pushd %~dp0
protoc.exe -I=./ --cpp_out=./ ./PB.proto

PBCompiler.exe --path=./PB.proto --output=ServerPacketHandler --recv=S_ --send=C_
IF ERRORLEVEL 1 PAUSE

XCOPY /Y PB.pb.cc "../MyServer"
XCOPY /Y PB.pb.h "../MyServer"
XCOPY /Y ServerPacketHandler.h "../MyServer"