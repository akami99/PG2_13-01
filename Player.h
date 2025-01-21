#pragma once
#include "IntVector2.h"
#include "Bullet.h"

class Player {
public:   // メンバ変数
	Bullet* bullet_[20];  // 弾クラスのポインタ変数
	IntVector2 pos_;  // 座標
	int radius_;      // 半径
	int speed_;       // 速さ

public:   // メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デコンストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 自機の更新処理
	/// </summary>
	/// <param name="keys">キー入力の取得</param>
	/// <param name="preKeys">1フレーム前のキー入力の取得</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 自機の描画処理
	/// </summary>
	void Draw();
};

