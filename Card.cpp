#include "Card.h"
#include <Novice.h>
void Card::Initialize(Vector2 cardPos[FixedNum::cardNum], Vector2 cardSize, bool haveCardF[FixedNum::cardNum])
{
	for (int i = 0; i < FixedNum::cardNum; i++)
	{
		haveCardF_[i] = haveCardF[i];
		cardSize_ = cardSize;
		cardPos_[i] = cardPos[i];

		if (haveCardF_[i])
		{
			num[i] = i + 1;
		}
	}
}

void Card::BattleUpdate()
{
}

void Card::BattleDraw(Texture* texture)
{
	for (int i = 0; i < FixedNum::cardNum; i++)
	{
		if (haveCardF_[i])
		{
			Novice::DrawBox((int)cardPos_[i].x, (int)cardPos_[i].y, 50, 100, 0.0f, BLACK, kFillModeSolid);

			Novice::DrawSprite((int)cardPos_[i].x, (int)cardPos_[i].y , texture->cards[i], 1, 1, 0.0f, WHITE);
		}
		Novice::ScreenPrintf(0, i * 50, "%d:num[%d]",i, num[i]);
		
	}	
}

AABB Card::GetCardAABB(int cardIndex)
{
	AABB aabb{};

	if (cardIndex >= 0 && cardIndex < FixedNum::cardNum)
	{
		Vector2 worldPos = cardPos_[cardIndex];

		aabb.min = { worldPos.x - cardSize_.x / 2.0f, worldPos.y - cardSize_.y / 2.0f };

		aabb.max = {
			worldPos.x + cardSize_.x / 2.0f,
			worldPos.y + cardSize_.y / 2.0f,
		};
	}
	return aabb;
}


int Card::GetOwnedCardCount() const {
	int count = 0;
	for (int i = 0; i < FixedNum::cardNum; i++) {
		if (haveCardF_[i]) {
			count++;
		}
	}
	return count;
}
