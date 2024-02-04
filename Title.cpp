#include "Title.h"

void Title::Initialize() {
	TitleGH_ = Novice::LoadTexture("./resources./Title.png");
	LeftClickGH_ = Novice::LoadTexture("./resources./LeftClick.png");
}

void Title::Update() {
	if (Novice::IsTriggerMouse(0)) {
		SceneManager::SetNextScene(new Game);
	}
}

void Title::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawSprite(640 - 330, 360 - 40, TitleGH_, 1, 1, 0.0f, 0xFFFFFFFF);
	Novice::DrawSprite(640 - 95, 560 - 16, LeftClickGH_, 1, 1, 0.0f, 0xFFFFFFFF);
}
