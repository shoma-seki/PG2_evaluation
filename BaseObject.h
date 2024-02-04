#pragma once
#include "Struct.h"
#include "Functions.h"

class BaseObject {
protected:
	Object obj_;
	Vector2Array direction_;
	Vector2Array velocity_;
	float speed_;
	Vector2Array imgSize_;

	int GH_;

public:
	BaseObject() {}
	~BaseObject() {}

	virtual void Initialize() {}
	virtual void Update() {}
	virtual void Draw() {}
	void RenderingPipelineB(const CameraData& camera);
	void LocalToScreen(Object& obj);
};

