#pragma once
#ifndef INC_SINGLETON_H_
#define INC_SINGLETON_H_

#include <assert.h>

/** Template class for creating single-instance global classes.
*/
template <typename T> class CSingleton
{
protected:

		static T* ms_Singleton;		///< Puntero a la variable de la propia clase.

public:
		/**
		* Constructor.
		*/
		CSingleton( void )
		{
				assert( !ms_Singleton );
				ms_Singleton = static_cast< T* >( this );
		}

		/**
		* Destructor.
		*/
		virtual ~CSingleton( void )
		{  
				assert( ms_Singleton );  ms_Singleton = 0;  
		}

		/**
		* Obtenemos el singleton.
		* @Return Singleton.
		*/
		static T& GetSingleton( void )
		{	
				assert( ms_Singleton );  
				return ( *ms_Singleton ); 
		}

		/**
		* Obtenemos el puntero al singleton.
		* @Return Puntero al singleton.
		*/
		static T* GetSingletonPtr( void )
		{ 
				return ms_Singleton; 
		}
};

template<typename T> T* CSingleton<T>::ms_Singleton = 0;

#endif //INC_SINGLETON_H_
