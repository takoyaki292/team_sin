#include "Judge.h"
#include <Novice.h>
void Judeg::Initialize(Vector2 playerHpPos, Vector2 bossHpPos)
{
	playerHpPos_ = playerHpPos;
	bossHpPos_ = bossHpPos;
}

void Judeg::Update()
{
}

void Judeg::Draw(int& playerHp, int& bossHp)
{
	Novice::DrawBox((int)playerHpPos_.x, (int)playerHpPos_.y, playerHp * 60, 30, 0.0f, RED, kFillModeSolid);
	Novice::DrawBox((int)bossHpPos_.x, (int)bossHpPos_.y, bossHp * 60, 30, 0.0f, RED, kFillModeSolid);
}
