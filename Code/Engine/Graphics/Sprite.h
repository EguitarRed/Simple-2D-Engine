#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "..\Base\Types.h"
#include "SDL.h"
#include <string>

class CSprite
{
protected:
	SDL_Texture*	m_pImage;
	std::string		m_Filename;
	SDL_Renderer*   m_pRenderer;
	uint8			m_r,m_g,m_b;

public:
	CSprite(std::string Filename, SDL_Renderer* pRenderer);
	~CSprite();

	std::string		GetFilename() {return m_Filename;}
	SDL_Texture*	GetImage() {return m_pImage;}	
	void			SetColor(const uint8 r,const uint8 g,const uint8 b){m_r=r;m_g=g;m_b=b;}

	virtual void	Render(int32 posx, int32 posy, int32 width, int32 height);
};

#endif