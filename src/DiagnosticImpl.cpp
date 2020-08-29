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

#include "DiagnosticImpl.h"

#include <codecvt>
#include <locale>

#ifdef WIN32

#include <Lmcons.h>

#endif

namespace yy {
    std::string get_host() {
        char *temp = 0;
        std::string computerName;

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
        temp = getenv("COMPUTERNAME");
        if (temp != 0) {
            computerName = temp;
            temp = 0;
        }
#else
        temp = getenv("HOSTNAME");
            if (temp != 0) {
                computerName = temp;
                temp = 0;
            }
            else {
                temp = new char[512];
                if (gethostname(temp, 512) == 0) { // success = 0, failure = -1
                    computerName = temp;
                }
                delete[]temp;
                temp = 0;
            }
#endif

        return computerName;
    }

    std::string get_user() {
        std::string username;

#ifdef WIN32
        char buffer[UNLEN + 1];
        DWORD size;
        size = sizeof(buffer);
        if (GetUserNameA(buffer, &size)) {
            username = buffer;
        }
#endif

#if defined( __linux__ )
        char valueUsername[LOGIN_NAME_MAX];
            getlogin_r(valueUsername, LOGIN_NAME_MAX);
            username = valueUsername;
#endif

        return username;
    }

    int get_process_id() {
        int process_id = -1;

#ifdef WIN32
        DWORD procId;
        procId = GetCurrentProcessId();
        process_id = procId;
#endif

#if defined( __linux__ )
        process_id = ::getpid();
#endif

        return process_id;
    }

    int get_thread_id() {
        int thread_id = -1;

        thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());

        return thread_id;
    }

    std::string get_process_name() {
#ifdef WIN32
        wchar_t buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);

        using convert_type = std::codecvt_utf8<wchar_t>;
        std::wstring_convert<convert_type, wchar_t> converter;
        std::string converted_str = converter.to_bytes(buffer);

        return converted_str;
#endif

#if defined( __linux__ )
        char cmd[25];
        char exepath[PATH_MAX + 1] = {0};

        sprintf(cmd, "/proc/%d/exe", getpid());
        readlink(cmd, exepath, 1024);
        return std::string(exepath);
#endif

        return nullptr;
    }

    std::string get_domain_name() {
#ifdef WIN32
        LPCWSTR lpDcName = nullptr;

        NET_API_STATUS nStatus;
        nStatus = NetGetDCName(nullptr, nullptr, (LPBYTE *) &lpDcName);

        std::string result;
        if (nStatus == NERR_Success) {
            std::wstring wstr_nStatus = lpDcName;
            using convert_type = std::codecvt_utf8<wchar_t>;
            std::wstring_convert<convert_type, wchar_t> converter;
            result = converter.to_bytes(wstr_nStatus);
        } else {
            result = "";
        }

        return result;
#endif

        return nullptr;
    }
}
