#ifndef _DRAW_DATA_H_
#define _DRAW_DATA_H_

#include <d3d11.h>
#include <memory>
#include "Camera.h"

class Camera;

struct DrawData
{
	std::unique_ptr <ID3D11DeviceContext> m_pd3dImmediateContext;
	std::unique_ptr <Camera> m_MainCamera;
};

#endif