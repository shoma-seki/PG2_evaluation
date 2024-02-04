#pragma once
#include "BaseObject.h"
#include "cmath"

class Bullet : public BaseObject{
private:
	

public:
	Bullet(int GH, Vector2Array playerTranslate, Vector2Array playerDirection, float playerTheta) { Initialize(GH,playerTranslate,playerDirection,playerTheta); }
	~Bullet(){}

	void Initialize(int GH,Vector2Array playerTranslate,Vector2Array playerDirection,float playerTheta);
	void Update();
	void Draw();
	void Move();

	float GetSpeed() { return speed_; }
	Vector2Array GetPos() { return obj_.translate; }
};

