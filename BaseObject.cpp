#include "BaseObject.h"

void BaseObject::RenderingPipelineB(const CameraData& camera){
	obj_.worldMatrix = MakeAffineMatrix(obj_.scale, obj_.theta, obj_.translate);
	obj_.wvpVpMatrix = RenderingPipeline(obj_.worldMatrix, camera.viewMatrix, camera.orthographicMatrix, camera.viewportMatrix);

	obj_.screenLt = Transform(obj_.lt, obj_.wvpVpMatrix);
	obj_.screenRt = Transform(obj_.rt, obj_.wvpVpMatrix);
	obj_.screenLb = Transform(obj_.lb, obj_.wvpVpMatrix);
	obj_.screenRb = Transform(obj_.rb, obj_.wvpVpMatrix);
}

void BaseObject::LocalToScreen(Object& obj){
	obj.worldMatrix = MakeAffineMatrix(obj.scale, obj.theta, obj.translate);
	obj.screenLt = Transform(obj.lt, obj.worldMatrix);
	obj.screenRt = Transform(obj.rt, obj.worldMatrix);
	obj.screenLb = Transform(obj.lb, obj.worldMatrix);
	obj.screenRb = Transform(obj.rb, obj.worldMatrix);
}
