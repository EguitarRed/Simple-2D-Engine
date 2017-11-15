#include "ParticleManager.h"

CParticleManager::~CParticleManager()
{
	std::vector<CParticle*>::iterator l_it = m_Particles.begin();
	for(; l_it != m_Particles.end(); ++l_it)
	{
		 CHECKED_DELETE(*l_it);
	}
	m_Particles.clear();
}

void CParticleManager::AddParticle(const float x, const float y, const float vx, const float vy, const uint8 r, const uint8 g,const uint8 b)
{
	CParticle* l_particle = new CParticle( x, y, vx, vy, r, g, b );
	m_Particles.push_back(l_particle);
}

void CParticleManager::AddExplosion(const float x, const float y, const uint8 r, const uint8 g,const uint8 b)
{
	float l_vx,l_vy;
	bool l_bRight,l_bDown;
	for(int32 i= 0; i < NUM_PARTICLES_EXPLOSION; ++i)
	{
		l_bRight = rand() % 2 == 1;	
		if (l_bRight) l_vx = float(rand() % MAX_VEL_EXPLOSION);
		else l_vx = float(-rand() % MAX_VEL_EXPLOSION);
		l_bDown = rand() % 4 == 3;
		if (l_bDown) l_vy = float(rand() % MAX_VEL_EXPLOSION);
		else l_vy = float(-rand() % MAX_VEL_EXPLOSION);
		AddParticle( x, y, l_vx, l_vy, r, g, b );
	}
	
}

void CParticleManager::Update(float dt)
{
	std::vector<CParticle*>::iterator l_it = m_Particles.begin();	
	for(; l_it != m_Particles.end(); )
	{
		(*l_it)->Update(dt);
		if ((*l_it)->IsDead())
		{
			CParticle* l_particle = *l_it;
			l_it = m_Particles.erase(l_it);
			CHECKED_DELETE(l_particle);
		}
		else
		{
			++l_it;
		}
	}		
}

void CParticleManager::Render(SDL_Renderer* pRenderer)
{
	std::vector<CParticle*>::iterator l_it = m_Particles.begin();
	for(; l_it != m_Particles.end(); ++l_it)
	{
		(*l_it)->Render(pRenderer);
	}
}
