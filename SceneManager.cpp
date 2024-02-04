#include "SceneManager.h"

std::stack<BaseScene*> SceneManager::scene_;
bool SceneManager::isSceneChange_;
bool SceneManager::isEndSceneChange_;

BaseScene* SceneManager::afterScene_;
BaseScene* SceneManager::currentScene_;

void SceneManager::Initialize() {
	scene_.push(new Title);
}

void SceneManager::Update() {
	scene_.top()->Update();
	if (isEndSceneChange_ == true) {
		delete currentScene_;
		delete scene_.top();
		scene_.pop();
		scene_.push(afterScene_);
		isEndSceneChange_ = false;
	}
}

void SceneManager::Draw() {
	scene_.top()->Draw();
}
