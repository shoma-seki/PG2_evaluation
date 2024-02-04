#include "Bullet.h"

void Bullet::Initialize(int GH, Vector2Array playerTranslate, Vector2Array playerDirection, float playerTheta){
	GH_ = GH;
	obj_.size = { 64,64 };
	imgSize_ = { 64,64 };
	obj_.lt = { -obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.rt = { obj_.size.vector2[0] / 2.0f,-obj_.size.vector2[1] / 2.0f, };
	obj_.lb = { -obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.rb = { obj_.size.vector2[0] / 2.0f,obj_.size.vector2[1] / 2.0f, };
	obj_.translate = playerTranslate;
	obj_.scale = { 0.3f,0.3f };
	obj_.theta = playerTheta;
	LocalToScreen(obj_);

	speed_ = 10;
	direction_ = {-playerDirection.vector2[0],-playerDirection.vector2[1] };
	velocity_ = { 0,0 };
}

void Bullet::Update(){
	Move();
	LocalToScreen(obj_);
}

void Bullet::Draw(){
	MyDrawQuad(obj_, imgSize_, GH_, 0xFFFFFFFF);
}

void Bullet::Move(){
	speed_ -= 0.1f;
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
}
