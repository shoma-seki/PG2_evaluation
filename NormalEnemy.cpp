#include "NormalEnemy.h"

void NormalEnemy::Initialize(Vector2Array translate, Vector2Array direction, float speed) {

	obj_.translate = translate;
	direction_ = direction;
	speed_ = speed;

	obj_.size = { 64,80 };
	imgSize_ = { 64,80 };
	obj_.lt = { -obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.rt = { obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.lb = { -obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.rb = { obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.scale = { 0.5f,0.5f };
	obj_.theta = 0;
	LocalToScreen(obj_);

	isAlive_ = true;
}

void NormalEnemy::Update(std::vector<Bullet*> bullet, Vector2Array playerTranslate, float playerSpeed) {
	bullet_ = bullet;
	velocity_ = { direction_.vector2[0] * speed_,direction_.vector2[1] * speed_ };
	obj_.translate.vector2[0] += velocity_.vector2[0];
	obj_.translate.vector2[1] += velocity_.vector2[1];
	if (bullet_.size() > 0) {
		for (int i = 0; i < bullet.size(); i++) {
			dis_ = GetDis(obj_.translate, bullet_[i]->GetPos());
			if (dis_ < 30) {
				isAlive_ = false;
			}
		}
	}

	if (playerSpeed > 6) {
		playerDis_ = GetDis(obj_.translate, playerTranslate);
		if (playerDis_ < 30) {
			isAlive_ = false;
		}
	}
	else if (playerSpeed <= 6) {
		playerDis_ = GetDis(obj_.translate, playerTranslate);
		if (playerDis_ < 50) {
			isHitPlayer_ = true;
		}
		else {
			isHitPlayer_ = false;
		}
	}
	LocalToScreen(obj_);
	obj_.theta = std::atan2f(-direction_.vector2[0], direction_.vector2[1]);
}

void NormalEnemy::Draw(int GH, Vector2Array random) {
	if (isAlive_ == true) {
		MyDrawQuadR(obj_, random, imgSize_, GH, 0xFFFFFFFF);
	}
}