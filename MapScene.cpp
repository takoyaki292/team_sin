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
void MapScene::Initialize(const int map[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX],int backT)
{
	
	for (int y = 0; y < FixedNum::mapChipSizeY; y++)
	{
		for (int x = 0; x < FixedNum::mapChipSizeX; x++)
		{
			map_[y][x] = map[y][x];
		}
	}
	player_->MapInitialize();
	isBattleF = false;

	backT_ = backT;
}

void MapScene::Update()
{
	MapCollisiion();

	player_->MapUpdate();
}

void MapScene::Draw()
{
	Novice::DrawSprite(0, 0, backT_, 1, 1, 0.0f, WHITE);
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
			//21がカード
			if (map_[y][x] == 21)
			{
				Novice::DrawSprite(x * FixedNum::chipSize, y * FixedNum::chipSize, texture_->mapCard, 1, 1, 0.0f, WHITE);
			}
			//31がボス
			if (map_[y][x] == 31)
			{
				Novice::DrawSprite(x * FixedNum::chipSize, y * FixedNum::chipSize, texture_->mapBoss, 1, 1, 0.0f, WHITE);
			}
		}
	}
	player_->MapDraw(texture_);
}

void MapScene::MapCollisiion()
{
	for (int y = 0; y < FixedNum::mapChipSizeY; y++)
	{
		for (int x = 0; x < FixedNum::mapChipSizeX; x++)
		{
			///カードを踏んだら
			//if (map_[y][x] == 21&&player_.mapPos)
			//{
			//
			//}
			//ボスエリアに踏んだら
			//if (map_[y][x] == 31&&player_.mapPos)
			//{
			//	//isBattleF = true;
			//}
		}
	}
}


