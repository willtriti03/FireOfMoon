#pragma once
#define TimeMgr Timer::GetInstance()

class Timer
{
	float m_time = 0;
	int time;
	int frame = 0;
	int nowFrame;
public:
	Timer();
	~Timer();

	float GetTime(){ return m_time+time; };
	int GetFrame(){ return nowFrame; };

	void Update(float eTime);
	
	bool Wait(int time);
	static Timer* GetInstance(){ static Timer Instance; return &Instance; };
};

