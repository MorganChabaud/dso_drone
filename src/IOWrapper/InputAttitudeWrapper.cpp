#include "InputAttitudeWrapper.h"

#include <iostream>
#include <string>
#include "Eigen/Core"

namespace dso
{

namespace IOWrap
{

InputAttitudeWrapper::InputAttitudeWrapper(std::string & folderPath): folderPath(folderPath), baseName("img"), extension(".depth")
{

}
	

bool InputAttitudeWrapper::loadFile(int imgIdx)
{
	const std::string fileName(folderPath + baseName + std::to_string(imgIdx) + extension);

	file.open(fileName, std::ifstream::in | std::ifstream::binary);

	if(!file.is_open())
	{
		std::cout << "Error: Unable to open file " << fileName << std::endl;
		return false;
	}
	else
		std::cout << "Debug: " << fileName << " is opened." << std::endl;

	// qw, qx, qy, qz
	for (int i = 0; i < 4; ++i)
	{
		file.read((char *) &attitude[i], sizeof(float));		
		
		if(file.eof())
		{
			std::cout << "Error: Premature end of file" << std::endl;
			return false;
		}
		else if(file.fail())
		{
			std::cout << "Error: Reading file lead to failbit or badbit" << std::endl;
			return false;
		}
	}
	
	// Test end of file
	float tmp;
	file >> tmp;
	if(!file.eof())
		std::cout << "Warning: The file has not been read entirely" << std::endl;

	file.close();
	return true;
}

}
}
