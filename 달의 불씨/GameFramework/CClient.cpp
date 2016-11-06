#include"stdafx.h"
#include"CClient.h"

CClient::CClient(std::string serverIP, int serverPort){
	//소켓 초기화
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET){
		getErrorMessage();
		exit(0);
	}

	ZeroMemory(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());
	serverAddr.sin_port = htons(serverPort);

	/*
	int optval = 3000;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)optval, sizeof(optval)) == SOCKET_ERROR){
	getErrorMessage();
	exit(0);
	}
	*/

	//서버와 연결
	if (connect(sock, (SOCKADDR *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR){
		getErrorMessage();
		exit(0);
	}

	//읽기 쓰레드 생성
	start();

}
CClient::~CClient(){
	//쓰레드 함수 자원 반납
	stop();

	if (!closed){
		closeSocket();
	}

	//delete 용
	CSocket::DATA* dat;
	while (dataQueue.size() <= 0){
		dat = dataQueue.front();
		dataQueue.pop();
		delete dat;
	}
}

void CClient::run(){
	while (true){
		DATA read;

		if (readData(sock, (char *)&read, sizeof(read), 0) < 0){	//데이터를 읽어 들임
			getErrorMessage();//서버가 이상
			exit(0);
		}

		//버퍼에 넣을거
		DATA *dat = new DATA;
		dat->code = read.code;
		strcpy(dat->data, read.data);
		//std::cout << "읽음" << dat->code << "/" << dat->data << std::endl;

		dataQueue.push(dat);	//버퍼에 추가
	}
}
int CClient::write(int code, char *data){
	CSocket::DATA dat;

	if (data[strlen(data) - 1] == '\n')
		data[strlen(data) - 1] = '\0';

	dat.code = code;
	strcpy(dat.data, data);

	if (sendData(sock, (char *)&dat, sizeof(dat), 0) < 0){//데이터를 보냄
		getErrorMessage();	//이 클라 소켓이 이상
		exit(0);
	}

	//std::cout << "보냄" << dat.code << "/" << dat.data << std::endl;

	return strlen(data);
}
int CClient::read(int *code, char *data){
	if (dataQueue.size() <= 0){//버퍼에 데이타가 없는가?
		*code = CCLIENT_NO_MORE_DATA;
		strcpy(data, "");
		return 0;
	}

	CSocket::DATA* dat = dataQueue.front();//데이터 꺼내옴

	*code = dat->code;
	strcpy(data, dat->data);

	//std::cout << "호출" << dat->code << "/" << dat->data << std::endl;

	dataQueue.pop();
	delete dat;

	return strlen(dat->data);
}

int CClient::closeSocket(){
	closesocket(sock);
	closed = true;
	return 0;
}