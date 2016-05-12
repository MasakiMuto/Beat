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
	int beatCount;
	bool direction;
	std::unique_ptr<std::mt19937> mt;
	std::unique_ptr<std::uniform_int_distribution<> > dist;

	int getNum();
	int getBeat();
};

}