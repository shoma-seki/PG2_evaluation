#pragma once

class BaseScene{
private:


public:
	BaseScene() {};
	~BaseScene() {};

	virtual void Initialize();
	virtual void Update();
	virtual void Draw();
};