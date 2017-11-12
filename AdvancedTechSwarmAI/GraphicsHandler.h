#ifndef _GRAPHICSHANDLER_H_
#define _GRAPHICSHANDLER_H_

#include <windows.h>
#include <memory>
#include "Direct3D.h"
#include "Camera.h"
#include "VBObject.h"
#include "Shader.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsHandler
{
public:
	GraphicsHandler();
	GraphicsHandler(const GraphicsHandler&);
	~GraphicsHandler();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render();
	std::unique_ptr<Direct3D> m_Direct3D;
	Camera* m_Camera;
	VBObject* m_vbo;
	Shader* m_shader;

};

#endif