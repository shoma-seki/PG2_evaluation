#pragma once
#include <stack>
#include "BaseScene.h"
#include "Game.h"
#include "Title.h"
#include "SceneChange.h"

class SceneManager{
private:
	static std::stack<BaseScene*> scene_;
	static bool isSceneChange_;
	static bool isEndSceneChange_;

	static BaseScene* afterScene_;
	static BaseScene* currentScene_;
	  
public:
	static void Initialize();
	static void Update();
	static void Draw();

	template <typename T>
	static void SetNextScene(T* sceneP) {
		isSceneChange_ = false;
		isEndSceneChange_ = false;
		afterScene_ = sceneP;
		currentScene_ = scene_.top();
		scene_.pop();
		scene_.push(new SceneChange(currentScene_, afterScene_, &isSceneChange_, &isEndSceneChange_));
	}
};

