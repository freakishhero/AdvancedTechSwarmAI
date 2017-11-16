#ifndef _SCENE_H
#define _SCENE_H_

#include <windows.h>
#include <dinput.h>
#include <memory>
#include <vector>
#include <d3d11.h>

class GameObject;
class SceneData;
class DrawData;
class VBObject;
class Camera;

/*class GameObject2D;
class Camera;
class TPSCamera;
struct GameData;
struct DrawData;
struct DrawData2D;
class Light;*/

class Scene
{
public:
	Scene(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance);
	virtual ~Scene();
	bool Tick();
	bool Draw(DrawData* _DD);

private:
	std::unique_ptr<Camera> m_camera;
	SceneData* m_SceneData; //Scene data;
	DrawData* m_DrawData;
	DWORD m_playTime; //Run time
	VBObject* m_vbo;
	std::vector<GameObject*> m_GameObjects;
	IDirectInput8* m_pDirectInput;
	IDirectInputDevice8* m_pKeyboard;
	IDirectInputDevice8* m_pMouse;
	unsigned char m_keyboardState[256];
	unsigned char m_previousKeyboardState[256];
	DIMOUSESTATE m_mouseState;
	HWND m_hWnd;

};

#endif