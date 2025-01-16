﻿#include "MapScene.h"
#include <Novice.h>
MapScene::~MapScene()
{
	delete player_;
}
void MapScene::Initialize(const int map[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX])
{
	for (int y = 0; y < FixedNum::mapChipSizeY; y++)
	{
		for (int x = 0; x < FixedNum::mapChipSizeX; x++)
		{
			map_[y][x] = map[y][x];
		}
	}
	player_->MapInitialize();
}

void MapScene::Update()
{
	player_->MapUpdate();
}

void MapScene::Draw()
{
	for (int y = 0; y < FixedNum::mapChipSizeY; y++)
	{
		for (int x = 0; x < FixedNum::mapChipSizeX; x++)
		{
			if (map_[y][x] == 10)
			{

			}
			if (map_[y][x] == 11)
			{
				Novice::DrawBox(x * FixedNum::chipSize, y * FixedNum::chipSize, FixedNum::chipSize, FixedNum::chipSize,
					0.0f, WHITE, kFillModeSolid);
			}
			if (map_[y][x] == 12)
			{
				Novice::DrawBox(x * FixedNum::chipSize, y * FixedNum::chipSize, FixedNum::chipSize, FixedNum::chipSize,
					0.0f, BLACK, kFillModeSolid);
			}
		}
	}

	player_->MapDraw();
}


