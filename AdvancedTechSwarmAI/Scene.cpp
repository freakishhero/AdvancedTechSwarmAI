#include "Scene.h"
#include "Camera.h"
#include "GameObject.h"
#include "SceneData.h"
#include "DrawData.h"
#include "Vector.h"
#include "VBObject.h"
#include <windows.h>
#include <time.h>

Scene::Scene(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance)
{
	//Seed the random number generator
	srand((UINT)time(NULL));

	ID3D11DeviceContext* pd3dImmediateContext;
	_pd3dDevice->GetImmediateContext(&pd3dImmediateContext);
	m_hWnd = _hWnd;
	m_pKeyboard = nullptr;
	m_pDirectInput = nullptr;

	//HRESULT hr = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDirectInput, NULL);
	//hr = m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyboard, NULL);
	//hr = m_pKeyboard->SetDataFormat(&c_dfDIKeyboard);
	//hr = m_pKeyboard->SetCooperativeLevel(m_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	//hr = m_pDirectInput->CreateDevice(GUID_SysMouse, &m_pMouse, NULL);
	//hr = m_pMouse->SetDataFormat(&c_dfDIMouse);
	//hr = m_pMouse->SetCooperativeLevel(m_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	//create GameData struct and populate its pointers
	m_SceneData = new SceneData();
	//m_SceneData->m_keyboardState = m_keyboardState;
	//m_SceneData->m_previousKeyboardState = m_previousKeyboardState;
	m_SceneData->m_state = MAIN_MENU;
	//m_SceneData->m_mouseState = &m_mouseState;

	//create a base camera
	m_camera = std::make_unique<Camera>();
	m_camera->SetPosition(Vector3(0.0f, 0.0f, -5.0f));
	m_GameObjects.push_back(m_camera.get());

	//create DrawData struct and populate its pointers
	m_DrawData = new DrawData();
	m_DrawData->m_pd3dImmediateContext = nullptr;
	m_DrawData->m_MainCamera = m_camera.get();

	// Create the model object.
	m_vbo = new VBObject();
	m_vbo->Initialize(_pd3dDevice);
	m_GameObjects.push_back(m_vbo);
}

Scene::~Scene()
{
	// Release the model object.
	if (m_vbo)
	{
		m_vbo->Shutdown();
		delete m_vbo;
		m_vbo = nullptr;
	}

	// Release the camera object.
	if (m_camera)
	{
		m_camera = nullptr;
	}
}

bool Scene::Tick()
{
	//Check if the user pressed escape and wants to exit the application.
	//if (m_Input->IsKeyDown(VK_ESCAPE))
	//{
	//	return false;
	//}

	DWORD currentTime = GetTickCount();
	if (m_SceneData)
	{
		m_SceneData->m_deltaTime = min((float)(currentTime - m_playTime) / 1000.0f, 0.1f);
		m_playTime = currentTime;
	}

	for (auto& _game_object : m_GameObjects)
	{
		_game_object->Tick(m_SceneData);
	}

	if (!Draw(m_DrawData))
	{
		return false;
	}
	
	
	return true;
}

bool Scene::Draw(DrawData* _DD)
{
	m_DrawData->m_pd3dImmediateContext = _DD->m_pd3dImmediateContext;

	for (auto& _game_object : m_GameObjects)
	{
		_game_object->Draw(_DD);
	}

	return true;
}
