#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace dso
{

namespace IOWrap
{

class InputDepthWrapper
{
	const int imgWidth, imgHeight;
	int imgIdx;
	

	std::ifstream depthFile;
	const std::string depthFolderPath, depthBaseName, depthExtension;
	
	std::vector<float> imgDepths;

public:
	InputDepthWrapper(int imgWidth, int imgHeight, std::string & depthFolderPath);

	bool loadDepthFile(int imgIdx);	

	inline float getDepth(int x, int y){ return imgDepths[y * imgWidth + x]; }
	inline std::vector<float> & getDepths(){ return imgDepths; };
};

}
}
