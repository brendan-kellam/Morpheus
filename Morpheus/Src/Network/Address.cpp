
#include "Address.h"


CAddress::CAddress() : CAddress(127, 0, 0, 1, AUTO_PORT)
{ }

CAddress::CAddress(unsigned short port) : CAddress(127, 0, 0, 1, port)
{ }


CAddress::CAddress(
	unsigned char a,
	unsigned char b,
	unsigned char c,
	unsigned char d,
	unsigned short port) : m_a(a), m_b(b), m_c(c), m_d(d), m_port(port)
{

	m_address = (m_a << 24) |
				(m_b << 16) |
				(m_c << 8)  |
				 m_d;

	InitializeAddress();
}

CAddress::CAddress(unsigned int address, unsigned short port) : m_address(address), m_port(port)
{
	InitializeAddress();
}

void CAddress::InitializeAddress() const
{
	m_addrStruct.sin_family = AF_INET;
	m_addrStruct.sin_addr.s_addr = htonl(m_address);
	m_addrStruct.sin_port = htons(m_port);
}


unsigned int CAddress::GetAddress() const
{
	return m_address;
}

const sockaddr* CAddress::GetAddrStruct() const
{
	return (const struct sockaddr*) &m_addrStruct;
}

unsigned char CAddress::GetA() const
{
	return m_a;
}

unsigned char CAddress::GetB() const
{
	return m_b;
}

unsigned char CAddress::GetC() const
{
	return m_c;
}

unsigned char CAddress::GetD() const
{
	return m_d;
}

unsigned short CAddress::GetPort() const
{
	return m_port;
}