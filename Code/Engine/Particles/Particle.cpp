#include "Particle.h"
#include "SDL.h"

void CParticle::Update(float dt)
{
	if ( m_vx != 0.f )
	{
		if (m_vx > 0.f)
		{
			m_vx -= m_Resistance * dt;
			if (m_vx < 0.f) m_vx = 0.f;
		}
		else
		{
			m_vx += m_Resistance * dt;
			if (m_vx > 0.f) m_vx = 0.f;
		}		 
	}
	m_vy += m_Gravity * dt;
	m_x += m_vx * dt;
	m_y += m_vy * dt;

	if (m_LiveTime > 0.f)
		m_Alpha = (m_LiveTime - m_LivedTime) / m_LiveTime;
	if (m_Alpha > 1.f) m_Alpha = 1.f;

	if (m_LivedTime < m_LiveTime)
	{
		m_LivedTime += dt;		
	}
	else m_bIsDead = true; 			
}

void CParticle::Render(SDL_Renderer* pRenderer)
{
	//save color
	uint8 l_r,l_g,l_b,l_a;
	SDL_GetRenderDrawColor(pRenderer, &l_r, &l_g, &l_b, &l_a);
	SDL_SetRenderDrawColor(pRenderer, m_r, m_g, m_b, uint8(255 * m_Alpha));	
	//render
	if ((m_vy >= DEFAULT_BLUR_VEL) || (m_vx >= DEFAULT_BLUR_VEL))
	{	
		SDL_RenderDrawLine(pRenderer, int32(m_x - m_vx*0.01f), int32(m_y - m_vy*0.01f), int32(m_x), int32(m_y));
	}
	else
	{
		SDL_RenderDrawPoint(pRenderer, int32(m_x), int32(m_y));
	}
	
	//set previous color
	SDL_SetRenderDrawColor(pRenderer, l_r, l_g, l_b, l_a);

}