#pragma once

#define WIN32_LEAN_AND_MEAN

#ifdef _DEBUG
#pragma comment(lib, "MyLibraries\\Debug\\MyLibraries.lib")
#else
#pragma comment(lib, "MyLibraries\\Release\\MyLibraries.lib")
#endif