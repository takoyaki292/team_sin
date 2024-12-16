#include "GameScene.h"

GameScene::GameScene()
{
    // Playerのインスタンスを動的に確保
    player_ = new Player();
    fixedNum_ = new FixedNum();
    card_ = new Card();
}

GameScene::~GameScene()
{
    // 確保したPlayerのメモリを解放
    delete player_;
    delete fixedNum_;
    delete card_;
}

void GameScene::Initialize()
{
    
    //カードの初期化
    Vector2 cardPos[fixedNum_->cardNum]{};
    Vector2 cardSize;
    bool haveCardF[fixedNum_->cardNum]{};

    for (int i = 0; i < fixedNum_->cardNum; i++)
    {
        cardPos[i] = Vector2(450.f + i * 100.f, 600.f);
        cardSize = { 50.f,100.f };
        haveCardF[i] = true;
    }
    card_->Initialize(cardPos,cardSize,haveCardF);

    // Playerの初期化用データ
    Vector2 playerPos = { 80.f, 80.f };
    Vector2 playerSize = { 50.f, 100.f };
    Vector2 playerMovePos = cardPos[0];
    Vector2 hpPosition = {400.f,550.f};
    int playerHp = 10;
    bool plyaerIsAlive = true;
    bool playerIsTurn = false;
    Vector2 playerCardMoveSpeed = {cardSize.x*2,cardSize.y * 2, };
    bool cardIsCollision = false;
    // player_の初期化
    player_->Initialize(playerPos, playerSize, playerHp,hpPosition, plyaerIsAlive, playerIsTurn, playerMovePos, playerCardMoveSpeed, cardIsCollision);

}

    
void GameScene::Update()
{
    // Playerの更新処理
    player_->BattleUpdate();

    ChecAllCollisiions();

}

void GameScene::Draw()
{
    // Playerの描画処理
    player_->BattleDraw();

    card_->BattleDraw();
}

bool GameScene::IsCollision(AABB aabb1, AABB aabb2)
{
    bool ATFlag = false;

    if (aabb1.max.y > aabb2.min.y && aabb1.min.y < aabb2.max.y) {

        if (aabb1.max.x > aabb2.min.x && aabb1.min.x < aabb2.max.x) {
            ATFlag = true;
        }
    }
    else {
        ATFlag = false;
    }
    

    return ATFlag;
}

void GameScene::ChecAllCollisiions()
{
    AABB playerAABB = player_->GetCardAABB();

    if (!card_ || !fixedNum_) return;
    for (int i = 0; i < fixedNum_->cardNum; i++)
    {
        if (i < 0 || i >= fixedNum_->cardNum) continue; 

        if (card_->haveCardF_[i]) 
        {
            AABB cardAABB = card_->GetCardAABB(i);

            if (IsCollision(playerAABB, cardAABB))
            {
                // 衝突した場合の処理
                player_->cardIsCollision_ = true;
                
                //スペースキーを押したら
                if (player_->cardConfirmed())
                {
                    player_->attck_ = card_->num[i];
                    card_->haveCardF_[i] = false;
                    //player_->cardAttck(*card_);
                }
            }
        }
    }
}


