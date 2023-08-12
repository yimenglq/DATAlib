#ifndef StaticArray_H
#define StaticArray_H
#include"Array.h"

namespace DATAlib
{

	template<typename T,int N>
	class StaticArray :public Array<T>//¾²Ì¬Êý×éÀà
	{
	protected:
		T m_staticArray[N];

	public:
			
			StaticArray()
			{
				this->m_Array = m_staticArray;

			}

			StaticArray(const StaticArray<T,N>& obj)
			{
				this->m_Array = m_staticArray;
				
				
					for (int i = 0; i < obj.length(); i++)
					{
						this->m_staticArray[i] = obj.m_staticArray[i];
					}
					
				
			}

			StaticArray<T,N>& operator=(const StaticArray<T, N>& obj)
			{
				if (this != &obj)
				{
					for (int i = 0; i < obj.length(); i++)
					{
						this->m_staticArray[i] = obj.m_staticArray[i];
					}

				}
				return *this;
			}

			virtual int length() const override
			{
				return N;
			}


	};

}


#endif // !StaticArray_H

