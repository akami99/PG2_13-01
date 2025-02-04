#include <Novice.h>
#include "Player.h"
#include "Enemy.h"



const char kWindowTitle[] = "LC1B_01_アカミネ_レン_PG2_13-01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	// 生成
	//player
	Player* player = new Player;

	//enemy
	Enemy* enemyA = new Enemy;
	Enemy* enemyB = new Enemy;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// リセット操作
		if (keys[DIK_R] && preKeys[DIK_R]) {
			Enemy::isAlive = true;
			Enemy::enemyCount = 2;
		}
		
		// playerの更新処理
		player->Update(keys, preKeys);

		// enemyの更新処理
		enemyA->Update();
		enemyB->Update();

		//衝突判定
		enemyA->Collision(player->bullet_);
		enemyB->Collision(player->bullet_);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// enemyの描画処理
		enemyA->Draw();
		enemyB->Draw();

		// paleyrの描画処理
		player->Draw();

		// UI
		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemyA->isAlive);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemyB->isAlive);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// 削除
	delete player;

	delete enemyA;
	delete enemyB;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
