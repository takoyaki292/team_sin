#include "Player.h"
#include <Novice.h>

void Player::Initialize(const Vector2& pos, const Vector2& size, int hp, bool isAlive, bool isTurn, const Vector2& movePos,int moveSpeed) {
    pos_ = pos;
    size_ = size;
    hp_ = hp;
    isAlive_ = isAlive;
    isTurn_ = isTurn;
    movePos_ = movePos;
    moveSpeed_ = moveSpeed;
}

void Player::BattleUpdate()
{
    BattleIsAlive();
    MoveCard();

}

void Player::BattleDraw()
{
    if (isAlive_) {
        Novice::DrawBox((int)pos_.x, (int)pos_.y, (int)size_.x, (int)size_.y, 0.0f, RED, kFillModeSolid);
        Novice::DrawBox((int)movePos_.x, (int)movePos_.y, 50, 100, 0.0f, GREEN, kFillModeWireFrame);
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
        movePos_.x -= moveSpeed_;
    }
    if (keys[DIK_D] && !preKeys[DIK_D])
    {
        movePos_.x += moveSpeed_;
    }
}
