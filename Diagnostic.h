#include <thread>
#include <string>

#if defined( __linux__ ) || defined(__APPLE__)
#include <unistd.h>
#include <pwd.h>
#include <limits.h>
#endif

#ifdef WIN32
#include "windows.h"
#include <Lmcons.h>
#endif

#define INFO_BUFFER_SIZE 32767

#ifdef WIN32
#pragma setlocale("ru-RU" )
#endif

namespace yy
{
	std::string GetHost();
	std::string GetUser();
	int GetProcessId();
	int GetThreadId();
}