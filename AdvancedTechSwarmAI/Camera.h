#pragma once
#ifndef _CAMERACLASS_H_
#define _CAMERACLASS_H_

#include "SceneData.h"
#include "DrawData.h"
#include "GameObject.h"
#include <directxmath.h>
using namespace DirectX;

class Camera : public GameObject
{
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	virtual void Tick(std::unique_ptr<SceneData> _SD);
	virtual void Draw(std::unique_ptr<DrawData> _DD) override;
	void Render();
	void GetViewMatrix(XMMATRIX&);

private:
	XMMATRIX m_viewMatrix;
};

#endif