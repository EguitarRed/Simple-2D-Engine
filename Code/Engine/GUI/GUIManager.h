#pragma once
#ifndef _GUIMANAGER_H_
#define _GUIMANAGER_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include "..\Base\MapManager.h"
#include <string>

//****** FORWARD Declarations ***
class CGUIElement;
//*****************************

class CGUIManager: public CMapManager<CGUIElement>
{
public:
	CGUIManager(){}
	~CGUIManager();

	CGUIElement* AddTextBox(const std::string instanceName, const std::string Text, float x, float y);

	void Update(float dt);
	void Render();
};

#endif