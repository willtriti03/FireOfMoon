#include"stdafx.h"
#include"CSocket.h"

WSAData CSocket::wsaDat;

int CSocket::WSAStart(){
	if (WSAStartup(MAKEWORD(2, 2), &wsaDat) != 0){
		return SOCKET_ERROR;
	}

	return 0;
}

int CSocket::WSAClose(){
	WSACleanup();

	return 0;
}

int CSocket::getErrorMessage(){
	LPVOID message;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&message, 0, NULL);
	MessageBox(NULL, (LPCTSTR)message, nullptr, MB_ICONERROR);
	LocalFree(message);

	return WSAGetLastError();
}

std::string CSocket::getIpAddr(std::string domainName){
	HOSTENT *ptr = gethostbyname(domainName.c_str());
	IN_ADDR addr;
	if (ptr == NULL)
		return nullptr;
	if (ptr->h_addrtype != AF_INET)
		return nullptr;

	memcpy(&addr, ptr->h_addr, ptr->h_length);

	return inet_ntoa(addr);
}

int CSocket::sendData(SOCKET socket, char *data, int length, int flags){
	int result;

	/*
	if ((result = send(socket, (char *)&length, sizeof(int), flags)) == SOCKET_ERROR){
	return SOCKET_ERROR;
	}
	if ((result = send(socket, data, length, flags)) == SOCKET_ERROR){
	return SOCKET_ERROR;
	}
	*/
	if ((result = send(socket, data, length, flags)) == SOCKET_ERROR){
		return SOCKET_ERROR;
	}

	return result;
}

int CSocket::readData(SOCKET socket, char *data, int length, int flags){
	int result;

	/*
	if (recv(socket, (char *)&result, sizeof(int), flags) == SOCKET_ERROR){
	return SOCKET_ERROR;
	}
	if ((result = recv(socket, data, result, flags)) == SOCKET_ERROR){
	return SOCKET_ERROR;
	}
	*/
	if ((result = recv(socket, data, length, flags)) == SOCKET_ERROR){
		return SOCKET_ERROR;
	}

	return result;
}

int CSocket::sendDataUDP(SOCKET socket, char *data, int length, int flags, SOCKADDR *to, int *tolen){
	return 0;
}

int CSocket::readDataUDP(SOCKET socket, char *data, int length, int flags, SOCKADDR *from, int *fromlen){
	return 0;
}