pushd %~dp0
protoc.exe -I=./ --cpp_out=./ ./PB.proto
protoc.exe -I=./ --cpp_out=./ ./Structs.proto
protoc.exe -I=./ --cpp_out=./ ./Enums.proto

PBCompiler.exe --path=./PB.proto --output=ClientPacketHandler --recv=C_ --send=S_
PBCompiler.exe --path=./PB.proto --output=ServerPacketHandler --recv=S_ --send=C_
IF ERRORLEVEL 1 PAUSE

XCOPY /Y PB.pb.cc "../MyServer"
XCOPY /Y PB.pb.h "../MyServer"
XCOPY /Y Structs.pb.cc "../MyServer"
XCOPY /Y Structs.pb.h "../MyServer"
XCOPY /Y Enums.pb.cc "../MyServer"
XCOPY /Y Enums.pb.h "../MyServer"
XCOPY /Y ServerPacketHandler.h "../MyServer"

XCOPY /Y PB.pb.cc "../MyClient"
XCOPY /Y PB.pb.h "../MyClient"
XCOPY /Y Structs.pb.cc "../MyClient"
XCOPY /Y Structs.pb.h "../MyClient"
XCOPY /Y Enums.pb.cc "../MyClient"
XCOPY /Y Enums.pb.h "../MyClient"
XCOPY /Y ClientPacketHandler.h "../MyClient"