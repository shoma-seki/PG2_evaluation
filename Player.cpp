#include "Player.h"

void Player::Initialize() {
	GH_ = Novice::LoadTexture("./resources./player.png");
	fireGH_ = Novice::LoadTexture("./resources./playerFire.png");
	obj_.size = { 64,80 };
	imgSize_ = { 64,80 };
	obj_.lt = { -obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.rt = { obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.lb = { -obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.rb = { obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.translate = { 640,360 };
	obj_.scale = { 0.5f,0.5f };
	obj_.theta = 0;
	LocalToScreen(obj_);

	speed_ = 0;
	direction_ = { 0,0 };
	velocity_ = { 0,0 };

	HP_ = 100;
	invincibleTime_ = 0;

	bulletM_ = new BulletManager();
}

void Player::Update() {
	Novice::GetMousePosition(&mouX, &mouY);

	if (speed_ > 0.1f) {
		speed_ -= 0.1f;
	}
	velocity_ = { direction_.vector2[0] * speed_,direction_.vector2[1] * speed_ };
	obj_.translate.vector2[0] += velocity_.vector2[0];
	obj_.translate.vector2[1] += velocity_.vector2[1];

	if (obj_.translate.vector2[0] < 100) {
		obj_.translate.vector2[0] = 101;
		direction_.vector2[0] *= -1;
	}
	else if (obj_.translate.vector2[0] > 1180) {
		obj_.translate.vector2[0] = 1179;
		direction_.vector2[0] *= -1;
	}

	if (obj_.translate.vector2[1] < 100) {
		obj_.translate.vector2[1] = 101;
		direction_.vector2[1] *= -1;
	}
	else if (obj_.translate.vector2[1] > 620) {
		obj_.translate.vector2[1] = 619;
		direction_.vector2[1] *= -1;
	}

	obj_.theta = std::atan2f(-direction_.vector2[0], direction_.vector2[1]);

	SizeEase(obj_.size, isEase);
	obj_.lt = { -obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.rt = { obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.lb = { -obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.rb = { obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };

	LocalToScreen(obj_);

	if (Novice::IsTriggerMouse(0)) {
		if (speed_ < 10) {
			speed_ += 2;
		}
		direction_.vector2[0] = Normalize(float(mouX), float(mouY), 640.0f, 320.0f, 1);
		direction_.vector2[1] = Normalize(float(mouX), float(mouY), 640.0f, 320.0f, 2);
		isEase = true;

		obj_.theta = std::atan2f(-direction_.vector2[0], direction_.vector2[1]);

		bulletM_->ShotBullet(obj_.translate, direction_, obj_.theta);
	}

	bulletM_->Update();

	if (isHit_ == true) {
		invincibleTime_++;
		if (invincibleTime_ == 1) {
			if (HP_ >= 5) {
				HP_ -= 5;
			}
		}
	}
	else {
		invincibleTime_ = 0;
	}
}

void Player::Draw() {
	if (isHit_ == false) {
		if (speed_ <= 6) {
			MyDrawQuad(obj_, imgSize_, GH_, 0xFFFFFFFF);
		}
		else {
			MyDrawQuad(obj_, imgSize_, fireGH_, 0xFFFFFFFF);
		}
	}
	else {
		MyDrawQuad(obj_, imgSize_, GH_, 0xFF0000FF);
	}

	bulletM_->Draw();

	Novice::DrawBox(30, 30, HP_ * 3, 50, 0.0f, 0x22DD22FF, kFillModeSolid);
}
