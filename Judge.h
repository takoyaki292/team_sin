#pragma once
//#include "Vector2.h"
class Judeg
{
public:
	Judeg();
	~Judeg();
	void Initialize(Vector2 playerHpPos,Vector2 bossHpPos);
	void Update();
	void Draw(int& playerHp,int& bossHp);

private:
	Vector2 playerHpPos_;
	Vector2 bossHpPos_;
};