#ifndef StaticList_H
#define StaticList_H
#include"SeqList.h"

namespace DATAlib
{
	template<typename T, int N>
	class StaticList:public SeqList<T>//��̬���Ա�
	{
	protected:
		T m_staticArry[N];//��̬���� ˳���ȡ�ռ� ģ��N Ϊ�ռ��С

	public:
		StaticList()
		{
			this->m_array = m_staticArry;
			this->m_length = 0;
		}

		/*StaticList(int p)
		{
			this->m_array = m_staticArry;
			this->m_length = 0;

			for (int i = 0; i < N; i++)
			{
				m_staticArry[i] = p;
			}
		}*/

		virtual int capacity() const override//���Ա����洢�� 
		{

			return N;
		}

	};


}




#endif
