#ifndef _SHAREDPOINTER_H_
#define _SHAREDPOINTER_H_
#include"Pointer.h"

namespace DATAlib
{

	template<typename Classtype>
	class SharedPointer : public Pointer<Classtype>
	{
	protected:
		int* m_rel;//指针引用数的内存地址

		void assignment(const SharedPointer<Classtype>& obj)
		{
			this->m_Pointer = obj.m_Pointer;
			this->m_rel = obj.m_rel;
			if(this->m_rel)
				(*(this->m_rel))++;
		}
	public:
		SharedPointer(Classtype* p = NULL) :Pointer<Classtype>(p) 
		{
			if (p)
			{
				m_rel = new int();
				if (m_rel)
				{
					*m_rel = 1;
				}
				else
				{
					throw "内存不住";
				}

			}
			else
			{
				m_rel = NULL;
			}
		}
		SharedPointer(const SharedPointer<Classtype>& obj)
		{
			assignment(obj);
		}
		/*SharedPointer(const SharedPointer<Classtype>& obj) const  构造不分const
		{

			const_cast<SharedPointer<Classtype>&>(*this) = obj;
		}*/

		SharedPointer<Classtype>& operator = (const SharedPointer<Classtype>& obj)
		{
			if (this != &obj)
			{
				if (!this->IsNull())
				{
					
					Clear();

				}

				if( !obj.IsNull())
					assignment(obj);
			}

			
			return *this;
		}
		bool operator ==(const SharedPointer<Classtype>& obj)
		{
			return (this->m_Pointer == obj.m_Pointer);
		}
		bool operator !=(const SharedPointer<Classtype>& obj)
		{
			return !(*this == obj);
		}




		int getRel()  //获取指针引用计数
		{
			return *(this->m_rel);
		}
		int getRel()const
		{
			return *(this->m_rel);
		}


		void Clear()
		{
			if (this->m_rel)
			{
				(*(this->m_rel))--;
				if (*(this->m_rel) <= 0)
				{
					delete this->m_Pointer;
					delete this->m_rel;

				}
			}
			this->m_Pointer = NULL;
			this->m_rel = NULL;
		}

		~SharedPointer()
		{
			Clear();
		}


	};

}


#endif // !_SHAREDPOINTER_H_

