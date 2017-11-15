#include "GraphicsHandler.h"

GraphicsHandler::GraphicsHandler()
{
	m_Direct3D = nullptr;
	m_Camera = nullptr;
	m_vbo = nullptr;
	m_shader = nullptr;
}


GraphicsHandler::GraphicsHandler(const GraphicsHandler& other)
{
}


GraphicsHandler::~GraphicsHandler()
{
}


bool GraphicsHandler::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	m_Direct3D = std::make_unique<Direct3D>();
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new Camera;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(Vector3(0.0f, 0.0f, -5.0f));

	// Create the model object.
	m_vbo = new VBObject;
	if (!m_vbo)
	{
		return false;
	}

	// Initialize the model object.
	result = m_vbo->Initialize(m_Direct3D->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize object.", L"Error", MB_OK);
		return false;
	}

	// Create the color shader object.
	m_shader = new Shader;
	if (!m_shader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_shader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the shader.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsHandler::Shutdown()
{
	// Release the color shader object.
	if (m_shader)
	{
		m_shader->Shutdown();
		delete m_shader;
		m_shader = nullptr;
	}

	// Release the model object.
	if (m_vbo)
	{
		m_vbo->Shutdown();
		delete m_vbo;
		m_vbo = nullptr;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = nullptr;
	}

	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		m_Direct3D = nullptr;
	}
	return;
}


bool GraphicsHandler::Tick()
{
	// Render the graphics scene.
	if (!Render())
	{
		return false;
	}
	return true;
}


bool GraphicsHandler::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.5f, 0.8f, 0.8f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//m_vbo->Draw(m_Direct3D->GetDeviceContext());

	// Render the model using the color shader.
	result = m_shader->Render(m_Direct3D->GetDeviceContext(), m_vbo->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();
	return true;
}