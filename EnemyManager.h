#pragma once
#include "NormalEnemy.h"
#include <vector>

class EnemyManager{
private:
	std::vector<BaseEnemy*> enemy_;
	Vector2Array enemyPos_;
	int NEnemyGH_;
	bool isStop_;
	bool isHitPlayer_;

public:
	EnemyManager(){ Initialize(); }
	~EnemyManager(){}

	void Initialize();
	void Update(std::vector<Bullet*> bullet, Vector2Array playerTranslate,float playerSpeed);
	void Draw(Vector2Array random);
	void PopEnemy(Vector2Array translate, Vector2Array direction, float speed);
	bool* GetStop() { return &isStop_; }
	bool GetIsHitPlayer();
};

