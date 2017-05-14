#include "FileManager.h"

FileManager::FileManager()
{
}

void FileManager::initialize(fstream &os)
{
	HardwareData blankData;

	for (int i = 0; i < 100; i++)
	{
		os.write(reinterpret_cast<const char*>(&blankData), sizeof(HardwareData));
	}
}

HardwareData FileManager::read(fstream& fs, int id)
{
	fs.seekg((id - 1) * sizeof(HardwareData));
	HardwareData hardwareData;
	fs.read(reinterpret_cast<char *>(&hardwareData), sizeof(HardwareData));
	return hardwareData;
}

void FileManager::write(fstream& fs, const HardwareData & data, int id)
{
	fs.seekp((id - 1) * sizeof(HardwareData));
	fs.write(reinterpret_cast<const char*>(&data), sizeof(HardwareData));
}

