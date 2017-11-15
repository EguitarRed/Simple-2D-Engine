#pragma once
#ifndef _GUITEXT_H_
#define _GUITEXT_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "GUIElement.h"
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_pixels.h"

class CGUIText : public CGUIElement
{
protected:
	std::string		m_Text;
	std::string		m_FontFilename;
	TTF_Font*		m_SDLFont;
	SDL_Color		m_TextColor;
	SDL_Color		m_BackColor;
	int32			m_FontSize;
	int32			m_FontStyle;
	SDL_Texture*	m_TextTexture;
	SDL_Renderer*	m_pRenderer;	

	void			UpdateTexture();

public:
	CGUIText(SDL_Renderer* pRenderer, std::string Text);
	~CGUIText();

	std::string		GetText() const {return m_Text;}
	void			SetText(const std::string Text);

	int32			GetFontSize() const {return m_FontSize;}
	void			SetFontSize(const int32 Size);

	bool			IsFontBold() const {return m_FontStyle == TTF_STYLE_BOLD;}
	void			SetBold(bool bold); 
	
	virtual void Render();
};

#endif