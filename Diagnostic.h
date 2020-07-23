#include <thread>
#include <string>
#include <cstdio>

#if defined( __linux__ ) || defined(__APPLE__)

#include <unistd.h>
#include <pwd.h>
#include <limits.h>

#define GetCurrentDir getcwd

#endif

#ifdef WIN32

#include "windows.h"
#include <Lmcons.h>
#include <direct.h>

#define GetCurrentDir _getcwd

#endif

#define INFO_BUFFER_SIZE 32767

#ifdef WIN32

#pragma setlocale("ru-RU")

#endif

namespace yy
{
	std::string get_host();
	std::string get_user();
	int get_process_id();
	int get_thread_id();
	std::string get_process_name();
}