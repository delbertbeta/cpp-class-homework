#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>

#include "HardwareData.h"

using namespace std;

class FileManager
{
public:
	FileManager();
	static void initialize(fstream&);
	static HardwareData read(fstream&, int);
	static void write(fstream&, const HardwareData&, int);
};

