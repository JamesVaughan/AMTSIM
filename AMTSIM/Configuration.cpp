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
#include "stdafx.h"
#include "AMTSIM.h"
#include "Configuration.h"
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;
using namespace boost;
using namespace boost::property_tree;
namespace UTTRI
{
    double Configuration::TimeStep = 0.0;
    std::vector<VehicleType> Configuration::VehicleTypes;
    std::string Configuration::NetworkPath;

    void LoadVehicleTypes(basic_ptree<string, string> &vehicleRoot)
    {
        for_each(vehicleRoot.begin(), vehicleRoot.end(), [&](ptree::value_type &element)
        {
            assert(element.first.empty());
            // Load in vehicle type information here
        });
    }

    void LoadNetworkPath(basic_ptree<string, string> &networkPathRoot)
    {
        Configuration::NetworkPath = networkPathRoot.get_value<string>();
    }

    void LoadTimeStep(basic_ptree<string, string> &timeStepRoot)
    {
        Configuration::TimeStep = timeStepRoot.get_value<double>();
    }

    bool Configuration::Load(string &fileName)
    {
        bool success = true;
        ifstream file(fileName);
        stringstream buffer;
        if (!file)
        {
            return false;
        }
        try
        {
            buffer << file.rdbuf();
            file.close();
        }
        catch (...)
        {
            return false;
        }
        ptree pt;
        read_json(buffer, pt);
        LoadVehicleTypes(pt.get_child("VehicleTypes"));
        LoadNetworkPath(pt.get_child("NetworkPath"));
        LoadTimeStep(pt.get_child("TimeStep"));
        return true;
    }
}