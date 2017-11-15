#include "Timer.h"
#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "SDL.h"


uint32 CTimer::GetTimeCounter()
{
	return m_CurrentTick - m_StartTick;
}

void CTimer::Update()
{
	if (!m_bPaused)
	{
		uint32 l_ct = SDL_GetTicks();
		m_DeltaTick = l_ct - m_CurrentTick;
		m_CurrentTick = l_ct;	
	}
}
	
void CTimer::Start()
{
	if (m_bPaused)
	{
		m_bPaused = false;
		uint32 l_ct = SDL_GetTicks();
		m_StartTick = l_ct - m_CurrentTick;
		m_CurrentTick = l_ct;
		m_DeltaTick = 0;
	}
	else
	{
		m_bPaused = false;
		m_StartTick = SDL_GetTicks();
		m_CurrentTick = m_StartTick;
		m_DeltaTick = 0;
	}
}

void CTimer::Stop()
{
	m_StartTick = 0;
	m_CurrentTick = 0;
	m_DeltaTick = 0;
	m_bPaused = true;
}

void CTimer::Pause()
{
	m_bPaused = true;
}

