#pragma once
#ifndef _SOUNDMANAGER_H_
#define _SOUNDMANAGER_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include <string>
#include "..\Base\MapManager.h"

//*** Forward declarations ****
class CSound;
//****************************

class CSoundManager : public CMapManager<CSound>
{
private:
	std::string m_Path;

public:
	CSoundManager(std::string Path=".\\Sounds\\"):m_Path(Path){}
	~CSoundManager();

	void		LoadSound(std::string Filename);
	void		PlaySound(std::string Filename);
	std::string GetPath() const {return m_Path;}
	void		SetPath(const std::string Path) {m_Path = Path;}
};

#endif

