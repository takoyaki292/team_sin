#include "Skill.h"
#include <Novice.h>
#include "Player.h"
#include <vector>
#include <random>
Skill::Skill()
{
}

Skill::~Skill()
{
}

void Skill::Initialize(const Vector2& listBottomPos, const Vector2& listBottomSize, bool isListBottom, Vector2 skillBottomPos[FixedNum::skillNum], Vector2 skillBottomSize[FixedNum::skillNum], bool isSkillBottomFlag[FixedNum::skillNum],Vector2 skillEffect[FixedNum::skillNum], bool isHaveSkill[FixedNum::skillNum])
{
	listBottomPos_ = listBottomPos;
	listBottomSize_ = listBottomSize;
	isListBottom_ = isListBottom;
	
	for (int i = 0; i < FixedNum::skillNum; i++)
	{
		skillBottomPos_[i] = skillBottomPos[i];
		skillBottomSize_[i] = skillBottomSize[i];
		isSkillBottomFlag_[i] = isSkillBottomFlag[i];
		skillEffect_[i] = skillEffect[i];
		isSkillHave_[i] = isHaveSkill[i];
	}
}

void Skill::Update(Player& player)
{
	if (player.isSkillBottom()) {
		isListBottom_ = true;
	}
	else {
		isListBottom_ = false;
	}
}



void Skill::Draw(Texture* texture)
{
	if (!isListBottom_ )
	{
		//Novice::DrawEllipse((int)1100.f, (int)200.f, (int)listBottomSize_.x, (int)listBottomSize_.y, 0.0f, GREEN, kFillModeSolid);
		Novice::DrawSprite((int)1100.f, (int)200.f, texture->skill, 1, 1, 0.0f, WHITE);
	}
	else if (isListBottom_)
	{
		
		//Novice::DrawSprite(0, 0, backT, 1, 1, 0.0f, WHITE);
		
		
		//Novice::DrawSprite((int)skillBottomPos_[2].x, (int)skillBottomPos_[2].y, texture->skillReversal, 1, 1, 0.0f, WHITE);
		for (int i = 0; i < FixedNum::skillNum; i++)
		{
			//Novice::DrawEllipse((int)skillBottomPos_[i].x, (int)skillBottomPos_[i].y, (int)skillBottomSize_[i].x, (int)skillBottomSize_[i].y
			//	, 0.0f, BLACK, kFillModeSolid);
			//
			//Novice::DrawSprite((int)skillBottomPos_[i].x, (int)skillBottomPos_[i].y, texture->skills[i], 1, 1, 0.0f, WHITE);
			if (isSkillHave_[i])
			{
				Novice::DrawSprite((int)skillBottomPos_[0].x - (int)skillBottomSize_[0].x, (int)skillBottomPos_[0].y - (int)skillBottomSize_[0].y, texture->skillPlusTwo, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite((int)skillBottomPos_[2].x - (int)skillBottomSize_[2].x, (int)skillBottomPos_[2].y - (int)skillBottomSize_[2].y, texture->skillReversal, 1, 1, 0.0f, WHITE);
			}
			else
			{
				Novice::DrawEllipse((int)skillBottomPos_[i].x, (int)skillBottomPos_[i].y, (int)skillBottomSize_->x, (int)skillBottomSize_->y, 0.0f, BLACK, kFillModeSolid);
			}
			
			Novice::DrawBox((int)skillEffect_[i].x, (int)skillEffect_[i].y, (int)skillBottomSize_[i].x, (int)skillBottomSize_[i].y, 0.0f, BLACK, kFillModeSolid);
		}
	}
}


AABB Skill::GetSkillAABB(int skillIndex)
{
	AABB aabb{};

	if (skillIndex >= 0 && skillIndex < FixedNum::skillNum)
	{
		Vector2 worldPos = skillBottomPos_[skillIndex];

		aabb.min = {
			worldPos.x - skillBottomSize_[skillIndex].x / 2.0f,
			worldPos.y - skillBottomSize_[skillIndex].y / 2.0f
		};

		aabb.max = {
			worldPos.x + skillBottomSize_[skillIndex].x / 2.0f,
			worldPos.y + skillBottomSize_[skillIndex].y / 2.0f
		};
	}
	return aabb;
}


void Skill::BattleTwice(Card& cardInstance)
{
	// カードが所持されている場合に、カードの攻撃力に+3の効果を与える
	for (int i = 0; i < FixedNum::cardNum; i++)
	{
		if (cardInstance.haveCardF_[i]) {
			// それぞれのカードの攻撃力に +3 を加算
			cardInstance.num[i] += 3;
		}
	}
}

void Skill::BattleRandomNum(Card& cardInstance)
{
	unsigned int currentTime = static_cast<unsigned int>(time(nullptr));
	srand(currentTime);

	// シャッフル用の配列
	std::vector<int> availableNums = { 1, 2, 3, 4, 5, 6, 7 };
	std::random_device rd;
	std::mt19937 g(rd());

	// 配列のシャッフル
	std::shuffle(availableNums.begin(), availableNums.end(), g);

	int numIndex = 0; // シャッフルされた数値のインデックス

	// 有効なカードのインデックスにランダムな番号を割り当て
	for (int i = 0; i < FixedNum::cardNum; i++)
	{
		if (cardInstance.haveCardF_[i]) // 有効なカードであるか確認
		{
			if (numIndex < availableNums.size()) // 範囲外アクセスを防止
			{
				
				cardInstance.num[i] = availableNums[numIndex];
				numIndex++;
			}
			else
			{
				// 追加の安全対策: numIndexがシャッフル配列のサイズを超えた場合
				break;
			}
		}
	}
}
