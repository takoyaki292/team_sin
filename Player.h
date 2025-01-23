#pragma once
#include "Vector2.h"
#include "AABB.h"
#include "Card.h"
#include "Texture.h"
class Player
{
///マップシーンの関数や変数
public:
    /// <summary>
    /// マップシーンの初期化
    /// </summary>
    void MapInitialize();

    /// <summary>
    /// マップシーンの更新処理
    /// </summary>
    void MapUpdate();

    /// <summary>
    /// マップシーンの描画処理
    /// </summary>
    void MapDraw(Texture* texture);
private:



//戦闘シーンの関数や変数
public:
    void Initialize(const Vector2& pos, const Vector2& size, int hp,Vector2& hpPos, bool isAlive, bool isTurn, const Vector2& movePos, Vector2 moveSpeed,bool cardIsCollision,Vector2 skillBottomPos,Vector2 skillBottomSpeed);
    void BattleUpdate();
    void BattleDraw(Texture* texture);
    /// <summary>
    /// 戦闘シーンで生きているかの関数
    /// </summary>
    void BattleIsAlive();

    /// <summary>
    /// カードを選ぶ時の関数
    /// </summary>
    void MoveCard();

    

    /// <summary>
    /// スキルを選ぶ時の関数
    /// </summary>
    void MoveSkill();
    /// <summary>
    /// AABB型の当たり判定
    /// </summary>
    /// <returns></returns>
    AABB GetCardAABB();

    /// <summary>
    /// AABB型のスキル
    /// </summary>
    /// <returns></returns>
    AABB GetSkillAABB();
    /// <summary>
    /// スペースキーを押した場合、カードを消える関数
    /// </summary>
    /// <returns></returns>
    bool cardConfirmed();
    
    
    /// <summary>
    /// Eキーを押した場合、スキル一覧を見ることができる関数
    /// </summary>
    /// <returns></returns>
    bool isSkillBottom();
    /// <summary>
    /// スペースキーを押した場合
    /// </summary>
    /// <returns></returns>
    bool skillConfirmed();

    /// <summary>
    /// バトル時のカードとの当たり判定
    /// </summary>
    bool cardIsCollision_= false;

    // プレイヤーが衝突しているカードのインデックスを追加
    int cardIndex_ = -1;

    //攻撃力
    int attck_;

    bool skillIsCollision_ = false;

    bool isSkillActive_ = false; // スキル発動状態を保持する    
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

    Vector2 skillBottonPos_;
    Vector2 skillBottomSpeed_;
};