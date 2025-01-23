#pragma once
#include "Player.h"
#include "Card.h"
#include "FixedNum.h"
#include "Skill.h"
#include "Texture.h"
#include "Boss.h"

class GameScene
{
public:
    GameScene();
    ~GameScene();

    //void Initialize();
    void Initialize(int backT);
    void Update();
    void Draw();
    
    /// <summary>
    /// AABB型の当たり判定の関数
    /// </summary>
    /// <param name="aabb1"></param>
    /// <param name="aabb2"></param>
    /// <returns></returns>
    bool IsCollision(AABB aabb1, AABB aabb2);

    /// <summary>
    /// 全ての当たり判定を管理する
    /// </summary>
    void ChecAllCollisiions();


private:

    Player* player_ = nullptr; // Playerのポインタ
    Card* card_ = nullptr;
    FixedNum* fixedNum_ = nullptr;
    Skill* skill_ = nullptr;
    Texture* texture_=nullptr;
    Boss* boss_ = nullptr;

    int backT_;
};
