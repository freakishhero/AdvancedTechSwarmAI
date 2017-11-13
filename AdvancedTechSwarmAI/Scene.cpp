#include "Scene.h"
#include <windows.h>
#include <time.h>

Scene::Scene()
{
	//Seed the random number generator
	srand((UINT)time(NULL));
}

Scene::~Scene()
{
}

bool Scene::Tick()
{
	return false;
}

void Scene::Draw()
{
}
