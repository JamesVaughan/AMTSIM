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
#include <direct.h>
#include <iostream>
using namespace std;
using namespace UTTRI;

int __cdecl main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "USAGE: CONFIGURATION_FILE" << endl;
        return 0;
    }
    // Load Configurations
    try
    {
        if (!Configuration::Load(string(argv[1])))
        {
            cout << "Unable to read configuration file " << argv[1] << endl;
            return false;
        }
        cout << "Time Step: " << Configuration::TimeStep << endl;
        // Load Network
        
        // Load Demand
    }
    catch (RuntimeError& error)
    {
        cout << "FATAL ERROR:" << error.Message << endl;
    }
    return 0;
}


