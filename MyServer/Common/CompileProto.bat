pushd %~dp0
protoc.exe -I=./ --cpp_out=./ ./PB.proto

IF ERRORLEVEL 1 PAUSE

XCOPY /Y PB.pb.cc "../MyServer"
XCOPY /Y PB.pb.h "../MyServer"

XCOPY /Y PB.pb.cc "../MyClient"
XCOPY /Y PB.pb.h "../MyClient"