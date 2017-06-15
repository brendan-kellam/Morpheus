#ifndef Socket_H
#define Socket_H

#pragma once

#include "NetIncludes.h"
#include "Address.h"
#include <iostream>
#include <exception>

class CSocket
{
public:
	
	CSocket();
	~CSocket();
	
	bool Open(unsigned short port, bool broadcastPublically = false);
	void Close();
	bool IsOpen() const; 

	bool Send(const CAddress& destination, const void* data, int size);
	int  Receive(CAddress& sender, void* data, int size);

	//bool Sendall(const CAddress& sendto, const void* data, int totalbytes);
	//bool Recvall(const CAddress& sentfrom, void* data, int size);


private:
	int m_handle;	  // SOCKET
	sockaddr_in addr;
	int addrlen = sizeof(addr);
};

#endif

