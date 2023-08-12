#pragma once
#include"LinkList.h"
namespace DATAlib
{
	template <typename ClassType,int SpaceNum>
	class StaticLinkList : public LinkList<ClassType>
	{
		private:
			


		protected:
			typedef typename LinkList<ClassType>::Node Node;
			//unsigned char m_static_space[sizeof(typename LinkList<ClassType>::Node) * SpaceNum];
			struct SNode :public Node//为了调用构造函数 （重写new关键字）
			{
				void* operator new(size_t size, void* p)//在指定内存 new 关键字的重写方式
				{
					return p;
				}

			};
			
			unsigned char m_static_space[sizeof(SNode) * SpaceNum];

			int m_space_used[SpaceNum];


			

			virtual Node* create()override
			{
				SNode* ret = NULL;
				for (int i = 0; i < SpaceNum; i++)
				{
					if (!m_space_used[i])
					{
						ret = (reinterpret_cast<SNode*>(m_static_space))+i ;
						ret = new(ret)SNode();//在指定内存new 的操作
						m_space_used[i] = 1;
						
						
						break;
					}
				}

				return	ret;

			}
			virtual void destory(Node* pn)override
			{
				SNode* space = reinterpret_cast<SNode*>(m_static_space);
				SNode* psn = dynamic_cast<SNode*>(pn);
				for ( int i = 0; i <SpaceNum; i++)
				{
					if (psn == (space + i))
					{
						m_space_used[i] = 0;
						psn->~SNode();
						break;
					}
				}

				//delete pn;
			}

		public:
			StaticLinkList()
			{
				for (int i = 0; i < SpaceNum; i++)
				{
					m_space_used[i] = 0;

				}


			}

			int capactiy()
			{
				return SpaceNum;

			}
		


			~StaticLinkList()
			{

				LinkList<ClassType>::clear();
			}
	};


}
