#pragma once
#include <random>
#include <memory>
namespace dxshoot {

class Level
{
public:
	Level();
	~Level();
	void update();
private:
	int count;
	std::unique_ptr<std::mt19937> mt;
	std::unique_ptr<std::uniform_int_distribution<> > dist;
};

}