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
			struct SNode :public Node//Ϊ�˵��ù��캯�� ����дnew�ؼ��֣�
			{
				void* operator new(size_t size, void* p)//��ָ���ڴ� new �ؼ��ֵ���д��ʽ
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
						ret = new(ret)SNode();//��ָ���ڴ�new �Ĳ���
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
