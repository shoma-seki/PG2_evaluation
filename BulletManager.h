#pragma once
#include "Bullet.h"
#include "vector"

class BulletManager{
private:
	std::vector<Bullet*> bullet_;
	int GH_;

public:
	BulletManager() { Initialize(); }
	~BulletManager() {}

	void Initialize();
	void Update();
	void Draw();
	void ShotBullet(Vector2Array playerTranslate, Vector2Array playerDirection, float playerTheta);

	std::vector<Bullet*>& GetBullet() { return bullet_; }
};

