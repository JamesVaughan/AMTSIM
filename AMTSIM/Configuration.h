#pragma once
/*
Copyright 2017 University of Toronto

This file is part of AMTSIM.

AMTSIM is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AMTSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AMTSIM.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <vector>
#include <string>
#include "VehicleType.h"
namespace UTTRI
{
    class Configuration
    {
    public:
        static std::vector<VehicleType> VehicleTypes;
        static std::string NetworkPath;
        static std::string DemandPath;
        static double TimeStep;
        static bool Load(std::string &configurationFile);
    };
}