#ifndef _LOOPLINKLIST_H_
#define _LOOPLINKLIST_H_

#include"LinkList.h"

namespace DATAlib
{
	template< typename ClassType>
	class LoopLinkList : public LinkList<ClassType>
	{


	protected:
		typedef typename LinkList<ClassType>::Node Node;

		void LastToFirst()
		{
			this->move(0, (this->m_length > 1 ? this->m_length - 1 : 1));
			this->next();
			this->m_current->next = this->m_header.next;

		}
		


	public:
		bool insert(const ClassType& e) override
		{
			
			return	insert(this->m_length,e);

		}
		
		bool insert(int i, const ClassType& e) override
		{
			
			int Loopi = i % (this->m_length > 0 ? this->m_length + 1 : 1);
			bool ret = LinkList<ClassType>::insert(Loopi, e);
			if(Loopi == 0)
				LastToFirst();
			return ret;
		}
		bool remove(int i) override
		{	
			bool ret = true;
				if (i == 0 && this->m_length == 1)
				{
				//Node* current = reinterpret_cast<Node *>( & m_header);
					SharedPointer<Node> current;
					Node* currentnode = reinterpret_cast<Node*>(&this->m_header);
					current = currentnode->next;
				
					SharedPointer<Node> tDel = currentnode->next;
					currentnode->next = tDel->next = NULL;
					if (this->m_current == tDel)
					{
						this->m_current = tDel->next;
					}

					this -> m_length--;
					return ret;
				}
				else
				{
					ret = LinkList<ClassType>::remove(i);
				}
				
				if (i == 0)
				{
					LastToFirst();
				}

			
			return ret;

		}
		bool set(int i, const ClassType& e)override
		{
			int Loopi = i % (this->m_length > 0 ? this->m_length + 1 : 1);

			return LinkList<ClassType>::set(Loopi, e);

		}
		ClassType get(int i)
		{
			int Loopi = i % (this->m_length > 0 ? this->m_length + 1 : 1);
			
			return	LinkList<ClassType>::get(Loopi);
		}

		bool get(int i, ClassType& e)const override
		{
			int Loopi = i % (this->m_length > 0 ? this->m_length + 1 : 1);
			return LinkList<ClassType>::get(Loopi, e);
		}
		void clear() override
		{

			while (!this->m_header.next.IsNull() && (this->m_length > 0))
			{
				/*Node* tDel = m_header.next;*/
				SharedPointer<Node> tDel = this->m_header.next;
				this->m_header.next = tDel->next;
				this->m_length--;
				if (this->m_length == 0)
				{
					this->m_header.next = NULL;
				}
				//destory( tDel);
			}

		}

		virtual bool next()//跟据步长移动游标
		{
			int i = 0;
			while ((i < this->m_step) && (!this->end()) && (this->m_length > 1))
			{
				this->m_current = this->m_current->next;
				i++;
			}
			return (i == this->m_step);
		}

		~LoopLinkList()
		{

			clear();
		}
	};




}


#endif // !_LOOPLINKLIST_H_

