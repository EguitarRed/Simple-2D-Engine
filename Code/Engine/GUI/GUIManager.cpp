#include "GUIManager.h"
#include "GUIText.h"
#include "..\Core\Core.h"
#include <vector>

CGUIManager::~CGUIManager()
{
	Destroy();
}

CGUIElement* CGUIManager::AddTextBox(const std::string instanceName, const std::string Text, float x, float y)
{
	if (getResource(instanceName.c_str()) == NULL) //exists?
	{
		CGUIText* l_text = new CGUIText(CORE.GetRenderer(), Text);		
		l_text->SetPosition(x,y);
		l_text->SetName(instanceName);
		AddResource(instanceName.c_str(), l_text);
		return l_text;
	}
	return NULL;
}

void CGUIManager::Update(float dt)
{	
	TMapResource::iterator l_it = m_Resources.begin();
	for(; l_it != m_Resources.end(); )
	{
		l_it->second->Update(dt);
		if (l_it->second->IsDead())
		{
			CHECKED_DELETE(l_it->second);
			l_it = m_Resources.erase(l_it);
		}
		else
		{
			++l_it;
		}			
	}		
}
void CGUIManager::Render()
{
	TMapResource::iterator l_it = m_Resources.begin();
	for(; l_it != m_Resources.end(); ++l_it)
	{
		l_it->second->Render();
	}
}