#pragma once
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "SDL.h"
#include <string>

class CBackground
{
protected:
	SDL_Texture*	m_pImage;
	std::string		m_Filename;
	SDL_Renderer*   m_pRenderer;
	int32			m_x,m_y;
	int32			m_Width;
	int32			m_Height;
	uint8			m_r,m_g,m_b;

public:
	CBackground(std::string Filename, SDL_Renderer* pRenderer, int32 Width, int32 Height);
	~CBackground();

	std::string		GetFilename() {return m_Filename;}
	SDL_Texture*	GetImage() const {return m_pImage;}	
	int32	GetX() const {return m_x;}
	int32	GetY() const {return m_y;}	
	int32	GetWidth() const {return m_Width;}
	int32	GetHeight() const {return m_Height;}
	void	SetX(const int32 x) {m_x = x;}
	void	SetY(const int32 y) {m_y = y;}	
	void	SetWidth(const int32 Width) {m_Width = Width;}
	void	SetHeight(const int32 Height) {m_Height = Height;}
	void	SetPosition(const int32 x,const int32 y) {m_x = x; m_y = y;}	
	void	SetSize(const int32 Width, const int32 Height) {m_Width = Width; m_Height = Height;}
	void	SetBounds(const int32 x,const int32 y, const int32 Width, const int32 Height);
	void	SetColor(const uint8 r,const uint8 g,const uint8 b){m_r=r;m_g=g;m_b=b;}

	virtual void	Render();
};

#endif