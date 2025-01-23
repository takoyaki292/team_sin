#include <Novice.h>
#include "GameScene.h"
#include "MapScene.h"
#include "Map.h"
#include "Texture.h"
#include "Background.h"
const char kWindowTitle[] = "チーム制作_new";

// シーンの状態を管理するためのenum class
enum class SceneState {
    Map,
    Game
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
    Background back;

    // シーンの状態を初期化
    SceneState currentScene = SceneState::Map;

    //Texture* texture_ =new Texture;
    //texture_->InitializeTextures();
    // GameSceneとMapSceneを動的に確保
    GameScene* gameScene = new GameScene();
    gameScene->Initialize(back.oneGameBack);

    Map map;
    MapScene* mapScene = new MapScene();
    mapScene->Initialize(map.oneMap,back.oneMapBack);

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        // シーンの更新と描画
        switch (currentScene) {
        case SceneState::Map:
           // 更新処理
           mapScene->Update();
        
           // 描画処理
           mapScene->Draw();
        
           
           // ゲームシーンに向かう
           if (preKeys[DIK_M] == 0 && keys[DIK_M] != 0) {
               currentScene = SceneState::Game;
           }
           //マップのボスを踏んだら
           if (mapScene->isBattleF)
           {
               currentScene = SceneState::Game;
               mapScene->isBattleF = false;
           }

           //// 二つ目のマップに行く
           if (preKeys[DIK_G] == 0 && keys[DIK_G] != 0) {
               mapScene->Initialize(map.twoMap,back.oneMapBack);
               currentScene = SceneState::Map;
           }
           break;
        case SceneState::Game:
            // 更新処理
            gameScene->Update();

            // 描画処理
            gameScene->Draw();

            //// シーン切り替えのチェック（例：Gキーでマップシーンへ移行）
            if (preKeys[DIK_G] == 0 && keys[DIK_G] != 0) {
                mapScene->Initialize(map.twoMap,back.oneMapBack);
                currentScene = SceneState::Map;
            }
            break;
       

        }

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // メモリの解放
    delete gameScene;
    delete mapScene;
    

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
