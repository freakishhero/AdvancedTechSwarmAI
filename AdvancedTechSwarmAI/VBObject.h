#pragma once
#ifndef _VBOBJECT_H_
#define _VBOJECT_H_

#include "GameObject.h"
#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;

class VBObject : GameObject
{
public:
	VBObject();
	VBObject(const VBObject&);
	~VBObject();

	virtual void Tick(std::unique_ptr<SceneData> _SD) override;
	virtual void Draw(std::unique_ptr<DrawData> _DD) override;

	bool Initialize(ID3D11Device*);
	void Shutdown();

	int GetIndexCount();

private:
	bool InitializeBuffers(ID3D11Device* _DeviceContext);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext* _DeviceContext);

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};
};

#endif