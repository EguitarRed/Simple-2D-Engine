#pragma once
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "SDL.h"

#define DEFAULT_LIVE_TIME 1.f
#define DEFAULT_GRAVITY 100.f
#define DEFAULT_RESISTANCE 300.f
#define DEFAULT_BLUR_VEL 50.f

class CParticle
{
protected:
	float		m_x,m_y;
	float		m_vx,m_vy;	
	float		m_LiveTime;	
	float		m_LivedTime;
	bool		m_bIsDead;
	float		m_Alpha;
	float		m_Gravity;
	float		m_Resistance;
	uint8		m_r,m_g,m_b;

public:
	CParticle( const float x = 0,
			   const float y = 0,
			   const float vx = 0,
			   const float vy = 0,
			   const uint8 r = 255,
			   const uint8 g = 255,
			   const uint8 b = 255,
			   const float LiveTime = DEFAULT_LIVE_TIME,
			   const float Gravity = DEFAULT_GRAVITY,
			   const float Resistance = DEFAULT_RESISTANCE )
		: m_x(x)
		, m_y(y)
		, m_vx(vx)
		, m_vy(vy)								
		, m_r(r)
		, m_g(g)
		, m_b(b)
		, m_LiveTime(LiveTime)
		, m_bIsDead(false)
		, m_Alpha(1.f)
		, m_Gravity(Gravity)
		, m_Resistance(Resistance)
		, m_LivedTime(0.f)
	{}

	float	GetX() const									{return m_x;}
	float	GetY() const									{return m_y;}
	float	GetVX() const									{return m_vx;}
	float	GetVY() const									{return m_vy;}			
	float	GetLiveTime() const								{return m_LiveTime;}
	bool	IsDead() const									{return m_bIsDead;}			
	void	SetX(const float x)								{m_x = x;}
	void	SetY(const float y)								{m_y = y;}
	void	SetVX(const float vx)							{m_vx = vx;}
	void	SetVY(const float vy)							{m_vy = vy;}		
	void	SetPosition(const float x,const float y)		{m_x = x; m_y = y;}
	void	SetVelocity(const float vx,const float vy)		{m_vx = vx; m_vy = vy;}
	void	SetColor(const uint8 r, const uint8 g,const uint8 b){m_r=r;m_g=g;m_b=b;}
		
	virtual void Update(float dt);
	virtual void Render(SDL_Renderer* pRenderer);
};

#endif