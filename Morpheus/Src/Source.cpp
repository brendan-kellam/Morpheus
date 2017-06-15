#include <Windows.h>

#include <SDL/SDL.h> // Note: SDL owns the main function!
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Graphics/RenderManager.h"
#include "Core/Debug/LogManager.h"

#include "Engine.h"


/*
Notes:
- Game loop -
-> "Runs the game at a consistent speed despite differences in the underlying hardware"
-> Game loop is where most of the processing occurs, and therefore must be efficient!
-> A "fluid game loop" takes time steps in relation to how much real time has passed since the last frame. (GPP 129)
	-> Alas, this creates a non-deterministic game... (due to rounding error with floating points)
-> Note: Rendering is not affected by variable time step: The rendering will want to run as fast as it can!
*/

// --- MANAGERS ---
CRenderManager gRenderManager;


int main(int argc, char** argv)
{
	
	CLogManager::Instance().StartUp();
	CRenderManager::Instance().StartUp();


	// .. do stuff ..


	CRenderManager::Instance().ShutDown();
	CLogManager::Instance().ShutDown();

	system("pause");


	return 0;
}