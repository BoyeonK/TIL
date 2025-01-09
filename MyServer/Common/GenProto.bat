protoc.exe -I=./ --cpp_out=./ ./PB.proto
IF ERRORLEVEL 1 PAUSE