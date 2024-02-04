#pragma once
#include "BaseScene.h"
#include "Novice.h"
#include "SceneManager.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Shake.h"

class Game:public BaseScene{
private:
	Player* player_;
	EnemyManager* enemy_;
	Shake* shake_;
	Vector2Array random_;

	int cnt_;
	int stopCnt_;
	bool isPopEnemySet1_;
	bool isPopEnemySet2_;
	bool isPopEnemySet3_;
	bool* isStop_;
	bool isGameOver_;
	bool isClear_;

	int GameOverGH_;
	int ClearGH_;
	int LeftClickGH_;
	int gameOverCount_;
	int ClearCount_;

	int mouX_;
	int mouY_;

public:
	Game() { Initialize(); };
	~Game() {
		delete player_;
		delete enemy_;
		delete shake_;
	};

	void Initialize() override;
	void Update() override;
	void Draw() override;

	void PopEnemySet1(int setCnt);
	void PopEnemySet2(int setCnt);
	void PopEnemySet3(int setCnt);
	void SetIsPopEnemy(int SetName);
};

