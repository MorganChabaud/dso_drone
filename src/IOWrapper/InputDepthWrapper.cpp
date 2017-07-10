#include "InputDepthWrapper.h"

#include <iostream>

namespace dso
{

namespace IOWrap
{

InputDepthWrapper::InputDepthWrapper(int imgWidth, int imgHeight, std::string & depthFolderPath): imgWidth(imgWidth), imgHeight(imgHeight), depthFolderPath(depthFolderPath), depthBaseName("img"), depthExtension(".depth")
{
	imgIdx = -1;
	imgDepths.reserve(imgWidth * imgHeight);	
}
	

bool InputDepthWrapper::loadDepthFile(int imgIdx)
{
	const std::string depthFileName(depthFolderPath + depthBaseName + std::to_string(imgIdx) + depthExtension);

	depthFile.open(depthFileName);

	if(!depthFile.is_open())
	{
		std::cout << "Error: Unable to open depth file " << depthFileName << std::endl;
		return false;
	}

	for (int i = 0; i < (imgWidth * imgHeight); ++i)
		depthFile >> imgDepths[i];

	depthFile.close();
	return true;
}

}
}
