#pragma once
//#include "Vector2.h"
#include <Novice.cpp>
class Judge
{
public:
	//Judge;
	//~Judge;

	void Initialize(Vector2 playerHpPos,Vector2 bossHpPos);
	void Update();
	void Draw(int& playerHp, int& bossHp);
	
	void IsTrue();

	void BigNum(int& playerAttck, int& bossAttck, int& playerHp, int& bossHp, bool& playerIsTrue, bool& bossIsTrue);

private:
	
	Vector2 playerHpPos_;
	Vector2 bossHpPos_;
};