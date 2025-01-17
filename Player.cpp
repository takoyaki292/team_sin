#include "Player.h"
#include <Novice.h>
#include "FixedNum.h"

void Player::MapInitialize()
{
}

void Player::MapUpdate()
{
}

void Player::MapDraw(Texture* texture)
{
    Novice::DrawSprite(50, 50,texture->player, 1, 1, 0.0f, WHITE);
}


void Player::Initialize(const Vector2& pos, const Vector2& size, int hp, Vector2& hpPos, bool isAlive, bool isTurn, const Vector2& movePos,Vector2 moveSpeed, bool cardIsCollision,Vector2 skillBottomPos, Vector2 skillBottomSpeed) {
    pos_ = pos;
    size_ = size;
    hp_ = hp;
    hpPos_ = hpPos;
    isAlive_ = isAlive;
    isTurn_ = isTurn;
    movePos_ = movePos;
    moveSpeed_ = moveSpeed;
    cardIsCollision_ = cardIsCollision;
    skillBottonPos_ = skillBottomPos;
    skillBottomSpeed_ = skillBottomSpeed;
}

void Player::BattleUpdate()
{
    // プレイヤーが生きているかどうかのチェック
    BattleIsAlive();

    // スキルモードかカードモードかで処理を分岐
    if (isSkillBottom()) {
        MoveSkill(); // スキルを移動させる
    }
    else {
        MoveCard(); // カードを移動させる
    }
}


void Player::BattleDraw(Texture* texture)
{
    if (isAlive_) {
        Novice::DrawBox((int)hpPos_.x, (int)hpPos_.y, hp_ * 60, 30, 0.0f, RED, kFillModeSolid);

        if (isSkillBottom()) {
            Novice::DrawEllipse((int)skillBottonPos_.x, (int)skillBottonPos_.y, 50, 50, 0.0f, BLACK, kFillModeWireFrame);
        }
        else {
            Novice::DrawBox((int)movePos_.x, (int)movePos_.y, 82, 112, 0.0f, BLACK, kFillModeWireFrame);
        }
        
        Novice::DrawSprite((int)pos_.x, (int)pos_.y, texture->player, 1, 1, 0.0f, WHITE);
    }
    
    //Novice::ScreenPrintf(300, 0, "attck:%d", attck_);
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

void Player::MoveSkill()
{
    // キー入力を受け取る
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);
    if (keys[DIK_A] && !preKeys[DIK_A])
    {
        skillBottonPos_.x -= skillBottomSpeed_.x;
    }
    if (keys[DIK_D] && !preKeys[DIK_D])
    {
        skillBottonPos_.x += skillBottomSpeed_.x;
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

AABB Player::GetSkillAABB()
{
    Vector2 worldPos = skillBottonPos_;
    AABB aabb{};

    aabb.min = { worldPos.x - size_.x / 2.0f, worldPos.y - size_.y / 2.0f };

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

bool Player::isSkillBottom()
{
    // Eキーが押された場合、スキルを発動状態にする
    if (keys[DIK_E] && !preKeys[DIK_E]) {
        isSkillActive_ = true; // スキル発動状態を保持
    }

    // Rキーが押された場合、スキルをキャンセル状態にする
    if (keys[DIK_R] && !preKeys[DIK_R]) {
        isSkillActive_ = false; // スキルを解除
    }

    // 現在のスキル発動状態を返す
    return isSkillActive_;
}


bool Player::skillConfirmed()
{
    if (skillIsCollision_)
    {
        for (int i = 0; i < FixedNum::skillNum; i++)
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