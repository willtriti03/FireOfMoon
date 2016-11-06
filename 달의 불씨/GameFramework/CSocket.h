#ifndef _CSOCKET_H_
#define _CSOCKET_H_

#include"Application.h"

#include<string>
#define BUFSIZ 512

class CSocket{
private:
	static WSAData wsaDat;
protected:
	static int sendData(SOCKET socket, char *data, int length, int flags = 0);
	static int readData(SOCKET socket, char *data, int length, int flags = 0);
	static int sendDataUDP(SOCKET socket, char *data, int length, int flags, SOCKADDR *to, int *tolen);
	static int readDataUDP(SOCKET socket, char *data, int length, int flags, SOCKADDR *from, int *fromlen);
public:
	struct DATA{
		int code;
		char data[BUFSIZ];
	};

	static int WSAStart();//WSAStartup
	static int WSAClose();//WSAClose

	static int getErrorMessage();//WSAGetLastError값 리턴, MessageBox로 에러원인 출력
	static std::string getIpAddr(std::string domainName);//도메인명 -> IP
};

#endif