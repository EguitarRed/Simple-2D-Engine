#include "SoundManager.h"
#include "Sound.h"

CSoundManager::~CSoundManager()
{
	Destroy();
}

void CSoundManager::LoadSound(std::string Filename)
{
	CSound* l_sound = new CSound(m_Path+Filename);
	AddResource(Filename.c_str(), l_sound);
}

void CSoundManager::PlaySound(std::string Filename)
{
	CSound* l_sound = getResource(Filename.c_str());
	if (l_sound != NULL)
	{
		l_sound->Play();
	}
}