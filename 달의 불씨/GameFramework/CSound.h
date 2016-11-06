#pragma once
#ifndef _CSOUND_H_
#define _CSOUND_H_

#include"ISceneNode.h"
#include <fmod.hpp>
#include <fmod_errors.h>
#pragma  comment( lib, "fmod_vc.lib" )
class CSound : public ISceneNode{
	static FMOD_SYSTEM *g_System;
	FMOD_SOUND *sound;

	FMOD_CHANNEL *channel;
	float volume = 0.5f;
	FMOD_BOOL isPlaying;
public:
	CSound(char* path, bool isInfinite);
	~CSound();

	static void s_Init();
	static void s_Destroy();

	void Pause();
	void Resume();
	void Play();
	void Stop();
	void volumeUp();
	void volumeDown();
	void update(float eTime);
	void Render();
};

#endif