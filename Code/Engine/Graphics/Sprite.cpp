#include "Sprite.h"
#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "SDL.h"
#include "SDL_Image.h"
#include <string>
#include "assert.h"

CSprite::CSprite(std::string Filename, SDL_Renderer* pRenderer)
	: m_pImage(NULL)
	, m_Filename(Filename)
	, m_pRenderer(pRenderer)
{
	assert(pRenderer);
	SDL_Surface* l_temp = IMG_Load(Filename.c_str()); 
	assert(l_temp);
	m_pImage = SDL_CreateTextureFromSurface(pRenderer, l_temp);
	assert(m_pImage);
	CHECKED_DELETE_SURFACE(l_temp);
	m_r = 255;
	m_g = 255;
	m_b = 255;	
}
	
CSprite::~CSprite()
{
	CHECKED_DELETE_TEXTURE(m_pImage);
}

void CSprite::Render(int32 posx, int32 posy, int32 width, int32 height)
{
	SDL_Rect l_dest = {posx,posy,width,height};	
	SDL_SetTextureColorMod(m_pImage, m_r, m_g, m_b);
	SDL_RenderCopy(m_pRenderer, m_pImage, NULL, &l_dest);
}