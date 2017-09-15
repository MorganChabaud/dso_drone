#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace dso
{

namespace IOWrap
{

class InputAttitudeWrapper
{
	Eigen::Vector4f attitude;
	

	std::ifstream depthFile;
	const std::string folderPath, baseName, extension;
	
public:
	InputAttitudeWrapper(std::string & folderPath);

	bool loadFile(int imgIdx);	

	inline Eigen::Vector4f & getAttitude(){ return attitude; }
};

}
}
