#pragma once
#include "BaseEnemy.h"
#include "Functions.h"
#include <cmath>
#include "Bullet.h"

class NormalEnemy : public BaseEnemy {
private:
	std::vector<Bullet*> bullet_;
	float dis_;
	float playerDis_;

public:
	NormalEnemy(Vector2Array translate, Vector2Array direction, float speed) { Initialize(translate, direction, speed); }
	~NormalEnemy() {}

	void Initialize(Vector2Array translate, Vector2Array direction, float speed) override;
	void Update(std::vector<Bullet*> bullet, Vector2Array playerTranslate,float playerSpeed) override;
	void Draw(int GH,Vector2Array random) override;
	bool GetIsAlive()override { return isAlive_; };
	Vector2Array GetIsPos() override { return obj_.translate; }
	bool GetIsHitPlayer() override { return isHitPlayer_; }
};

