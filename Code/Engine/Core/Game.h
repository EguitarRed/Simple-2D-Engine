#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "..\Base\Base.h"
#include "Core.h"
#include "SDL.h"

class CGame
{
protected:
	CCore* m_pCore;

public:
	CGame(){ m_pCore = new CCore();}
	~CGame(){ CHECKED_DELETE(m_pCore);}

	virtual void Init()=0;	
	virtual void ManageEvent(const SDL_Event* e)=0;
	virtual void Update()=0;
	virtual void Render()=0;
};

#endif