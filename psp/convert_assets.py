import os

def file_to_c_array(filename, array_name, out_f):
    if not os.path.exists(filename):
        print(f"!! Warning: {filename} not found, skipping.")
        out_f.write(f"// {filename} not found during generation\n")
        out_f.write(f"const unsigned char {array_name}[] = {{ 0 }};\n")
        out_f.write(f"const unsigned int {array_name}_size = 0;\n\n")
        return

    try:
        with open(filename, "rb") as f:
            data = f.read()
            
        out_f.write(f"const unsigned char {array_name}[] = {{\n")
        for i, byte in enumerate(data):
            if i % 12 == 0:
                out_f.write("  ")
            out_f.write(f"0x{byte:02x}, ")
            if (i + 1) % 12 == 0:
                out_f.write("\n")
        if (i + 1) % 12 != 0:
            out_f.write("\n")
        out_f.write("};\n")
        out_f.write(f"const unsigned int {array_name}_size = {len(data)};\n\n")
        print(f"Successfully converted {filename} to C array.")
    except Exception as e:
        print(f"!! Error converting {filename}: {e}")
        out_f.write(f"// Error converting {filename}: {e}\n")

if __name__ == "__main__":
    # Base directory is the parent of where this script is located (project root)
    script_dir = os.path.dirname(__file__)
    project_root = os.path.dirname(script_dir)
    assets_dir = os.path.join(project_root, "assets")
    output_path = os.path.join(script_dir, "support_res.c")
    
    with open(output_path, "w", encoding="utf-8") as out_f:
        file_to_c_array(os.path.join(assets_dir, "qr_coffee.bmp"), "support_qr_coffee", out_f)
        file_to_c_array(os.path.join(assets_dir, "qr_wallet.bmp"), "support_qr_wallet", out_f)
