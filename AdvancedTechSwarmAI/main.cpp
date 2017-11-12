#include "SystemHandler.h"
#include <memory>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	std::unique_ptr<SystemHandler> system;
	bool result;

	//Create the system object.
	system = std::make_unique<SystemHandler>();
	if (!system)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = system->Initialize();
	if (result)
	{
		system->Run();
	}
	else 
	{
		MessageBox(0, L"Window Initialization - Failed",
			L"Error", MB_OK);
		return 0;
	}

	// Shutdown and release the system object.
	system->Shutdown();
	system = nullptr;
	return 0;
}