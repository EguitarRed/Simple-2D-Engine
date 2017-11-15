#include "Sound.h"
#include <assert.h>

CSound::CSound(std::string Filename)
	: m_Filename(Filename)
	, m_Sound(NULL)
{
	m_Sound = Mix_LoadWAV(Filename.c_str());
	assert(m_Sound);
}

CSound::~CSound()
{
	CHECKED_DELETE_SOUND(m_Sound);
}

void CSound::Play()
{
	Mix_PlayChannel(-1, m_Sound, 0);
}