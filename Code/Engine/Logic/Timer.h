#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"

class CTimer
{
private:
	uint32	m_StartTick;
	uint32	m_DeltaTick;
	uint32	m_CurrentTick;
	bool	m_bPaused;

public:
	CTimer()
		: m_StartTick(0)
		, m_DeltaTick(0)
		, m_CurrentTick(0)
		, m_bPaused(true)
	{}

	uint32 GetStartTick() const {return m_StartTick;}
	uint32 GetDeltaTick() const {return m_DeltaTick;}
	uint32 GetCurrentTick() const {return m_CurrentTick;}
	uint32 GetTimeCounter();

	void Update();
	
	void Start();
	void Stop();
	void Pause();
};


#endif

