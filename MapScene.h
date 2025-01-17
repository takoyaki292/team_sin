#pragma once
#include "FixedNum.h"
#include "Player.h"
#include "Texture.h"
class MapScene
{
public:
    MapScene();
    ~MapScene();
    void Initialize(const int map[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX]);
    void Update();
    void Draw();

private:
    int map_[FixedNum::mapChipSizeY][FixedNum::mapChipSizeX];
    Player* player_;
    Texture* texture_;
    
};
