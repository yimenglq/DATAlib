#ifndef DynamicArray_H
#define DynamicArray_H
#include"Array.h"
#include"Exception.h"

namespace DATAlib
{
	template<typename T>
	class DynamicArray : public Array<T>
	{
	protected:
		int m_ArraySize;

		T* copy(T* array, int len, int newlen )
		{
			T* ret = new T[newlen];
			if (ret != NULL)
			{
				int size = (len < newlen) ? len: newlen;

				for (int i = 0; i < size; i++)
				{
					ret[i] = array[i];
				}
			}

			return ret;
		}


		void update(T* array, int length)
		{
			if (array != NULL)
			{
				
				T* temp = this->m_Array;
				
				this->m_Array = array;
				this->m_ArraySize = length;
				
				delete[] temp;
			}
			else
			{
				THROW_EXCEPTION(AritthmeticException, "update ����arrayΪ��");
			}
		}

		void init(T* array, int length)
		{
			if (array != NULL)
			{

				this->m_Array = array;
				this->m_ArraySize = length;
			}
			else
			{
				THROW_EXCEPTION(AritthmeticException, "�ڴ治��");

			}
		}

	public:

		DynamicArray(int length)
		{
			init(new T[length], length);

			///////////////////////////////////
			/*this->m_Array = new T[length];
			if (this->m_Array != NULL)
			{
				this->m_ArraySize = length;

			}
			else
			{
				THROW_EXCEPTION(AritthmeticException, "�ڴ治��");

			}*/
		}

		DynamicArray(const DynamicArray<T>& obj)
		{
			//this->m_Array = copy(obj.m_Array, obj.m_ArraySize, obj.m_ArraySize);
			
			init(copy(obj.m_Array, obj.m_ArraySize, obj.m_ArraySize), obj.m_ArraySize);
			////////////////////////////////////////////////////////////////////////////
			
			/*this->m_Array = new T[obj.m_ArraySize];

			if (this->m_Array != NULL)
			{
				for (int i = 0; i < obj.m_ArraySize; i++)
				{
					this->m_Array[i] = obj.m_Array[i];
				}
				this->m_ArraySize = obj.m_ArraySize;
			}
			else
			{
				THROW_EXCEPTION(AritthmeticException, "�ڴ治��");

			}*/
		}

		DynamicArray<T>& operator= (const DynamicArray<T>& obj)
		{
			if (this != &obj)
			{
				update(copy(obj.m_Array, obj.m_ArraySize, obj.m_ArraySize), obj.length());//����ָ�������ַ

				////////////////////////////////////////////////////////////////
				//T* array = copy(obj.m_Array, obj.m_ArraySize, obj.m_ArraySize);//��������Ԫ��

				//update(array, obj.length);//����ָ�������ַ

			////////////////////////////////////////////////////////////////////////////////

				/*T* array = new T[obj.m_ArraySize];
				if (array != NULL)
				{
					for (int i = 0; i < obj.m_ArraySize; i++)
					{
						array[i] = obj.m_Array[i];
					}

					T* temp = this->m_Array;
					this->m_Array = array;
					this->m_ArraySize = obj.m_ArraySize;
					delete[] temp;*/

				//}
				/*else
				{
					THROW_EXCEPTION(AritthmeticException, "�ڴ治��");
				}*/
				

			}

			return *this;
		}

		


		virtual int length() const override
		{

			return m_ArraySize;
		}

		virtual bool resize(int length)
		{
			if (this->m_ArraySize != length)
			{
				
				update(copy(this->m_Array, this->m_ArraySize, length), length);
				///////////////////////////////////////
				
				/*T* array = new T[length];

				if (array != NULL)
				{
					int size = (this->m_ArraySize > length) ? length : this->m_ArraySize;
					for (int i = 0; i < size; i++)
					{
						array[i] = this->m_Array[i];

					}

					T* temp = this->m_Array;
					this->m_Array = array;
					this->m_ArraySize = length;
					delete[] temp;
					return 1;
				}
				else
				{
					THROW_EXCEPTION(AritthmeticException, "�ڴ治��");
				}*/

				
			}
			return 0;

		}

		~DynamicArray()
		{

			delete[] this->m_Array;
		}
	};



}
#endif