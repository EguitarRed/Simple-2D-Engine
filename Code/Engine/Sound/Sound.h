#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include <string>
#include "SDL_mixer.h"

class CSound
{
private:
	std::string		m_Filename;
	Mix_Chunk*		m_Sound;

public:
	CSound(std::string Filename);
	~CSound();

	void Play();
};

#endif