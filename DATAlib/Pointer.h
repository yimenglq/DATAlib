#ifndef _POINTER_H_
#define _POINTER_H_  

#include"Object.h"

namespace DATAlib
{
	template < typename ClassType >
	class Pointer :public Object
	{
	protected:
		ClassType* m_Pointer;

	public:
		Pointer(ClassType* Pointers = NULL ):m_Pointer(Pointers){}
		
		ClassType*	operator ->()
		{

			return	m_Pointer;
		}
		const	ClassType* operator ->()const
		{

			return	m_Pointer;
		}
		ClassType&	operator *()
		{
			return *m_Pointer;
		}
		const	ClassType& operator *()const
		{
			return *m_Pointer;
		}
		bool IsNull()
		{
			return (m_Pointer == NULL);
		}
		bool IsNull() const
		{
			return (m_Pointer == NULL);
		}
		inline	ClassType* get()
		{
			return m_Pointer;
		}
		inline const ClassType* get()const
		{

			return m_Pointer;
		}





	};

}





#endif // !_POINTERS.H_

