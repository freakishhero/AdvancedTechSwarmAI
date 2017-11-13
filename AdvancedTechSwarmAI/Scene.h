#ifndef _SCENE_H
#define _SCENE_H_

#include <windows.h>
#include <dinput.h>
#include <memory>
#include <vector>

class GameObject;
class SceneData;

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
	Scene();
	virtual ~Scene();
	bool Tick();
	void Draw();

protected:
	SceneData* m_SceneData;
	//std::vector<GameObject> m_GameObjects;
private:

};

#endif