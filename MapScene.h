#pragma once
#include "FixedNum.h"
#include "Player.h"
#include "Texture.h"
class MapScene
{
public:
    MapScene();
    ~MapScene();
    void Initialize(const int map[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX],int backT);
    void Update();
    void Draw();

    bool isBattleF = false;
private:
    int map_[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX];
    Player* player_;
    Texture* texture_;
    
    void MapCollisiion();

    int backT_;
};
