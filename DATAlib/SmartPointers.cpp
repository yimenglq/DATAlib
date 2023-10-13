#erro "废弃"
#include "SmartPointers.h"

namespace DATAlib
{
	template<typename T>
	SmartPointers<T>::SmartPointers()
	{
		pits = NULL;
	}

	template<typename T>
	SmartPointers<T>::SmartPointers(int size)
	{
		pits = new T[size];
	}

	template<typename T>
	SmartPointers<T>::SmartPointers(const	SmartPointers<T>& e)
	{
		this->pits = e.pits;
		e.pits = NULL;
				
	}

	template<typename T>
	SmartPointers<T>& DATAlib::SmartPointers<T>::operator=(const SmartPointers<T>& e)
	{
		
		if (this != &e)
		{
			if (this->pits != NULL)
			{
			}
			else
			{
				delete pits;
			}
		
			this->pits = e.pits;
			e.pits = NULL;

		}

		return *this;
	}

	template<typename T>
	T SmartPointers<T>::operator->()
	{

		return this->pits;
	}

	template<typename T>
	SmartPointers<T>::~SmartPointers()
	{
		delete pits;
	}

	
}
