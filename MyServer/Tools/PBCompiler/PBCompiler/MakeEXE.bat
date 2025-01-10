pushd %~dp0
pyinstaller --onefile PBCompiler.py
MOVE .\dist\PBCompiler.exe .\PBCompiler.exe
@RD /S /Q .\dist
@RD /S /Q .\build
DEL /S /F /Q .\PBCompiler.spec