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
        // The different vehicle types in the simulation
        static std::vector<VehicleType> VehicleTypes;
        // the vehicles in the simulation
        static std::vector<Vehicle> Vehicles;
        // The path to the network file
        static std::string NetworkPath;
        // The path to the demand to place on the network
        static std::string DemandPath;
        // The amount of time that the simulation increases by per step
        static double TimeStep;
        // The amount of time that has occurred in the simulation (seconds)
        static double CurrentTime;
        // The last time unit for the simulation
        static double EndTime;
        // The function to load the configuration
        static bool Load(std::string &configurationFile);
    };
}