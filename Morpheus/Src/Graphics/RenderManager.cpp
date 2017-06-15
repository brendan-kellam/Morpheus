
#include "RenderManager.h"
#include <iostream>

// On Render manager startup

void CRenderManager::StartUp()
{
	std::cout << "Rendering manager starting.." << std::endl;
}


void CRenderManager::ShutDown()
{
	std::cout << "Rendering manager shutting down.." << std::endl;
}