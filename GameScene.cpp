#include "GameScene.h"

GameScene::GameScene()
{
    // Playerのインスタンスを動的に確保
    player_ = new Player();
}

GameScene::~GameScene()
{
    // 確保したPlayerのメモリを解放
    delete player_;
}

void GameScene::Initialize()
{
    // Playerの初期化用データ
    Vector2 playerPos = { 80.f, 80.f };
    Vector2 playerSize = { 50.f, 100.f };
    Vector2 playerMovePos = playerPos;
    int playerHp = 10;
    bool plyaerIsAlive = true;
    bool playerIsTurn = false;
    int playerCardMoveSpeed = 100;

    // player_の初期化
    player_->Initialize(playerPos, playerSize, playerHp, plyaerIsAlive, playerIsTurn, playerMovePos, playerCardMoveSpeed);
}

void GameScene::Update()
{
    // Playerの更新処理
    player_->BattleUpdate();
}

void GameScene::Draw()
{
    // Playerの描画処理
    player_->BattleDraw();
}
