#ifndef NETINCLUDES_H
#define NETINCLUDES_H

#pragma once

#define LOCAL_IP "127.0.0.1"
#define AUTO_PORT 0


// platform detection
#define PLATFORM_WINDOWS 1
#define PLATFORM_MAC	 2
#define PLATFORM_UNIX	 3

#if defined(_WIN32)
#define PLATFORM PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define PLATFORM PLATFORM_MAC
#else
#define PLATFORM PLATFORM_UNIX
#endif

#if PLATFORM == PLATFORM_WINDOWS
#pragma comment( lib, "ws2_32.lib" ) 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
#include <sys/CSocket.h>
#include <netinet/in.h>
#include <fcntl.h>
#endif

#endif