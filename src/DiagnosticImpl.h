/*
 *  YellowDiagnostician Native AddIn for 1C:Enterprise 8
 *  Copyright (C) 2020  YPermitin
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef YELLOWDIAGNOSTICIAN_DIAGNOSTICIMPL_H
#define YELLOWDIAGNOSTICIAN_DIAGNOSTICIMPL_H

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
#include <Lmwksta.h>
#include <StrSafe.h>
#include <stdlib.h>  // for _wtoi function
#include <assert.h>
#include <lm.h>

#pragma comment(lib, "netapi32.lib")

#define GetCurrentDir _getcwd

#endif

namespace yy
{
    std::string get_host();
    std::string get_user();
    int get_process_id();
    int get_thread_id();
    std::string get_process_name();
    std::string get_domain_name();
};

#endif //YELLOWDIAGNOSTICIAN_DIAGNOSTICIMPL_H
