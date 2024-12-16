#pragma once
#include "Vector2.h"
#include "FixedNum.h"
#include "AABB.h"
class Card
{
public:
	//Card();
	//~Card();
	void Initialize(Vector2 cardPos[FixedNum::cardNum], Vector2 cardSize,bool haveCardF[FixedNum::cardNum]);
	void BattleUpdate();
	void BattleDraw();

	AABB GetCardAABB(int cardIndex);
	/// <summary>
	/// カードを押されていた場合はfalseにする
	/// </summary>
	/// <param name="cardIndex"></param>
	//void DisableCard(int cardIndex);
	/// <summary>
	/// 自身が持っているカードのフラグ
	/// </summary>
	bool haveCardF_[FixedNum::cardNum];
	int num[FixedNum::cardNum] = {};
private:
	Vector2 cardPos_[FixedNum::cardNum];
	Vector2 cardSize_;

	

};