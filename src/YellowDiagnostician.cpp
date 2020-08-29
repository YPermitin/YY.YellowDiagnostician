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

#include <chrono>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>

#include "YellowDiagnostician.h"

std::string YellowDiagnostician::extensionName() {
    return "YellowDiagnostician";
}

YellowDiagnostician::YellowDiagnostician() {
    AddProperty(L"Version", L"Версия", true, false, [&]() {
        auto s = std::string(Version);
        return std::make_shared<variant_t>(std::move(s));
    });

    AddMethod(L"CurrentDate", L"ТекущаяДата", this, &YellowDiagnostician::currentDate);
    AddMethod(L"Sleep", L"Ожидать", this, &YellowDiagnostician::sleep, {{0, 5}});
    AddMethod(L"ProcessId", L"ИдентификаторПроцесса", this, &YellowDiagnostician::processId);
    AddMethod(L"ProcessName", L"ИмяПроцесса", this, &YellowDiagnostician::processName);
    AddMethod(L"ThreadId", L"ИдентификаторПотока", this, &YellowDiagnostician::threadId);
    AddMethod(L"HostName", L"ИмяКомпьютера", this, &YellowDiagnostician::hostName);
    AddMethod(L"UserName", L"ИмяПользователя", this, &YellowDiagnostician::userName);
    AddMethod(L"DomainName", L"ИмяДомена", this, &YellowDiagnostician::domainName);
}

void YellowDiagnostician::sleep(const variant_t &delay) {
    using namespace std;
    this_thread::sleep_for(chrono::seconds(get<int32_t>(delay)));
}
variant_t YellowDiagnostician::currentDate() {
    //using namespace std;
    //tm current{};
    //time_t t = time(nullptr);
    //localtime_s(&current, &t);
    //return current;
    return nullptr;
}
variant_t YellowDiagnostician::processId() {
    return yy::get_process_id();
}
variant_t YellowDiagnostician::processName() {
    return yy::get_process_name();
}
variant_t YellowDiagnostician::threadId() {
    return yy::get_thread_id();
}
variant_t YellowDiagnostician::hostName() {
    return yy::get_host();
}
variant_t YellowDiagnostician::userName() {
    return yy::get_user();
}
variant_t YellowDiagnostician::domainName() {
    return yy::get_domain_name();
}
