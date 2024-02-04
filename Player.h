#pragma once
#include "BaseObject.h"
#include "Novice.h"
#include "cmath"
#include "BulletManager.h"
#include "Bullet.h"

class Player : public BaseObject {
private:
	int mouX;
	int mouY;
	bool isEase;

	int bulletGH_;
	int fireGH_;
	BulletManager* bulletM_;

	bool isHit_;
	int HP_;
	int invincibleTime_;

public:
	Player() { Initialize(); }
	~Player() { delete bulletM_; }

	void Initialize() override;
	void Update() override;
	void Draw() override;

	void SetIsHit(bool isHit) { isHit_ = isHit; }

	Vector2Array GetPos() { return obj_.translate; }
	std::vector<Bullet*>& GetBullet() { return bulletM_->GetBullet(); }
	float GetSpeed() { return speed_; }
	int GetHP() { return HP_; }
};

