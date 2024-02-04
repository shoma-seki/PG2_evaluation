#include "EnemyManager.h"

void EnemyManager::Initialize() {
	NEnemyGH_ = Novice::LoadTexture("./resources./normalEnemy.png");
	isStop_ = false;
}

void EnemyManager::Update(std::vector<Bullet*> bullet, Vector2Array playerTranslate, float playerSpeed) {
	for (int i = 0; i < enemy_.size(); i++) {
		if (enemy_[i] != nullptr) {
			enemy_[i]->Update(bullet, playerTranslate, playerSpeed);
			enemyPos_ = enemy_[i]->GetIsPos();
		}
		if (enemy_[i]->GetIsAlive() == false) {
			delete enemy_[i];
			enemy_[i] = nullptr;
			enemy_.erase(enemy_.begin() + i);
			isStop_ = true;
		}

		if (enemyPos_.vector2[0] < -100 || enemyPos_.vector2[0]>1380) {
			delete enemy_[i];
			enemy_[i] = nullptr;
			enemy_.erase(enemy_.begin() + i);
		}
		else if (enemyPos_.vector2[1] < -100 || enemyPos_.vector2[1]>820) {
			delete enemy_[i];
			enemy_[i] = nullptr;
			enemy_.erase(enemy_.begin() + i);
		}
	}
}

void EnemyManager::Draw(Vector2Array random) {
	for (int i = 0; i < enemy_.size(); i++) {
		if (enemy_[i] != nullptr) {
			enemy_[i]->Draw(NEnemyGH_, random);
		}
	}
}

void EnemyManager::PopEnemy(Vector2Array translate, Vector2Array direction, float speed) {
	enemy_.emplace_back(new NormalEnemy(translate, direction, speed));
}

bool EnemyManager::GetIsHitPlayer() {
	for (int i = 0; i < enemy_.size(); i++) {
		if (enemy_[i] != nullptr) {
			isHitPlayer_ = enemy_[i]->GetIsHitPlayer();
			if (isHitPlayer_ == true) {
				break;
			}
		}
	}
	return isHitPlayer_;
}
