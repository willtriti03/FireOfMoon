#ifndef _CCLIENT_H_
#define _CCLIENT_H_

#include"CSocket.h"
#include<process.h>
#include<queue>
#include<thread>

#define CCLIENT_NO_MORE_DATA -1	//버퍼에서 읽어들일거 없으면 요거 리턴

class ThreadClass{
private:
protected:
	std::thread *thread = NULL;
public:
	ThreadClass(){}
	virtual ~ThreadClass(){
		if (thread != NULL){
			if (thread->joinable()) { thread->join(); }
			delete thread;
		}
	}

	void start(){ thread = new std::thread(&ThreadClass::run, this); }
	void stop(){}

	virtual void run(){}
};

class CClient : public ThreadClass, CSocket{
private:
	boolean closed = false;

	//서버와 연결울 위한 변수
	SOCKET sock;
	SOCKADDR_IN serverAddr;

	//데이터 버퍼(큐)
	std::queue<CSocket::DATA *> dataQueue;

	void run();

protected:
public:
	CClient(std::string serverIP, int serverPort);//서버 ip,서버 포트
	virtual ~CClient();

	int write(int code, char *data);	//데이터 전송
	int read(int *code, char *data);		//데이터 읽기(버퍼에서)

	int closeSocket();
};

#endif