#ifndef LINKLIST_H
#define LINKLIST_H	
#include "List.h"
#include"Exception.h"
#include"SharedPointer.h"
namespace DATAlib
{
	template<typename T>
	class LinkList : public	List<T>
	{
	protected:
		struct Node : public Object
		{
			T value;
			//Node* next;
			SharedPointer<Node> next;
		};

		//mutable	Node m_header;//头节点
		mutable struct:public Object
		{
			char value[sizeof(T)];
			//Node* next;
			SharedPointer<Node> next;

		} m_header;

		
		
		int m_length;//节点个数（不含有头节点）
		
		//Node* m_current;//游标
		SharedPointer<Node> m_current;//游标
		int m_step;//游标移动的步长

		//Node* position(int i)
		SharedPointer<Node> position(int i)
		{
			//Node* ret = reinterpret_cast<Node*>(&m_header);
			SharedPointer<Node> ret;
			Node* cnode = reinterpret_cast<Node*>(&m_header);
			ret = cnode->next;
			if((0<=i)&&(i<m_length))
			/*for (int p = 0; p < i; p++)
			{
				ret = ret->next;
			}*/
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
			//m_current =	reinterpret_cast<Node*>( &m_header);
			m_current = NULL;
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
				 //Node* node = create();
				 SharedPointer<Node> node = create();
				 //if (node != NULL)
				 if(!node.IsNull())
				 {
					// Node* current = reinterpret_cast<Node*>(&m_header);
					 SharedPointer<Node> current;
					 Node * cnod = reinterpret_cast<Node*>(&m_header);
					 /*for (int p = 0; p < i; p++)
						{
							current = current->next;
						}*/


					 current = cnod->next;
					 if (i == 0)
					 {
						 node->value = e;
						 node->next = cnod->next;
						 cnod->next = node;
						 m_length++;
						 return ret;
					 }
					 for (int p = 1; p < i; p++)
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
					 //THROW_EXCEPTION(AritthmeticException, "数组越界");
					 THROW_EXCEPTION(AritthmeticException, "内存不足，节点分配失败");
				 }
				

			 }

			 return ret;
		}
		  bool remove(int i) override
		 {
			  bool ret = ((0 <= i) && (i < m_length));
			  if (ret)
			  {
				  //Node* current = reinterpret_cast<Node *>( & m_header);
				  SharedPointer<Node> current;
				  Node* currentnode = reinterpret_cast<Node*>(&m_header);
				  current = currentnode->next;
				  if (i == 0)
				  {
					  SharedPointer<Node> tDel = currentnode->next;
					  currentnode->next = tDel->next;
					  if (m_current == tDel)
					  {
						  m_current = tDel->next;
					  }

					  m_length--;
					  return ret;
				  }
				  /*for (int p = 0; p < i; p++)
				  {
					  current = current->next;
				  }*/
				  for (int p = 1; p < i; p++)
				  {
					  current = current->next;
				  }
				  
				 /* Node* tDel = current->next;*/
				  SharedPointer<Node> tDel = current->next;
				  current->next = tDel->next;
				  if (m_current == tDel)
				  {
					  m_current = tDel->next;
				  }

				  m_length--;
				  //destory( tDel);
				  
			  }


			  return ret;

		 }
		   bool set(int i, const T& e)override
		  {
			   bool ret = ((0 <= i) && (i < m_length));
			   if (ret)
			   {
				  /* Node* current = reinterpret_cast<Node*>(&m_header);*/
				   SharedPointer<Node> current;
				   Node* currentNode = reinterpret_cast<Node*>(&m_header);
				   current = currentNode->next;
				   if (i == 0)
				   {
					   current->value = e;
					   return ret;
				   }
				   /*for (int p = 0; p < i; p++)
				   {
					   current = current->next;
				   }*/
				   for (int p = 1; p < i; p++)
				   {
					   current = current->next;
				   }

				   current->next->value = e;
				  
			   }
			   else
			   {

				   THROW_EXCEPTION(AritthmeticException, "引索错误");

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
					/*Node* current = reinterpret_cast<Node*>( & m_header);*/
					SharedPointer<Node> current;
					Node *currentNode  = reinterpret_cast<Node*>(&m_header);
					current = currentNode->next;
					if (i == 0)
					{
						e = current->value;
						return ret;
					}
					for (int p = 1; p < i; p++)
					{
						current = current->next;
					}

					e = current->next->value;

				}
				else
				{
				
					THROW_EXCEPTION(AritthmeticException, "引索错误");

				}
				
				return ret;

		   }
			int length()const override
			{
				return m_length;
			}
			void clear() override
			{
				while (!m_header.next.IsNull())
				{
					/*Node* tDel = m_header.next;*/
					SharedPointer<Node> tDel = m_header.next;
					m_header.next = tDel->next;
					m_length--;
					//destory( tDel);
				}
				////m_length = 0;
			}
			~LinkList()
			{
				clear();

			}
			virtual int find(const T& e)const override//查找是否有对应的元素
			{
				int ret = -1;
				int i = 0;
				/*Node* node = m_header.next;*/
				SharedPointer<Node> node = m_header.next;
				/*while (node)*/
				while (!node.IsNull())
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
			virtual bool move(int i, int step = 1)//定位游标位置 确定单次的步长
			{
				bool ret = ((0 <= i) && (i < m_length) && (step > 0));
				if (ret)
				{
					/*m_current = position(i)->next;*/
					m_current = position(i);
					m_step = step;
				}
				return ret;
			}
			T current()//返回游标里的value
			{
				if (!end())
				{
					/*if (m_current == reinterpret_cast<Node*>	( & m_header))*/
					if (m_current.get() == NULL)
						m_current = m_header.next;
					return m_current->value;
				}
				else
				{
					THROW_EXCEPTION(AritthmeticException, "当前游标为空");
				}
			}
			virtual bool end()//判断游标是否为空 指向 链表末尾
			{
				return ( m_current == NULL );
			}

			virtual bool next()//跟据步长移动游标
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




//重写之前的版本
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

		//mutable	Node m_header;//头节点
		mutable struct :public Object
		{
			char value[sizeof(T)];
			Node* next;

		} m_header;



		int m_length;//节点个数（不含有头节点）

		Node* m_current;//游标
		int m_step;//游标移动的步长

		Node* position(int i)
		{
			Node* ret = reinterpret_cast<Node*>(&m_header);
			if ((0 <= i) && (i < m_length))
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
			m_current = reinterpret_cast<Node*>(&m_header);
			m_header.next = NULL;
			m_length = 0;
			m_step = 1;
		}

		bool insert(const T& e) override
		{
			return insert(m_length, e);
		}

		bool insert(int i, const T& e) override
		{
			bool ret = ((0 <= i) && (i <= m_length));
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
					//THROW_EXCEPTION(AritthmeticException, "数组越界");
					THROW_EXCEPTION(AritthmeticException, "内存不足，节点分配失败");
				}


			}

			return ret;
		}
		bool remove(int i) override
		{
			bool ret = ((0 <= i) && (i < m_length));
			if (ret)
			{
				Node* current = reinterpret_cast<Node*>(&m_header);
				for (int p = 0; p < i; p++)
				{
					current = current->next;
				}

				Node* tDel = current->next;
				current->next = tDel->next;
				if (m_current == tDel)
				{
					m_current = tDel->next;
				}

				m_length--;
				destory(tDel);

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

				THROW_EXCEPTION(AritthmeticException, "引索错误");

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
				Node* current = reinterpret_cast<Node*>(&m_header);
				for (int p = 0; p < i; p++)
				{
					current = current->next;
				}

				e = current->next->value;

			}
			else
			{

				THROW_EXCEPTION(AritthmeticException, "引索错误");

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
				m_length--;
				destory(tDel);
			}
			//m_length = 0;
		}
		~LinkList()
		{
			clear();

		}
		virtual int find(const T& e)const override//查找是否有对应的元素
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
		virtual bool move(int i, int step = 1)//定位游标位置 确定单次的步长
		{
			bool ret = ((0 <= i) && (i < m_length) && (step > 0));
			if (ret)
			{
				m_current = position(i)->next;
				m_step = step;
			}
			return ret;
		}
		T current()//返回游标里的value
		{
			if (!end())
			{
				if (m_current == reinterpret_cast<Node*>	(&m_header))
					m_current = m_header.next;
				return m_current->value;
			}
			else
			{
				THROW_EXCEPTION(AritthmeticException, "当前游标为空");
			}
		}
		virtual bool end()//判断游标是否为空 指向 链表末尾
		{
			return (m_current == NULL);
		}

		virtual bool next()//跟据步长移动游标
		{
			int i = 0;
			while ((i < m_step) && (!end()))
			{
				m_current = m_current->next;
				i++;
			}
			return (i == m_step);
		}


	};

}

#endif // !LINKLIST_H

