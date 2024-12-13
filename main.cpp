#include <Novice.h>
#include "GameScene.h"

const char kWindowTitle[] = "チーム制作_new";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // GameSceneを動的に確保
    GameScene* gameScene = new GameScene();
    gameScene->Initialize();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        // 更新処理
        gameScene->Update();

        // 描画処理
        gameScene->Draw();

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // GameSceneのメモリを解放
    delete gameScene;

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
