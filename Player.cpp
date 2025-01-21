#include <Novice.h>
#include "Player.h"

Player::Player() {
	// メンバ変数の初期化
	pos_ = { 640, 400 };
	speed_ = 10;
	radius_ = 36;
	// 弾クラスの実体を生成
	for (int i = 0; i < 20; i++) {
		bullet_[i] = new Bullet();
	}
}

Player::~Player() {
	// ポインタ削除
	for (int i = 0; i < 20; i++) {
		delete bullet_[i];
	}
}

void Player::Update(char* keys, char* preKeys) {
	// nullチェック
	if (keys == nullptr || preKeys == nullptr) {
		return;
	}

	// 移動処理
	if (keys[DIK_A] || keys[DIK_LEFT]) { // 左
		pos_.x -= speed_;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {// 右
		pos_.x += speed_;
	}
	if (keys[DIK_W] || keys[DIK_UP]) {   // 上
		pos_.y -= speed_;
	}
	if (keys[DIK_S] || keys[DIK_DOWN]) { // 下
		pos_.y += speed_;
	}

	// 発射処理
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		for (int i = 0; i < 20; i++) {
			if (!bullet_[i]->isShot_) {
				bullet_[i]->pos_ = pos_;
				bullet_[i]->isShot_ = true;
				break;
			}
		}
	}

		// 弾の更新処理
		for (int i = 0; i < 20; i++) {
			bullet_[i]->Update(pos_);
		}
}

	void Player::Draw() {
	// 弾の描画
		for (int i = 0; i < 20; i++) {
			bullet_[i]->Draw();
		}

	// プレイヤーの描画
	Novice::DrawEllipse(
		pos_.x, pos_.y,
		radius_, radius_,
		0.0f, GREEN, kFillModeSolid
	);
}
