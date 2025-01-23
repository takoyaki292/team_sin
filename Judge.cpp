#include "Judge.h"

void Judge::Initialize(Vector2 playerHpPos, Vector2 bossHpPos)
{
	playerHpPos_ = playerHpPos;
	bossHpPos_ = bossHpPos;
}

void Judge::Update()
{
}

void Judge::Draw(int& playerHp, int& bossHp)
{
	Novice::DrawBox((int)playerHpPos_.x, (int)playerHpPos_.y, (int)playerHp * 60, 30, 0.0f,RED, kFillModeSolid);
	Novice::DrawBox((int)bossHpPos_.x, (int)bossHpPos_.y, (int)bossHp* 60, 30, 0.0f,RED, kFillModeSolid);

}

void Judge::IsTrue()
{
}

void Judge::BigNum(int& playerAttck, int& bossAttck, int& playerHp, int& bossHp,bool& playerIsTrue,bool& bossIsTrue)
{
	if (playerAttck < bossAttck)
	{
		playerHp -= bossAttck;
		playerIsTrue = false;
		bossIsTrue = false;
	}
	if (bossAttck < playerAttck)
	{
		bossHp -= playerAttck;
		playerIsTrue = false;
		bossIsTrue = false;
	}
}
