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

#ifndef YELLOWDIAGNOSTICIAN_H
#define YELLOWDIAGNOSTICIAN_H

#include "Component.h"
#include "DiagnosticImpl.h"

class YellowDiagnostician final : public Component {
public:
    const char *Version = u8"0.0.0.2";
    YellowDiagnostician();
private:
    std::string extensionName() override;

    std::shared_ptr<variant_t> sample_property;

    variant_t currentDate();
    void sleep(const variant_t &delay);
    variant_t processId();
    variant_t processName();
    variant_t threadId();
    variant_t hostName();
    variant_t userName();
    variant_t domainName();
};

#endif //YELLOWDIAGNOSTICIAN_H
