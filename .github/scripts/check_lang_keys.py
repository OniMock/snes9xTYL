import re
import os
import sys

def extract_enum_keys(header_path):
    """Extracts message keys from psp_msg.h"""
    with open(header_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    # Strip comments
    content = re.sub(r'//.*', '', content)
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)

    # Find the enum block containing MSG_TOTAL_ENTRIES
    # We look for enum { ... MSG_TOTAL_ENTRIES ... }
    # Using a more robust regex to find the block
    matches = re.finditer(r'enum\s*\{([^}]+)\}', content, re.DOTALL)
    enum_content = ""
    for match in matches:
        if "MSG_TOTAL_ENTRIES" in match.group(1):
            enum_content = match.group(1)
            break

    if not enum_content:
        print(f"Error: Could not find the message enum in {header_path}")
        return set()

    # Match keys: words starting with ERR_, ASK_, INFO_, etc.
    # We only want identifiers before = or , or whitespace
    keys = re.findall(r'\b([A-Z][A-Z0-9_]+)\b', enum_content)

    exclude = {'MSG_TOTAL_ENTRIES', 'MSG_TOTAL_LANG'}
    return {k for k in keys if k not in exclude}

def extract_c_keys(c_path):
    """Extracts keys from localization .c files"""
    with open(c_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    # Matches [KEY] = "..." but ignores [MSG_XXX] = {
    # Let's look for keys that are mapped to strings
    all_keys = re.findall(r'\[\s*([A-Z][A-Z0-9_]+)\s*\]\s*=', content)

    # Also handle multi-line strings or macros if any
    # Actually, the simple regex should work for most [KEY] = "..."
    # Let's also catch keys mapped to macros like PROJECT_NAME if they exist
    # but the primary goal is strings.

    # If the above is too restrictive, we can just exclude the MSG_ identifiers
    return {
        k for k in all_keys
        if not k.startswith("MSG_")
    }

def main():
    base_dir = "."
    header_path = os.path.join(base_dir, "psp", "psp_msg.h")
    lang_dir = os.path.join(base_dir, "psp", "lang")
    en_path = os.path.join(lang_dir, "en.c")

    if not os.path.exists(header_path):
        print(f"Error: {header_path} not found.")
        sys.exit(1)

    if not os.path.exists(en_path):
        print(f"Error: {en_path} not found.")
        sys.exit(1)

    print("--- Validating psp_msg.h vs en.c ---")
    header_keys = extract_enum_keys(header_path)
    en_keys = extract_c_keys(en_path)

    failed = False

    missing_in_en = header_keys - en_keys
    if missing_in_en:
        print(f"FAILED: The following keys are in psp_msg.h but missing in en.c:")
        for k in sorted(missing_in_en):
            print(f"  - {k}")
        failed = True

    missing_in_header = en_keys - header_keys
    if missing_in_header:
        print(f"FAILED: The following keys are in en.c but missing in psp_msg.h:")
        for k in sorted(missing_in_header):
            print(f"  - {k}")
        failed = True

    if not failed:
        print("OK: psp_msg.h and en.c are in sync.")

    print("\n--- Validating other languages vs en.c ---")
    lang_files = [f for f in os.listdir(lang_dir) if f.endswith('.c') and f != 'en.c']

    for lang_file in lang_files:
        lang_path = os.path.join(lang_dir, lang_file)
        lang_keys = extract_c_keys(lang_path)

        missing_in_lang = en_keys - lang_keys
        if missing_in_lang:
            print(f"FAILED: {lang_file} is missing keys from en.c:")
            for k in sorted(missing_in_lang):
                print(f"  - {k}")
            failed = True

        extra_in_lang = lang_keys - en_keys
        if extra_in_lang:
            print(f"WARNING: {lang_file} has keys NOT present in en.c (should be cleaned up or added to en.c):")
            for k in sorted(extra_in_lang):
                print(f"  - {k}")
            # We don't fail for extra keys in other languages, just warning,
            # but usually it means en.c is out of date or the key was deleted from en.c but not others.
            # actually user asked "se todas as chaves do en, bate com as chaves do msg.h" and vice-versa
            # and "se todas as chaves de en.c está nos demais arquivo de linguas"
            # So extra keys in other languages might be okay but better to keep it clean.

    if failed:
        print("\nValidation FAILED. Please fix the missing keys before building.")
        sys.exit(1)
    else:
        print("OK: All language files are consistent.")
        sys.exit(0)

if __name__ == "__main__":
    main()
