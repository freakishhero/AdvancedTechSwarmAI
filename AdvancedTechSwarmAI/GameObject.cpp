#include "GameObject.h"
#include "SceneData.h"

GameObject::GameObject()
{
	m_position = Vector3(0, 0, 0);
	m_yaw = 0.0f;
	m_pitch = 0.0f;
	m_roll = 0.0f;
	m_scale = Vector3(1, 1, 1);

	m_world_matrix = XMMATRIX(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);

	m_fudge = XMMATRIX(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);
}

GameObject::~GameObject()
{
}

void GameObject::Tick(std::unique_ptr<SceneData> _SD)
{
	if (m_applyPhysics)
	{
		Vector3 _new_velocity = m_velocity + (m_acceleration - m_velocity * m_drag) * _SD->m_deltaTime;
		Vector3 _new_position = m_position + m_velocity * _SD->m_deltaTime;

		m_velocity = _new_velocity;
		m_position = _new_position;
	}
}
