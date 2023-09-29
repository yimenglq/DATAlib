#ifndef SeqList_H
#define SeqList_H
#include"List.h"
#include"Exception.h"

namespace DATAlib
{


	template <typename T>
	class SeqList : public List<T>//���Ա����
	{
	protected:
		T* m_array;//�洢���ڴ�
		int m_length;//�洢��Ԫ�����������Ա�ǰ���ȣ�

	public:
		virtual bool insert(const T& e)override
		{

			return insert(m_length, e);
		}

		virtual bool insert(int i, const T& e)override//����Ԫ��
		{
			bool ret = ((0 <= i) && (i <= m_length));
			ret = ret && (m_length < capacity());
			if (ret)
			{
				for (int p = m_length - 1; p >= i; p--)//Ų��Ŀ��λ�ü�֮���Ԫ��
				{
					m_array[p + 1] = m_array[p];

				}

				m_array[i] = e;
				m_length++;
			}

			return ret;
		}

		virtual bool remove(int i) override//�Ƴ�Ԫ��
		{
			bool ret = ((0 <= i) && (i < m_length));//�Ϸ����ж�
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
		virtual bool set(int i, const T& e)override//����Ԫ��
		{
			bool ret = ((0 <= i) && (i < m_length));
			if (ret)
			{
				m_array[i] = e;
			}
			return ret;
		}
		virtual T get(int i)const //��ȡԪ��
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				return	m_array[i];
			}

			return -1;

		}
		virtual bool get(int i, T& e)const override//��ȡԪ��
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				e = m_array[i];
			}

			return ret;

		}
		virtual int length()const override//���Ա���
		{
			return m_length;
		}
		virtual void clear() override//���
		{
			m_length = 0;
		}

		T& operator[] (int i)//��д���������
		{
			bool ret = ((0 <= i) && (i < m_length));
			if (ret)
			{
				return m_array[i];
			}
			else
			{
				THROW_EXCEPTION(AritthmeticException,"����Խ��");
			}
			 
		}
		T operator[](int i)const//��д��������� const�汾
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
		
		virtual int capacity() const = 0;//���Ա����洢��
	};

	

}

#endif
