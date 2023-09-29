#ifndef LINKLIST_H
#define LINKLIST_H	
#include "List.h"
#include"Exception.h"
namespace DATAlib
{
	template<typename T>
	class LinkList : public	List<T>
	{
	protected:
		struct Node : public Object
		{
			T value;
			Node* next;

		};

		//mutable	Node m_header;//ͷ�ڵ�
		mutable struct:public Object
		{
			char value[sizeof(T)];
			Node* next;

		} m_header;

		
		
		int m_length;//�ڵ������������ͷ�ڵ㣩
		
		Node* m_current;//�α�
		int m_step;//�α��ƶ��Ĳ���

		Node* position(int i)
		{
			Node* ret = reinterpret_cast<Node*>(&m_header);
			if((0<=i)&&(i<m_length))
			for (int p = 0; p < i; p++)
			{
				ret = ret->next;
			}
			return ret;
		}


		virtual Node* create()
		{
			return new Node();
		}

		virtual void destory(Node* pn)
		{
			delete pn;
		}

	public:
		LinkList()
		{
			m_header.next = NULL;
			m_length = 0;
			m_step = 1;
		}

		bool insert(const T& e) override
		{
			return insert(m_length,e);
		}

		 bool insert(int i, const T& e) override
		{
			 bool ret = ((0 <= i) && ( i <= m_length));
			 if (ret)
			 {
				 Node* node = create();
				 if (node != NULL)
				 {
					 Node* current = reinterpret_cast<Node*>(&m_header);
						for (int p = 0; p < i; p++)
						{
							current = current->next;
						}

						node->value = e;
						node->next = current->next;
						current->next = node;
						m_length++;

				 }
				 else
				 {
					 //THROW_EXCEPTION(AritthmeticException, "����Խ��");
					 THROW_EXCEPTION(AritthmeticException, "�ڴ治�㣬�ڵ����ʧ��");
				 }
				

			 }

			 return ret;
		}
		  bool remove(int i) override
		 {
			  bool ret = ((0 <= i) && (i < m_length));
			  if (ret)
			  {
				  Node* current = reinterpret_cast<Node *>( & m_header);
				  for (int p = 0; p < i; p++)
				  {
					  current = current->next;
				  }
				  
				  Node* tDel = current->next;
				  current->next = tDel->next;
				destory( tDel);
				  m_length--;
			  }


			  return ret;

		 }
		   bool set(int i, const T& e)override
		  {
			   bool ret = ((0 <= i) && (i < m_length));
			   if (ret)
			   {
				   Node* current = reinterpret_cast<Node*>(&m_header);
				   for (int p = 0; p < i; p++)
				   {
					   current = current->next;
				   }

				   current->next->value = e;
				  
			   }
			   else
			   {

				   THROW_EXCEPTION(AritthmeticException, "��������");

			   }

			   return ret;

		  }

		   T get(int i)
		   {
			   T ret;
			   get(i, ret);
			     


			   return ret;
		   }

		    bool get(int i, T& e)const override
		   {
				bool ret = ((0 <= i) && (i < m_length));
				if (ret)
				{
					Node* current = reinterpret_cast<Node*>( & m_header);
					for (int p = 0; p < i; p++)
					{
						current = current->next;
					}

					e = current->next->value;

				}
				else
				{
				
					THROW_EXCEPTION(AritthmeticException, "��������");

				}
				
				return ret;

		   }
			int length()const override
			{
				return m_length;
			}
			void clear() override
			{
				while (m_header.next)
				{
					Node* tDel = m_header.next;
					m_header.next = tDel->next;
					destory( tDel);
				}
				m_length = 0;
			}
			~LinkList()
			{
				clear();

			}
			virtual int find(const T& e)const override//�����Ƿ��ж�Ӧ��Ԫ��
			{
				int ret = -1;
				int i = 0;
				Node* node = m_header.next;
				while (node)
				{
					if (node->value == e)
					{
						ret = i;
						break;
					}
					else
					{
						node = node->next;
						i++;
					}
				}
				return ret;

			}
			virtual bool move(int i, int step = 1)//��λ�α�λ�� ȷ�����εĲ���
			{
				bool ret = ((0 <= i) && (i < m_length) && (step > 0));
				if (ret)
				{
					m_current = position(i)->next;
					m_step = step;
				}
				return ret;
			}
			T current()//�����α����value
			{
				if (!end())
				{
					return m_current->value;
				}
				else
				{
					THROW_EXCEPTION(AritthmeticException, "��ǰ�α�Ϊ��");
				}
			}
			virtual bool end()//�ж��α��Ƿ�Ϊ�� ָ�� ����ĩβ
			{
				return ( m_current == NULL );
			}

			virtual bool next()//���ݲ����ƶ��α�
			{
				int i = 0;
				while ( (i < m_step) && (!end()))
				{
					m_current = m_current->next;
					i++;
				}
				return (i == m_step);
			}


	};

}

#endif // !LINKLIST_H

