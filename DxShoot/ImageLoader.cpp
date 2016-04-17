#include "ImageLoader.h"
#include <DxLib.h>

namespace dxshoot{

ImageLoader::ImageLoader()
{
	items = std::make_unique<ImageDict>();
}


ImageLoader::~ImageLoader()
{
	for (auto i : *items) {
		DeleteGraph(i.second);
	}
	items.reset();
}


int ImageLoader::load(const char* fileName)
{
	auto s = std::string(BasePath);
	s.append(fileName);
	auto item = items->find(s);
	if (item == items->end()) {
		int i = LoadGraph(s.c_str());
		items->emplace(s, i);
		return i;
	}
	return item->second;
}

}