#pragma once
#include "IntVector2.h"
#include "Bullet.h"

class Enemy {
protected: // メンバ変数
	IntVector2 pos_; // 座標
	int speed_ = 8;   // 速さ
	const int radius_ = 20;  // 半径

public:
	static int enemyCount;

	static int isAlive;  // 生きているかどうか

public:    // メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Enemy();

	/// <summary>
	/// デコンストラクタ
	/// </summary>
	~Enemy();

	/// <summary>
	/// 敵の更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 敵の衝突判定
	/// </summary>
	void Collision(Bullet* bullet[20]);

	/// <summary>
	/// 敵の描画処理
	/// </summary>
	void Draw();
};
