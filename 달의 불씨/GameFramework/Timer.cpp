#include "Timer.h"
#include <stdio.h>

Timer::Timer()
{
}


Timer::~Timer()
{
}
void Timer::Update(float eTime){
	m_time += eTime;
	frame++;
	if (m_time >= 1){
		time++;
		m_time -= 1;
		nowFrame = frame;
		frame = 0;
	}
	
}

bool Timer::Wait(int time){
	int limit = this->time + time; 
	while (this->time <= limit)printf("sada");
	return true;
}