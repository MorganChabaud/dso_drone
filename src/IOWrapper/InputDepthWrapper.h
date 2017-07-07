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
	
	std::vector<float> imgDepths;

	std::ifstream depthFile;
	const std::string depthFolderPath, depthBaseName, depthExtension;
	

public:
	InputDepthWrapper(int imgWidth, int imgHeight, std::string & depthFolderPath);

	void loadDepthFile(int imgIdx);	

	inline float getDepth(int x, int y){ return imgDepths[y * imgWidth + x]; }
	inline std::vector<float> & getDepths(){ return imgDepths; };
};

}
}
