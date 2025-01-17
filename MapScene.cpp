#include "MapScene.h"
#include <Novice.h>
#include "Texture.h"


MapScene::MapScene()
{
	player_ = new Player;
	texture_ = new Texture;
}

MapScene::~MapScene()
{
	delete player_;
	delete texture_;
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
				//Novice::DrawBox(x * FixedNum::chipSize, y * FixedNum::chipSize, FixedNum::chipSize, FixedNum::chipSize,
				//	0.0f, WHITE, kFillModeSolid);

				Novice::DrawSprite(x * FixedNum::chipSize, y * FixedNum::chipSize, texture_->map11, 1, 1, 0.0f, WHITE);
			}
			if (map_[y][x] == 12)
			{
				Novice::DrawBox(x * FixedNum::chipSize, y * FixedNum::chipSize, FixedNum::chipSize, FixedNum::chipSize,
					0.0f, BLACK, kFillModeSolid);
			}
		}
	}
	player_->MapDraw(texture_);
}


