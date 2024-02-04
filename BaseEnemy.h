#pragma once
#include "BaseObject.h"
#include "Bullet.h"

class BaseEnemy : public BaseObject {
protected:
	bool isAlive_;
	bool isHitPlayer_;

public:
	virtual void Initialize(Vector2Array translate, Vector2Array direction, float speed);
	virtual void Update(std::vector<Bullet*> bullet, Vector2Array playerTranslate,float playerSpeed);
	virtual void Draw(int GH,Vector2Array random);
	virtual bool GetIsAlive() { return isAlive_; }
	virtual Vector2Array GetIsPos() { return obj_.translate; }
	virtual bool GetIsHitPlayer() { return isHitPlayer_; }
};

