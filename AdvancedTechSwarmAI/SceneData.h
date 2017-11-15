#ifndef _SCENE_DATA_H_
#define _SCENE_DATA_H_

#include <dinput.h>
#include "States.h"

struct SceneData
{
	float m_deltaTime; //deltatime - time between frames
	State m_state; //current state of simulation

	//Input
	unsigned char* m_keyboardState;
	unsigned char* m_previousKeyboardState;
	DIMOUSESTATE* m_mouseState;
};

#endif