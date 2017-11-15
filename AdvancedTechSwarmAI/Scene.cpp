#include "Scene.h"
#include "GameObject.h"
#include "SceneData.h"
#include "DrawData.h"
#include "Vector.h"
#include <windows.h>
#include <time.h>

Scene::Scene(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance)
{
	//Seed the random number generator
	srand((UINT)time(NULL));

	ID3D11DeviceContext* pd3dImmediateContext;
	_pd3dDevice->GetImmediateContext(&pd3dImmediateContext);
	m_hWnd = _hWnd;
	//m_pKeyboard = nullptr;
	//m_pDirectInput = nullptr;

	//HRESULT hr = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDirectInput, NULL);
	//hr = m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyboard, NULL);
	//hr = m_pKeyboard->SetDataFormat(&c_dfDIKeyboard);
	//hr = m_pKeyboard->SetCooperativeLevel(m_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	//hr = m_pDirectInput->CreateDevice(GUID_SysMouse, &m_pMouse, NULL);
	//hr = m_pMouse->SetDataFormat(&c_dfDIMouse);
	//hr = m_pMouse->SetCooperativeLevel(m_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	//create GameData struct and populate its pointers
	//m_SceneData = std::make_unique<SceneData>();
	//m_SceneData->m_keyboardState = m_keyboardState;
	////m_SceneData->m_previousKeyboardState = m_previousKeyboardState;
	//m_SceneData->m_state = MAIN_MENU;
	//m_SceneData->m_mouseState = &m_mouseState;

	//create a base camera
	//m_camera = std::make_unique<Camera>(0.25f * XM_PI, AR, 1.0f, 10000.0f, Vector3::UnitY, Vector3(0,0,0));
	m_camera = std::make_unique<Camera>();
	m_camera->SetPosition(Vector3(0, 0, 0));
	m_GameObjects.push_back(m_camera.get());

	//create DrawData struct and populate its pointers
	m_DrawData = std::make_unique<DrawData>();
	m_DrawData->m_pd3dImmediateContext = nullptr;
	//m_DrawData->m_MainCamera = m_camera;

}

Scene::~Scene()
{
}

bool Scene::Tick()
{
	DWORD currentTime = GetTickCount();
	m_SceneData->m_deltaTime = min((float)(currentTime - m_playTime) / 1000.0f, 0.1f);
	m_playTime = currentTime;

	for (auto& _game_object : m_GameObjects)
	{
		//_game_object->Tick(m_SceneData);
	}
}

void Scene::Draw()
{
}
