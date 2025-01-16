#pragma once
#include "FixedNum.h"

class MapScene
{
public:
	void Initialize(const int map[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX]);
	void Update();
	void Draw();

private:
	int map_[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX];
};