#include "Socket.h"

CSocket::CSocket()
{
	
	#if PLATFORM == PLATFORM_WINDOWS
		
		// Winsock startup
		WSADATA WsaData;
		WORD DllVersion = MAKEWORD(2, 1);
	
		// If error occurs during WSAStartup
		if (WSAStartup(DllVersion, &WsaData) != NO_ERROR)
		{
			throw std::logic_error("ERROR: CSocket constructor - Unable to initialize socket layer");
		}
	#endif
}

CSocket::~CSocket()
{

}

bool CSocket::Open(unsigned short port, bool broadcastPublically)
{

	if (broadcastPublically)
	{
		addr.sin_addr.s_addr = htonl(INADDR_ANY); // Broadcast publically [Host to Network long]
	}
	else
	{
		addr.sin_addr.s_addr = inet_addr(LOCAL_IP);
	}

	addr.sin_port = htons(port); // Port
	addr.sin_family = AF_INET;   // IPv4 socket


	// Create new UDP socket
	m_handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (m_handle <= 0)
	{
		std::cout << "ERROR: Function(CSocket::Open) - Unable to create UDP socket" << std::endl;
		return false;
	}

	// bind address to socket
	if (bind(m_handle, (const sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		std::cout << "ERROR: Function(CSocket::Open) - Unable to bind UDP socket to port: " << port << std::endl;
		return false;
	}

	// Non-blocking for osx/unix
	#if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX

		int nonBlocking = 1;
		if (fcntl(handle, F_SETFL, O_NONBLOCK, nonBlocking) == -1)
		{
			std::cout << "ERROR: Function(CSocket::Open) - Failed to set non-blocking for UNIX/OSX platforms" << std::endl;
			return false;
		}

	// Non-blocking for windows
	#elif PLATFORM == PLATFORM_WINDOWS

		DWORD nonBlocking = 1;
		if (ioctlsocket(m_handle, FIONBIO, &nonBlocking) != 0)
		{
			std::cout << "ERROR: Function(CSocket::Open) - Failed to set non-blocking for WINDOWS platform" << std::endl;
			return false;
		}
	#endif
	
	return true;
}

void CSocket::Close()
{
#if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
	close(socket);
#elif PLATFORM == PLATFORM_WINDOWS

	WSACleanup();
	closesocket(m_handle);
#endif

}

bool CSocket::IsOpen() const
{
	char buf;
	int err = recv(m_handle, &buf, 1, MSG_PEEK);
	if (err == SOCKET_ERROR)
	{
		return false;
	}
	return true;
}

bool CSocket::Send(const CAddress& destination, const void* data, int size)
{
	int sentBytes = sendto(m_handle, 
		(const char*) data, 
		size, 
		0, 
		destination.GetAddrStruct(), 
		sizeof(sockaddr_in));

	if (sentBytes != size)
	{
		std::cout << "ERROR: Function(CSocket::Send) - Failed to send packet" << std::endl;
		return false;
	}

	return true;
}

int CSocket::Receive(CAddress& sender, void* data, int size)
{

	while (true)
	{
		unsigned int maxPacketSize = sizeof(data);

	#if PLATFORM == PLATFORM_WINDOWS
		using socklen_t = int;
	#endif
		
		sockaddr_in from;
		socklen_t fromLength = sizeof(from);

		int bytes = recvfrom(m_handle,
			(char*)data,
			maxPacketSize,
			0,
			(sockaddr*)&from,
			&fromLength);

		if (bytes <= 0)
			break;

		unsigned int from_address = ntohl(from.sin_addr.s_addr);
		unsigned int from_port	  = ntohs(from.sin_port);
	}

	return true;
}

/*
bool CSocket::Sendall(const CAddress& destination, const void* data, int totalbytes)
{
	int bytessent = 0; // Total # of bytes sent

	while (bytessent < totalbytes) {
		
		// Send data over socket
		int RetnCheck = sendto(, data + bytessent, totalbytes - bytessent, NULL);

		if (RetnCheck == SOCKET_ERROR) // If there was a connection issues
			return false;

		else if (RetnCheck == 0) // If we don't recieve any bytes 
			return false;

		bytessent += RetnCheck;
	}


	return true;
}
*/