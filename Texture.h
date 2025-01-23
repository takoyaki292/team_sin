#pragma once
#include "FixedNum.h"
#include <Novice.h>

class Texture {
public:
    // メンバ変数
    int player;                   
    int cards[FixedNum::cardNum]; 
    int skill;                    
    int skillPlusTwo;             
    int skillReversal;

    int map11;
    int mapBoss;
    int mapCard;
    
    int oneBoss;
    // コンストラクタでテクスチャを初期化
    Texture() {
        // プレイヤーのテクスチャをロード
        player = Novice::LoadTexture("./Resources/images/player/player01.png");

       cards[0]= Novice::LoadTexture("./Resources/images/card/1.png");
       cards[1]= Novice::LoadTexture("./Resources/images/card/2.png");
       cards[2]= Novice::LoadTexture("./Resources/images/card/3.png");
       cards[3]= Novice::LoadTexture("./Resources/images/card/4.png");
       cards[4]= Novice::LoadTexture("./Resources/images/card/5.png");
       cards[5]= Novice::LoadTexture("./Resources/images/card/6.png");
       cards[6]= Novice::LoadTexture("./Resources/images/card/7.png");
       //cards[0]= Novice::LoadTexture("./Resources/images/card/1.png");

        // スキルのテクスチャをロード
        skill = Novice::LoadTexture("./Resources/images/skill/skill.png");
        skillPlusTwo = Novice::LoadTexture("./Resources/images/skill/skill_+2.png");
        skillReversal = Novice::LoadTexture("./Resources/images/skill/skill_reversal.png");

        //マップのテクスチャをロード
        map11 = Novice::LoadTexture("./Resources/images/mapChip/block01.png");
        mapBoss = Novice::LoadTexture("./Resources/images/mapChip/bosMapChip.png");
        mapCard = Novice::LoadTexture("./Resources/images/mapChip/card01.png");
    
        oneBoss= Novice::LoadTexture("./Resources/images/enemy/boss.png");
    }

    
};
