#pragma once
#include "Vector2.h"
#include "FixedNum.h"
#include "Texture.h"
#include "Card.h"

class Boss {
public:
    void Initialize(Vector2 pos, Vector2 size, bool isTrue, int attck, int hp, Vector2 hpPos, int randomAttck[FixedNum::haveCard], bool isAlive);
    void Update();
    void Draw(int bossTexture, int cardT[FixedNum::cardNum]);
    void AttckRandom();

private:
    Vector2 pos_;
    Vector2 size_;
    int attck_;
    bool isTrue_;
    int hp_;
    Vector2 hpPos_;
    int randomAttck_[FixedNum::haveCard];
    bool isAlive_;
    //Card* card_;
};