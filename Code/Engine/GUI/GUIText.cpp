#include "GUIText.h"
#include <assert.h>


CGUIText::CGUIText(SDL_Renderer* pRenderer, std::string Text)
	: m_Text(Text)	
	, m_FontSize(12)
	, m_FontStyle(TTF_STYLE_NORMAL)
	, m_pRenderer(pRenderer)
	, m_FontFilename(DEFAULT_FONT_FILE)
{
	//Init Colors
	SDL_Color l_tmp = {255,255,255,255};
	m_TextColor = l_tmp;
	SDL_Color l_tmp2 = {0,0,0,0};
	m_BackColor = l_tmp2;

	//Create Font
	m_SDLFont = TTF_OpenFont( m_FontFilename.c_str(), m_FontSize);
	assert(m_SDLFont);

	//Init Texture to render
	SDL_Surface* l_surface = TTF_RenderText_Solid(m_SDLFont, m_Text.c_str(), m_TextColor);
	assert(l_surface);
	m_TextTexture = SDL_CreateTextureFromSurface(pRenderer, l_surface);
	assert(m_TextTexture);
	m_Width = float(l_surface->w);
	m_Height = float(l_surface->h);
	CHECKED_DELETE_SURFACE(l_surface);
}

CGUIText::~CGUIText()
{
	CHECKED_DELETE_TEXTURE(m_TextTexture);
	CHECKED_DELETE_FONT(m_SDLFont);	
}


void CGUIText::UpdateTexture()
{
	//Update Texture to Render	
	CHECKED_DELETE_TEXTURE(m_TextTexture);
	SDL_Surface* l_surface = TTF_RenderText_Solid(m_SDLFont, m_Text.c_str(), m_TextColor);
	assert(l_surface);
	m_TextTexture = SDL_CreateTextureFromSurface(m_pRenderer, l_surface);
	assert(m_TextTexture);
	m_Width = float(l_surface->w);
	m_Height = float(l_surface->h);
	CHECKED_DELETE_SURFACE(l_surface);
}

void CGUIText::SetText(const std::string Text)
{
	if (Text != m_Text)
	{
		m_Text = Text;
		UpdateTexture();	
	}
}

void CGUIText::SetFontSize(const int32 Size)
{
	m_FontSize = Size;
	CHECKED_DELETE_FONT(m_SDLFont);
	m_SDLFont = TTF_OpenFont( m_FontFilename.c_str(), m_FontSize);
	TTF_SetFontStyle(m_SDLFont, m_FontStyle);
	UpdateTexture();
}

void CGUIText::SetBold(bool bold)
{
	if (bold)
	{
		if (m_FontStyle != TTF_STYLE_BOLD)
		{
			m_FontStyle = TTF_STYLE_BOLD;
			TTF_SetFontStyle(m_SDLFont, m_FontStyle);
			UpdateTexture();
		}
	}
	else
	{
		if (m_FontStyle != TTF_STYLE_NORMAL)
		{
			m_FontStyle = TTF_STYLE_NORMAL;
			TTF_SetFontStyle(m_SDLFont, m_FontStyle);
			UpdateTexture();
		}
	}
	
}

void CGUIText::Render()
{
	if (m_bVisible)
	{		
		SDL_Rect l_dest = {int32(m_x), int32(m_y), int32(m_Width), int32(m_Height)};
		SDL_RenderCopy(m_pRenderer, m_TextTexture, NULL, &l_dest);
	}
}