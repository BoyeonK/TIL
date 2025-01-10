pushd %~dp0
protoc.exe -I=./ --cpp_out=./ ./PB.proto

PBCompiler.exe --path=./PB.proto --output=ClientPacketHandler --recv=C_ --send=S_
IF ERRORLEVEL 1 PAUSE

XCOPY /Y PB.pb.cc "../MyClient"
XCOPY /Y PB.pb.h "../MyClient"
XCOPY /Y ClientPacketHandler.h "../MyClient"