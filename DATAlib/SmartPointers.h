#ifndef SmartPointers_H
#define SmartPointers_H
#include"Object.h"
namespace DATAlib
{
	template<typename T>
	class SmartPointers : public Object
	{
	protected:
		T* m_pointers;

	public:
		SmartPointers(T* const p = NULL)
		{
			m_pointers = p;

		}
		/*SmartPointers(const T& p = NULL)
		{
			m_pointers = &p;
		}*/
		SmartPointers(const	SmartPointers<T>& e)
		{
			m_pointers = e.m_pointers;

			const_cast<SmartPointers<T>&>(e).m_pointers = NULL;
		}
		SmartPointers<T>& operator = (const	SmartPointers<T>& e)
		{
			if (this != &e)
			{

				delete m_pointers;

				this->m_pointers = e.m_pointers;
				const_cast<SmartPointers<T>&>(e).m_pointers = NULL;

			}

			return *this;
		}

		T& operator*()
		{
			return	*(this->m_pointers);
		}

		T* operator->()
		{
			return	this->m_pointers;
		}

		T* Get()
		{
			return this->m_pointers;
		}

		~SmartPointers() override
		{
			delete m_pointers;
		}


	};
}



#endif // !SmartPointers_H



