#pragma once
#include "Vector2.h"
#include "FixedNum.h"
#include "Player.h"
#include "Texture.h"
class Skill
{
public:
	Skill();
	~Skill();

	void Initialize(const Vector2& listBottomPos, const Vector2& listBottomSize, bool isListBottom
	,Vector2 skillBottomPos[FixedNum::skillNum],Vector2 skillBottomSize[FixedNum::skillNum],bool isSkillBottomFlag[FixedNum::skillNum],Vector2 skillEffect[FixedNum::skillNum],bool isHaveSkill[FixedNum::skillNum]);
	void Update(Player& player);
	void Draw(Texture* texture);

	AABB GetSkillAABB(int skillIndex);

	void BattleTwice(Card& cardInstance);

	void BattleRandomNum(Card& cardInstance);

	///スキルを一覧できるボタン
	bool isListBottom_ = false;
	///スキルボタン
	bool isSkillBottomFlag_[FixedNum::skillNum] = {};

private:

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//skillボタンを一覧できる変数
	Vector2 listBottomPos_;
	Vector2 listBottomSize_;

	//skillボタン
	Vector2 skillBottomPos_[FixedNum::skillNum] = {};
	Vector2 skillBottomSize_[FixedNum::skillNum] = {};

	Vector2 skillEffect_[FixedNum::skillNum] = {};

	bool isSkillHave_[FixedNum::skillNum] = {};
};