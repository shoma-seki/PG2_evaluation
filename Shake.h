#pragma once  
#include "Struct.h"
#include "stdlib.h"
#include "Functions.h"

class Shake {
private:
	Vector2Array random_;
	bool isShake_;

public:
	Shake(){}
	~Shake(){}

	void Initialize();
	void Update(bool isShake);

	Vector2Array GetRandom() { return random_;}
};

