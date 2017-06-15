
#include "NetworkManager.h"

bool CNetworkManager::Init() const 
{

	const int port = 0;
	CSocket socket;

	if (!socket.Open(port))
	{
		std::cout << "ERROR: Function(CNetworkManager::Init) - Failed to create socket" << std::endl;
		return false;
	}

	const char data[] = "Hello there!";
	
	socket.Send(CAddress(), data, sizeof(data));

	CAddress sender;
	unsigned char buffer[256];
	while (true)
	{	
		int bytes_read = socket.Receive(sender, buffer, sizeof(buffer));

		if (!bytes_read)
		{
			std::cout << buffer << std::endl;
			break;
		}
	}


	return true;
}



