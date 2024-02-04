#pragma once
#include "BaseScene.h"
#include "Novice.h"
#include "SceneManager.h"

class Title:public BaseScene{
private:
	int TitleGH_;
	int LeftClickGH_;

public:
	Title() { Initialize(); };
	~Title() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
};

