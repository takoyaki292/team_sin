#pragma once
#include "Vector2.h"
#include "FixedNum.h"
#include "AABB.h"
#include "Texture.h"
class Card
{
public:
	//Card();
	//~Card();
	void Initialize(Vector2 cardPos[FixedNum::cardNum], Vector2 cardSize,bool haveCardF[FixedNum::cardNum]);
	void BattleUpdate();
	void BattleDraw(Texture* texture);

	AABB GetCardAABB(int cardIndex);
	
	/// <summary>
	/// 自身が持っているカードのフラグ
	/// </summary>
	bool haveCardF_[FixedNum::cardNum] = {};
	int num[FixedNum::cardNum] = {};

	int GetOwnedCardCount() const;

private:
	Vector2 cardPos_[FixedNum::cardNum] = {};
	Vector2 cardSize_ = {};
};