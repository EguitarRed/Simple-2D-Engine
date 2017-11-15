#include "SpriteManager.h"
#include "Sprite.h"
#include <string>

CSpriteManager::~CSpriteManager()
{
	Destroy();
}

void CSpriteManager::LoadSprite(std::string Filename, SDL_Renderer* pRenderer)
{
	CSprite* sprite = new CSprite(m_Path + Filename, pRenderer);
	AddResource(Filename.c_str(), sprite);
}

void CSpriteManager::SetColor(const uint8 r,const uint8 g,const uint8 b)
{
	TMapResource::iterator l_it = m_Resources.begin();
	for(; l_it != m_Resources.end(); ++l_it)
	{
		l_it->second->SetColor(r,g,b);
	}
}