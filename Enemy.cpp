#include <Novice.h>
#include <math.h>
#include "Enemy.h"


int Enemy::enemyCount = 0;
int Enemy::isAlive = true;

Enemy::Enemy() {
	Enemy::enemyCount++;

	pos_ = { 250 * enemyCount, 250 * enemyCount };
	speed_ = 8;
}

Enemy::~Enemy() { enemyCount--; }

void Enemy::Update() {
	if (!Enemy::isAlive) {
		return;
	}

	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
		speed_ = -speed_;
	}
	pos_.x += speed_;
}

void Enemy::Collision(Bullet* bullet[20]) { 
	if (!Enemy::isAlive) {
		return;
	}

	for (int i = 0; i < 20; i++) {
		if (bullet[i]->isShot_) {
			if (sqrtf(powf(static_cast<float>(bullet[i]->pos_.x - pos_.x), 2.0f) + powf(static_cast<float>(bullet[i]->pos_.y - pos_.y), 2.0f))
				< bullet[i]->radius_ + radius_) {
				//enemyのどれかが倒された場合すべてのenemyを倒す
				Enemy::enemyCount = 0;

				Enemy::isAlive = false;

				break;
			}
		}
	}
}

void Enemy::Draw() {
	if (!Enemy::isAlive) {
		return;
	}

	Novice::DrawEllipse(
		pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid
	);
}