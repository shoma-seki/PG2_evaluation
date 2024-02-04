#include "BulletManager.h"

void BulletManager::Initialize() {
	GH_ = Novice::LoadTexture("./resources./bullet.png");
}

void BulletManager::Update() {
	for (int i = 0; i < bullet_.size(); i++) {
		if (bullet_[i] != nullptr) {
			bullet_[i]->Update();
		}
		if (bullet_[i]->GetSpeed() < 0.0f) {
			delete bullet_[i];
			bullet_[i] = nullptr;
			bullet_.erase(bullet_.begin() + i);
		}
	}
}

void BulletManager::Draw() {
	for (int i = 0; i < bullet_.size(); i++) {
		if (bullet_[i] != nullptr) {
			bullet_[i]->Draw();
		}
	}
}

void BulletManager::ShotBullet(Vector2Array playerTranslate, Vector2Array playerDirection, float playerTheta) {
	bullet_.emplace_back(new Bullet(GH_, playerTranslate, playerDirection, playerTheta));
}