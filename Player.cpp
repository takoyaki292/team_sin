#include "Player.h"
#include <Novice.h>
#include "FixedNum.h"

void Player::Initialize(const Vector2& pos, const Vector2& size, int hp, Vector2& hpPos, bool isAlive, bool isTurn, const Vector2& movePos,Vector2 moveSpeed, bool cardIsCollision) {
    pos_ = pos;
    size_ = size;
    hp_ = hp;
    hpPos_ = hpPos;
    isAlive_ = isAlive;
    isTurn_ = isTurn;
    movePos_ = movePos;
    moveSpeed_ = moveSpeed;
    cardIsCollision_ = cardIsCollision;
}

void Player::BattleUpdate()
{
    BattleIsAlive();
    MoveCard();

    //cardConfirmed();

}

void Player::BattleDraw()
{
    if (isAlive_) {
        Novice::DrawBox((int)pos_.x+(int)size_.x/2, (int)pos_.y+ (int)size_.y/2, (int)size_.x, (int)size_.y, 0.0f, RED, kFillModeSolid);
        Novice::DrawBox((int)movePos_.x, (int)movePos_.y, 50, 100, 0.0f, GREEN, kFillModeWireFrame);

        Novice::DrawBox((int)hpPos_.x, (int)hpPos_.y, hp_ * 60, 30, 0.0f, RED, kFillModeSolid);
    }
    
}

void Player::BattleIsAlive()
{
    if (isAlive_ && hp_ <= 0) {
        isAlive_ = false;
    }
}

void Player::MoveCard()
{
    // キー入力を受け取る
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);
    if (keys[DIK_A] && !preKeys[DIK_A])
    {
        movePos_.x -= moveSpeed_.x;
    }
    if (keys[DIK_D] && !preKeys[DIK_D])
    {
        movePos_.x += moveSpeed_.x;
    }
}

AABB Player::GetCardAABB()
{
    Vector2 worldPos = movePos_;
    AABB aabb{};

    aabb.min = { worldPos.x - size_.x / 2.0f, worldPos.y - size_.y / 2.0f};

    aabb.max = {
        worldPos.x + size_.x / 2.0f,
        worldPos.y + size_.y / 2.0f,
    };

    return aabb;
}

bool Player::cardConfirmed()
{
    if (cardIsCollision_)
    {
        for (int i = 0; i < FixedNum::cardNum; i++)
        {
            if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
            {
                return true;
            }
    
        }
    }
    else
    {
        return false;
    }

    return false;
}

//void Player::BattleAttck(int enemyHp, int attck)
//{
//
//}
