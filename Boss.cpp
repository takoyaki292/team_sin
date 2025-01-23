#include "Boss.h"
#include <random>
#include "FixedNum.h"
void Boss::Initialize(Vector2 pos, Vector2 size, bool isTrue, int attck, int hp, Vector2 hpPos, int randomAttck[FixedNum::haveCard], bool isAlive)
{
	pos_ = pos;
	size_ = size;
	isAlive_ = isAlive;
	isTrue_ = isTrue;
	attck_ = attck;
	hp_ = hp;
	hpPos_ = hpPos;
	for (int i = 0; i < FixedNum::haveCard; i++)
	{
		randomAttck_[i] = randomAttck[i];
	}
	//card_ = card;
}

void Boss::Update()
{

}


void Boss::Draw(int bossTexture)
{
	if (isAlive_)
	{
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, bossTexture, 1, 1, 0.0f, WHITE);

		Novice::DrawBox((int)hpPos_.x, (int)hpPos_.y, hp_ * 60, 30, 0.0f, RED, kFillModeSolid);

		for (int i = 0; i < FixedNum::cardNum; i++)
		{
			if (randomAttck_[i] != 0)
			{
				//mNovice::DrawSprite(200,100+i*50, cardT[randomAttck_[i]], 1, 1, 0.0f, WHITE);
			}
		}

		Novice::ScreenPrintf(1000, 100, "attck:%d", attck_);
	}
}

void Boss::AttckRandom()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(randomAttck_, randomAttck_ +FixedNum::haveCard, g);
	attck_ = randomAttck_[0];
}