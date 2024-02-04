#pragma once
#include "BaseScene.h"
#include "Struct.h"
#include "Functions.h"
#include <stack>

class SceneChange : public BaseScene {
private:
	std::stack<BaseScene*>currentScene_;
	BaseScene* afterScene_;
	bool* isSceneChange_;
	bool* isEndSceneChange_;
	bool isStart_;

	Vector2Array size_;
	Vector2Array pos_;
	float x1_;
	float x2_;
	float x3_;
	float t1_;
	float t2_;
	float t3_;
	float cnt_;

public:

	template <typename T>
	SceneChange(BaseScene* CurrentScene, T* afterScene, bool* isSceneChange, bool* isEndSceneChange) { Initialize(CurrentScene, afterScene, isSceneChange, isEndSceneChange); }
	~SceneChange() {}

	template <typename T>
	void Initialize(BaseScene* CurrentScene, T* afterScene, bool* isSceneChange, bool* isEndSceneChange) {
		currentScene_.push(CurrentScene);
		afterScene_ = afterScene;
		isSceneChange_ = isSceneChange;
		isEndSceneChange_ = isEndSceneChange;
		isStart_ = true;

		size_ = { 20,20 };
		x1_ = 0.01f;
		x2_ = 0.01f;
		cnt_ = 0;
	}
	void Update() override;
	void Draw() override;

	void Transition();
};

