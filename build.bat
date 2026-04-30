@echo off
rem Build ForgeAV sur Windows
if not exist core\nul (echo Dossier core introuvable & exit /b 1)
if not exist security\nul (echo Dossier security introuvable & exit /b 1)

gcc main.c core\*.c security\*.c -o forgeav.exe -lcrypt32
if %errorlevel% neq 0 (
    echo Erreur de compilation.
    exit /b %errorlevel%
)
echo Compilation réussie : forgeav.exe
