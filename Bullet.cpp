#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	// メンバ変数の初期化
	pos_ = { 0, 0 };
	radius_ = 16;
	speed_ = 12;
	isShot_ = false;
}

void Bullet::Update(const IntVector2 playerPos) {
	if (isShot_) {
		// 移動処理
		pos_.y -= speed_;
	} else {
		// 弾の格納
		pos_ = playerPos;
	}
	// 画面外の処理
	if (pos_.y + radius_ < 0) {
		isShot_ = false;
	}
}

void Bullet::Draw() {
	// 発射中
	if (isShot_) {
		Novice::DrawEllipse(
			pos_.x, pos_.y,
			radius_, radius_,
			0.0f, WHITE, kFillModeSolid
		);
	}
}