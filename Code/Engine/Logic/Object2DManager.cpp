#include "Object2DManager.h"
#include "..\Core\Core.h"
#include "..\Graphics\SpriteManager.h"


CObject2DManager::~CObject2DManager()
{
	Destroy();
}

void CObject2DManager::AddNewObject(const std::string instanceName, const std::string SpriteName, float x, float y, float Width, float Height)
{
	if (getResource(instanceName.c_str()) == NULL) //exists?
	{	
		CSprite* l_sprite = CORE.GetSpriteManager()->getResource(SpriteName.c_str());
		CObject2D* l_obj = new CObject2D(l_sprite);
		l_obj->SetBounds(x,y,Width,Height);
		AddResource(instanceName.c_str(), l_obj);
	}
}

void CObject2DManager::AddNewObject(const std::string instanceName, CSprite* Sprite, float x, float y, float Width, float Height)
{
	if (getResource(instanceName.c_str()) == NULL) //exists?
	{
		CObject2D* l_obj = new CObject2D(Sprite);
		l_obj->SetBounds(x,y,Width,Height);
		AddResource(instanceName.c_str(), l_obj);
	}
}

void CObject2DManager::Update(float dt)
{
	TMapResource::iterator l_it = m_Resources.begin();
	for(; l_it != m_Resources.end(); ++l_it)
	{
		l_it->second->Update(dt);
	}
}

void CObject2DManager::Render()
{
	TMapResource::iterator l_it = m_Resources.begin();
	for(; l_it != m_Resources.end(); ++l_it)
	{
		l_it->second->Render();
	}
}