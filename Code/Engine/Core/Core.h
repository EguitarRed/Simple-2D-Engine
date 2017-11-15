#pragma once
#ifndef _CORE_H_
#define _CORE_H_

#include "..\Base\Types.h"
#include "..\Base\Base.h"
#include "..\Base\Singleton.h"
#include <string>
#include "SDL.h"

//*** Forward declarations ***
class CSpriteManager;
class CObject2DManager;
class CBackground;
class CGUIManager;
class CSoundManager;
class CParticleManager;
//****************************

class CCore : public CSingleton<CCore>
{
private:
	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;	

	CBackground*		m_pBackground;
	CSpriteManager*		m_pSpriteManager;
	CObject2DManager*	m_pObject2DManager;
	CGUIManager*		m_pGUIManager;
	CSoundManager*		m_pSoundManager;
	CParticleManager*	m_pParticleManager;

public:
	CCore()
		: m_pWindow(NULL)
		, m_pRenderer(NULL)
		, m_pSpriteManager(NULL)
	{}

	~CCore();

	void Init(	std::string sWindowName		=DEFAULT_WINDOW_NAME, 
				int32 width					=DEFAULT_HRES,
				int32 height				=DEFAULT_VRES,
				std::string BackgroundFile	=DEFAULT_BACKGROUND);

	SDL_Window*		GetWindow()		{return m_pWindow;}
	SDL_Renderer*	GetRenderer()	{return m_pRenderer;}

	void			BeginRender();
	void			EndRender();

	CSpriteManager*		GetSpriteManager()		{return m_pSpriteManager;}
	CObject2DManager*	GetObject2DManager()	{return m_pObject2DManager;}
	CBackground*		GetBackground()			{return m_pBackground;}	
	CGUIManager*		GetGUIManager() 		{return m_pGUIManager;}
	CSoundManager*		GetSoundManager()		{return m_pSoundManager;}
	CParticleManager*	GetParticleManager()	{return m_pParticleManager;}
};

#endif