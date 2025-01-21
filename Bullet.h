#pragma once
#include "IntVector2.h"

class Bullet {
public:
	// メンバ変数
	IntVector2 pos_; // 座標
	int radius_;     // 半径
	int speed_;      // 速さ
	int isShot_;     // 発射フラグ

public:
	// メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update(const IntVector2 playerPos);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
};