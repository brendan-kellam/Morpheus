
#ifndef NETWORKMANAGER_H 
#define NETWORKMANAGER_H
#pragma once

#include "iostream"
#include "Socket.h"
#include "Address.h"

#define PORT 30000



class CNetworkManager
{

public:

	static CNetworkManager& GetInstance()
	{
		static CNetworkManager instance;
		return instance;
	}


	// Enforce singleton pattern
	CNetworkManager(CNetworkManager const&)				= delete; // Copy constructor
	CNetworkManager(CNetworkManager&&)				    = delete; // Move constructor
	CNetworkManager& operator=(CNetworkManager const&)	= delete; // Copy assign
	CNetworkManager& operator=(CNetworkManager&&)		= delete; // Move assign 

	bool Init() const;

private:
	CNetworkManager() { };
};

#endif