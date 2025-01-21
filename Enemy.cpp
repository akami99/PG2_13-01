#include <Novice.h>
#include <math.h>
#include "Enemy.h"


int Enemy::enemyCount = 0;


Enemy::Enemy() {
	enemyCount++;

	pos_ = { 250 * enemyCount, 250 * enemyCount };
	speed_ = 8;
	isAlive_ = true;
}

Enemy::~Enemy() { enemyCount--; }

void Enemy::Update() {
	if (!isAlive_) {
		return;
	}

	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
		speed_ = -speed_;
	}
	pos_.x += speed_;
}

void Enemy::Collision(Bullet* bullet[20]) { 
	if (!isAlive_) {
		return;
	}

	for (int i = 0; i < 20; i++) {
		if (bullet[i]->isShot_) {
			if (sqrtf(powf(static_cast<float>(bullet[i]->pos_.x - pos_.x), 2.0f) + powf(static_cast<float>(bullet[i]->pos_.y - pos_.y), 2.0f))
				< bullet[i]->radius_ + radius_) {

				enemyCount = 0;

				isAlive_ = false;

				break;
			}
		}
	}
}

void Enemy::Draw() {
	if (!isAlive_) {
		return;
	}

	Novice::DrawEllipse(
		pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid
	);
}