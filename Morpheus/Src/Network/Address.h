#ifndef ADDRESS_H
#define ADDRESS_H

#pragma once
#include "NetIncludes.h"


/*
* CAddress: Wrapper to describe a remote destination.
* Can be passed to a CSocket send function to send packets to address stored
* Note: you can cast sockaddr_in* to sockaddr*
*/

class CAddress
{
public: 

	CAddress();
	
	CAddress(unsigned short port);

	CAddress( unsigned char a,
			  unsigned char b,
		      unsigned char c,
			  unsigned char d,
			  unsigned short port);
	
	CAddress( unsigned int address,
			  unsigned short port );

	unsigned int GetAddress() const;
	const sockaddr* GetAddrStruct() const;
	unsigned char GetA() const;
	unsigned char GetB() const;
	unsigned char GetC() const;
	unsigned char GetD() const;
	unsigned short GetPort() const;

private:

	virtual void InitializeAddress() const;

	unsigned int m_address;
	unsigned short m_port;

	mutable sockaddr_in m_addrStruct;

	unsigned int m_a, m_b, m_c, m_d;

	

};

#endif
