#ifndef Array_H
#define Array_H
#include"Object.h"
#include"Exception.h"

namespace DATAlib
{
	template<typename T>
	class Array : public Object
	{
	protected:
		T* m_Array;
	public:
		virtual	bool get(int i, T& e) const;
		/*{
			bool ret = ((0 <= i) && (i < this->length()));
			if (ret)
			{
				e = m_Array[i];
			}

			return ret;
		}*/
		virtual bool set(int i, const T& e);
		virtual int length() const = 0;

		T& operator[](int i);
		T operator[](int i) const;
	};

	template<typename T>
	bool	Array<T>::get(int i, T& e) const
	{
		bool ret = ((0 <= i) && (i < this->length()));
		if (ret)
		{
			e = m_Array[i];
		}

		return ret;
	}

	template<typename T>
	bool	Array<T>::set(int i, const T& e)
	{
		bool ret = ((0 <= i) && (i < this->length()));
		if (ret)
		{
			m_Array[i] = e;

		}

		return ret;

	}
	
	template<typename T>
	T& Array<T>::operator[](int i)
	{
		bool ret = ((0 <= i) && (i < this->length()));
		if (ret)
		{
			return m_Array[i];
		}
		else
		{
			THROW_EXCEPTION(AritthmeticException, "引索错误 越界操作");
		}
	}

	template<typename T>
	T Array<T>::operator[](int i)const
	{
		return (const_cast<Array<T>&>(*this))[i];
	}

}


#endif