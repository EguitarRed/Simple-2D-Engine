//----------------------------------------------------------------------------------
// CMapManager class
// Author: Javier Diaz
//
// Description:
// Map de resources
// 
//----------------------------------------------------------------------------------
#pragma once
#ifndef __MAP_MANAGER_H__
#define __MAP_MANAGER_H__

#include <map>
#include <assert.h>
#include "Base.h"

#include <string>

template <class T>
class CMapManager
{
protected:
    typedef std::map<std::string, T*>		TMapResource;
	TMapResource							m_Resources;

public:
    virtual T* getResource(const char* Name)
	{
      TMapResource::iterator l_It=m_Resources.find(Name);
      if(l_It!=m_Resources.end())
        return l_It->second;
	  return NULL;
	}

    TMapResource getMyResources()
    {
      return m_Resources;
    }

	virtual void AddResource(const char* Name, T* Resource)
	{
		assert(Resource);
		m_Resources[Name] = Resource;
	}

	void Destroy()
	{
		TMapResource::iterator it = m_Resources.begin();

		for(; it != m_Resources.end(); it++)
		{
			CHECKED_DELETE(it->second);
		}
		m_Resources.clear();
	}
};

#endif; //__MAP_MANAGER_H__