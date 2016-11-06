#include"CSound.h"

FMOD_SYSTEM* CSound::g_System;

CSound::CSound(char* path, bool isInfinite){
	if (isInfinite == true)
		FMOD_System_CreateSound(g_System, path, FMOD_LOOP_NORMAL, 0, &sound);
	else
		FMOD_System_CreateSound(g_System, path, FMOD_DEFAULT, 0, &sound);
	
}
CSound::~CSound(){
	FMOD_Sound_Release(sound);
}
void CSound::s_Init(){
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);
}
void CSound::s_Destroy(){
	
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void CSound::Pause(){	
	FMOD_Channel_SetPaused(channel, true);
}
void CSound::Resume(){
	FMOD_Channel_SetPaused(channel, false);
}
void CSound::Play(){
	FMOD_System_PlaySound(g_System, sound, NULL, false, &channel);		
}
void CSound::Stop(){
	FMOD_Channel_Stop(channel);
}
void CSound::volumeUp(){
	if (volume >= 1.0f){
	}
	else{
		volume += 0.1f;
	}
	FMOD_Channel_SetVolume(channel, volume);
}
void CSound::volumeDown(){
	if (volume <= 0.0f){
	}
	else{
		volume -= 0.1f;
	}
	FMOD_Channel_SetVolume(channel, volume);
}
void CSound::update(float eTime){
	FMOD_Channel_IsPlaying(channel, &isPlaying);
	if (isPlaying == 1)
		FMOD_System_Update(g_System);
}
void CSound::Render(){

}