@echo off
setlocal

echo ===================================================
echo   Snes9xTYL Support Assets Updater
echo ===================================================
echo.

:: Check if FFmpeg is installed and available in PATH
ffmpeg -version >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] FFmpeg not found! Please install FFmpeg to convert assets.
    echo Make sure it is added to your Windows PATH.
    pause
    exit /b 1
)

:: Check if Python is installed and available in PATH
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] Python not found! Please install Python.
    pause
    exit /b 1
)

echo [1/2] Resizing and converting PNG files to BMP (128x128, 24-bit)...

:: Process Buy Me a Coffee QR code
if exist assets\qr_coffee.png (
    ffmpeg -y -i assets\qr_coffee.png -vf scale=128:128 -pix_fmt bgr24 assets\qr_coffee.bmp
    echo [+] assets\qr_coffee.png processed successfully.
) else (
    echo [WARNING] assets\qr_coffee.png not found. Skipping.
)

:: Process Crypto Wallet QR code
if exist assets\qr_wallet.png (
    ffmpeg -y -i assets\qr_wallet.png -vf scale=128:128 -pix_fmt bgr24 assets\qr_wallet.bmp
    echo [+] assets\qr_wallet.png processed successfully.
) else (
    echo [WARNING] assets\qr_wallet.png not found. Skipping.
)

echo.
echo [2/2] Generating psp\support_res.c from BMP assets...

:: Run Python conversion script
python psp\convert_assets.py

echo.
echo ===================================================
echo   PROCESS COMPLETED SUCCESSFULLY!
echo   You can now run 'make' to build the new EBOOT.
echo ===================================================
echo.

pause
