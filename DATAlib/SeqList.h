#ifndef SeqList_H
#define SeqList_H
#include"List.h"
#include"Exception.h"

namespace DATAlib
{


	template <typename T>
	class SeqList : public List<T>//线性表基操
	{
	protected:
		T* m_array;//存储的内存
		int m_length;//存储的元素数量（线性表当前长度）

	public:
		virtual bool insert(const T& e)override
		{

			return insert(m_length, e);
		}

		virtual bool insert(int i, const T& e)override//插入元素
		{
			bool ret = ((0 <= i) && (i <= m_length));
			ret = ret && (m_length < capacity());
			if (ret)
			{
				for (int p = m_length - 1; p >= i; p--)//挪动目标位置及之后的元素
				{
					m_array[p + 1] = m_array[p];

				}

				m_array[i] = e;
				m_length++;
			}

			return ret;
		}

		virtual bool remove(int i) override//移除元素
		{
			bool ret = ((0 <= i) && (i < m_length));//合法性判断
			//ret = ret && (m_length < capacity());

			if (ret)
			{
				for (int p = i; p < m_length - 1; p++)
				{
					m_array[p] = m_array[p + 1];
				}
				m_length--;
			}
			return ret;
		}
		virtual bool set(int i, const T& e)override//设置元素
		{
			bool ret = ((0 <= i) && (i < m_length));
			if (ret)
			{
				m_array[i] = e;
			}
			return ret;
		}
		virtual T get(int i)const //获取元素
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				return	m_array[i];
			}

			return -1;

		}
		virtual bool get(int i, T& e)const override//获取元素
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				e = m_array[i];
			}

			return ret;

		}
		virtual int length()const override//线性表长度
		{
			return m_length;
		}
		virtual void clear() override//清除
		{
			m_length = 0;
		}

		T& operator[] (int i)//重写数组操作符
		{
			bool ret = ((0 <= i) && (i < m_length));
			if (ret)
			{
				return m_array[i];
			}
			else
			{
				THROW_EXCEPTION(AritthmeticException,"数组越界");
			}
			 
		}
		T operator[](int i)const//重写数组操作符 const版本
		{
			return (const_cast<SeqList<T>&>(*this))[i];
		}

		
		
		virtual int find(const T& e)const override
		{
			int ret = -1;
			
			for (int i = 0; i < m_length; i++)
			{
				if (m_array[i] == e) 
				{
					ret = i;
					break;

				}
			}
			return ret;
		}
		
		virtual int capacity() const = 0;//线性表最大存储数
	};

	

}

#endif
