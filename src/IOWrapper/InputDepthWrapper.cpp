#include "InputDepthWrapper.h"

#include <iostream>
#include <string>

namespace dso
{

namespace IOWrap
{

InputDepthWrapper::InputDepthWrapper(int imgWidth, int imgHeight, std::string & depthFolderPath): imgWidth(imgWidth), imgHeight(imgHeight), depthFolderPath(depthFolderPath), depthBaseName("img"), depthExtension(".depth"), imgDepths(imgWidth * imgHeight)
{
	imgIdx = -1;
}
	

bool InputDepthWrapper::loadDepthFile(int imgIdx)
{
	const std::string depthFileName(depthFolderPath + depthBaseName + std::to_string(imgIdx) + depthExtension);

	// depthFile.open(depthFileName);
	depthFile.open(depthFileName, std::ifstream::in | std::ifstream::binary);

	if(!depthFile.is_open())
	{
		std::cout << "Error: Unable to open depth file " << depthFileName << std::endl;
		return false;
	}
	else
		std::cout << "Debug: " << depthFileName << " is opened." << std::endl;

	for (int i = 0; i < (imgWidth * imgHeight); ++i)
	{
		//std::string tmpString;
		//depthFile >> tmpString;
		//imgDepths[i] = std::stof(tmpString);
		depthFile.read((char *) &imgDepths[i], sizeof(float));		
		
		if(depthFile.eof())
		{
			std::cout << "Error: Premature end of depth file" << std::endl;
			return false;
		}
		else if(depthFile.fail())
		{
			std::cout << "Error: Reading depth file lead to failbit or badbit" << std::endl;
			return false;
		}
	}
	
	// Test end of file
	float tmp;
	depthFile >> tmp;
	if(!depthFile.eof())
		std::cout << "Warning: The depth file has not been read entirely" << std::endl;

	depthFile.close();
	return true;
}

}
}
