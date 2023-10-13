#ifndef SmartPointers_H
#define SmartPointers_H
#include"Object.h"
#include"Pointer.h"
namespace DATAlib
{
	template<typename T>
	class SmartPointers : public Pointer<T>
	{
	/*protected:
		T* m_pointers;*/

	public:
		SmartPointers(T* const p = NULL):Pointer<T>(p)
		{

		}
		/*SmartPointers(const T& p = NULL)
		{
			m_pointers = &p;
		}*/
		SmartPointers(const	SmartPointers<T>& e)//¿½±´¹¹Ôì
		{
			this->m_Pointer = e.m_Pointer;

			const_cast<SmartPointers<T>&>(e).m_Pointer = NULL;
		}
		SmartPointers<T>& operator = (const	SmartPointers<T>& e)
		{
			if (this != &e)
			{
				T* pointer = e.m_Pointer;
				this->m_Pointer = e.m_Pointer;
				const_cast<SmartPointers<T>&>(e).m_Pointer = NULL;
				delete pointer;

			}

			return *this;
		}

		

		~SmartPointers() override
		{
			delete this->m_Pointer;
		}


	};
}



#endif // !SmartPointers_H



