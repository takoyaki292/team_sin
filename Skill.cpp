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

void Skill::Initialize(const Vector2& listBottomPos, const Vector2& listBottomSize, bool isListBottom, Vector2 skillBottomPos[FixedNum::skillNum], Vector2 skillBottomSize[FixedNum::skillNum], bool isSkillBottomFlag[FixedNum::skillNum])
{
	listBottomPos_ = listBottomPos;
	listBottomSize_ = listBottomSize;
	isListBottom_ = isListBottom;
	
	for (int i = 0; i < FixedNum::skillNum; i++)
	{
		skillBottomPos_[i] = skillBottomPos[i];
		skillBottomSize_[i] = skillBottomSize[i];
		isSkillBottomFlag_[i] = isSkillBottomFlag[i];
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



void Skill::Draw()
{
	if (!isListBottom_ )
	{
		Novice::DrawEllipse((int)1100.f, (int)200.f, (int)listBottomSize_.x, (int)listBottomSize_.y, 0.0f, GREEN, kFillModeSolid);
	}
	else if (isListBottom_)
	{
		for (int i = 0; i < FixedNum::skillNum; i++)
		{
			Novice::DrawEllipse((int)skillBottomPos_[i].x, (int)skillBottomPos_[i].y, (int)skillBottomSize_[i].x, (int)skillBottomSize_[i].y
				, 0.0f, BLACK, kFillModeSolid);
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
				// cardInstance.num はおそらく配列なので、インデックスに基づいて値を設定
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
