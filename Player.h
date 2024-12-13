#pragma once
#include "Vector2.h"

class Player
{
public:
    void Initialize(const Vector2& pos, const Vector2& size, int hp, bool isAlive, bool isTurn, const Vector2& movePos,int moveSpeed);
    void BattleUpdate();
    void BattleDraw();
    /// <summary>
    /// 戦闘シーンで生きているかの関数
    /// </summary>
    void BattleIsAlive();

    /// <summary>
    /// カードを選ぶ時の関数
    /// </summary>
    void MoveCard();


private:
    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };


    Vector2 pos_;
    Vector2 size_;
    int hp_;
    bool isAlive_ = false;
    bool isTurn_ = false;
    Vector2 movePos_ = pos_;
    int moveSpeed_;


};