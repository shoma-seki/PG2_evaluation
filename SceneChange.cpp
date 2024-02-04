#include "SceneChange.h"

void SceneChange::Update() {
	Transition();
	if (x1_ >= 0.90f) {
		isStart_ = false;
	}
	if (x2_ >= 0.90f) {
		*isSceneChange_ = true;
	}
	if (x3_ >= 0.90f) {
		*isEndSceneChange_ = true;
	}
	if (*isSceneChange_ == true && currentScene_.top() != afterScene_) {
		currentScene_.push(afterScene_);
		x3_ = 0.01f;
	}
}

void SceneChange::Draw() {
	currentScene_.top()->Draw();
	Novice::DrawEllipse(int(pos_.vector2[0]), int(pos_.vector2[1]), int(size_.vector2[0]), int(size_.vector2[1]), 0.0f, 0xAAAAAAFF, kFillModeSolid);
}

void SceneChange::Transition() {
	cnt_++;
	if (isStart_ == true) {
		x1_ += 0.01f;
		Easing(pos_, { 640,1000 }, { 640,360 }, t1_);
		t1_ = EaseOutQuint(x1_);
	}
	else{
		if (*isSceneChange_ == false) {
			x2_ += 0.01f;
			Easing(size_, { 50,50 }, { 1280,1280 }, t2_);
			t2_ = EaseOutQuint(x2_);
		}
		else {
			x3_ += 0.01f;
			Easing(size_, { 1280,1280 }, { 0,0 }, t3_);
			t3_ = EaseOutQuint(x3_);
		}
	}
}
