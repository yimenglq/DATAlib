#ifndef StaticList_H
#define StaticList_H
#include"SeqList.h"

namespace DATAlib
{
	template<typename T, int N>
	class StaticList:public SeqList<T>//静态线性表
	{
	protected:
		T m_staticArry[N];//静态数组 顺序存取空间 模板N 为空间大小

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

		virtual int capacity() const override//线性表最大存储数 
		{

			return N;
		}

	};


}




#endif
