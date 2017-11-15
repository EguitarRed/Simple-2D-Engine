#include "Background.h"
#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "SDL.h"
#include "SDL_Image.h"
#include <string>
#include "assert.h"

CBackground::CBackground(std::string Filename, SDL_Renderer* pRenderer, int32 Width, int32 Height)
	: m_x(0)
	, m_y(0)
	, m_Width(Width)
	, m_Height(Height)
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

CBackground::~CBackground()
{
	CHECKED_DELETE_TEXTURE(m_pImage);
}

void CBackground::Render()
{
	//SDL_Rect l_dest;

	//l_dest.x = m_x;
	//l_dest.y = m_y;
	//l_dest.w = m_Width;
	//l_dest.h = m_Height;
	SDL_SetTextureColorMod(m_pImage, m_r, m_g, m_b);
	SDL_RenderCopy(m_pRenderer, m_pImage, NULL, NULL);
	
}