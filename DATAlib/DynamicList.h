#ifndef DynamicList_H
#define DynamicList_H
#include"SeqList.h"
#include<malloc.h>
#include"Exception.h"

namespace DATAlib
{

	template<typename T>
	class DynamicList :public SeqList<T>//动态线性表
	{
	protected:
		
		int m_MaxSize;//最大存储大小

	public:
		DynamicList(int b_size)
		{
			//this->m_array = (T*)malloc(sizeof(T) * N);
			this->m_array = new T[b_size];
			if (this->m_array != NULL)
			{
				m_MaxSize = b_size;
				this->m_length = 0;

			}
			else
			{
				THROW_EXCEPTION(AritthmeticException, "内存不足");
			}

		}

		virtual int capacity() const override//线性表最大存储数
		{
			return m_MaxSize;

		}

		virtual bool resize(int size) //重新设置存储空间大小
		{
			if (size != this->m_MaxSize)
			{
				T* arry = new T[size];

				if (arry != NULL)
				{
					int length = size > this->m_length ? this->m_length : size;
					for (int i = 0; i < length ; i++ )
					{
						arry[i] = this->m_array[i];

					}
					T* temp = this->m_array;
					this->m_length = length;
					this->m_array = arry;
					this->m_MaxSize = size;
					delete[] temp;
					return 1;
				}
				else
				{
					THROW_EXCEPTION(AritthmeticException, "内存不足");
				}
			}
			return 0;

		}
		
		~DynamicList()
		{

			delete[] this->m_array;
		}

	};

}





#endif // !DynamicList_H

