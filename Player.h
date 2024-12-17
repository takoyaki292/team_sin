#pragma once
#include "Vector2.h"
#include "AABB.h"
#include "Card.h"
class Player
{
public:
    void Initialize(const Vector2& pos, const Vector2& size, int hp,Vector2& hpPos, bool isAlive, bool isTurn, const Vector2& movePos, Vector2 moveSpeed,bool cardIsCollision);
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

    /// <summary>
    /// AABB型の当たり判定
    /// </summary>
    /// <returns></returns>
    AABB GetCardAABB();

    /// <summary>
    /// スペースキーを押した場合、カードを消える関数
    /// </summary>
    /// <returns></returns>
    bool cardConfirmed();
    
    
    /// <summary>
    /// バトル時のカードとの当たり判定
    /// </summary>
    bool cardIsCollision_= false;

    // プレイヤーが衝突しているカードのインデックスを追加
    int cardIndex_ = -1;

    //攻撃力
    int attck_;
private:
    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };


    Vector2 pos_;
    Vector2 size_;
    Vector2 hpPos_;
    int hp_;
    bool isAlive_ = false;
    bool isTurn_ = false;
    Vector2 movePos_ = pos_;
    Vector2 moveSpeed_;

};