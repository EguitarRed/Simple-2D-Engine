#pragma once
#ifndef _OBJECT2DMANAGER_H_
#define _OBJECT2DMANAGER_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "..\Base\MapManager.h"
#include "Object2D.h"
#include <string>

class CObject2DManager : public CMapManager<CObject2D>
{
public:
	~CObject2DManager();

	void AddNewObject(const std::string instanceName, const std::string SpriteName, float x, float y, float Width, float Height);
	void AddNewObject(const std::string instanceName, CSprite* Sprite, float x, float y, float Width, float Height);

	void Update(float dt);
	void Render();
};

#endif