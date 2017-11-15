#pragma once
#ifndef _SPRITEMANAGER_H_
#define _SPRITEMANAGER_H_

#include "..\Base\Base.h"
#include "..\Base\MapManager.h"
#include "Sprite.h"
#include <string>

class CSpriteManager : public CMapManager<CSprite>
{
private:
	std::string m_Path;

public:	
	CSpriteManager(std::string Path=".\\Images\\"):m_Path(Path){}
	~CSpriteManager();

	void		LoadSprite(std::string Filename, SDL_Renderer* pRenderer);
	std::string GetPath() const {return m_Path;}
	void		SetPath(const std::string Path) {m_Path = Path;}
	void		SetColor(const uint8 r,const uint8 g,const uint8 b);
};


#endif