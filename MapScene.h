#pragma once
#include "FixedNum.h"
#include "Player.h"
class MapScene
{
public:
	~MapScene();
	void Initialize(const int map[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX]);
	void Update();
	void Draw();

private:
	int map_[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX];
	Player* player_ = nullptr;

};