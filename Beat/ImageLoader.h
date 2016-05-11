#pragma once
#include <unordered_map>
#include <string>
#include <memory>

namespace dxshoot {

class ImageLoader
{
public:
	ImageLoader();
	~ImageLoader();
	int load(const char* fileName);

private:
	using ImageDict = std::unordered_map<std::string, int>;
	constexpr static char* BasePath = "Contents\\Sprites\\";

	std::unique_ptr<ImageDict> items;
};


}