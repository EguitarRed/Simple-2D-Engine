#pragma once
#ifndef _PARTICLEMANAGER_H_
#define _PARTICLEMANAGER_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "Particle.h"
#include <vector>
#include "SDL.h"

#define NUM_PARTICLES_EXPLOSION 200
#define MAX_VEL_EXPLOSION 300

class CParticleManager
{
private:
	std::vector<CParticle*>		m_Particles;

public:
	CParticleManager(){}
	~CParticleManager();

	void AddParticle(const float x, const float y, const float vx, const float vy, const uint8 r, const uint8 g, const uint8 b);
	void AddExplosion(const float x, const float y, const uint8 r, const uint8 g, const uint8 b);

	void Update(float dt);
	void Render(SDL_Renderer* pRenderer);
};

#endif