#pragma once
#include "Player.h"

class GameScene
{
public:
    GameScene();
    ~GameScene();

    void Initialize();
    void Update();
    void Draw();

private:
    Player* player_ = nullptr; // Playerのポインタ
};
