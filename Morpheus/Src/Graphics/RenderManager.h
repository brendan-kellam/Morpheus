#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#pragma once

#include "Engine.h"
#include "Core/Util/Singleton.h"
#include "Core/Util/Interfaces.h"

class CRenderManager
	: public CSingleton<CRenderManager>, public Interface::IManager
{

public:
	void StartUp()  override;
	void ShutDown() override;

};





#endif

