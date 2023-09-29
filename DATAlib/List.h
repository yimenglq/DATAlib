#ifndef List_H
#define List_H
#include"Object.h"
namespace DATAlib
{

	//���Ա�
	template <typename T>
	class List :public Object
	{
	public:
		virtual	bool insert(const T& e) = 0;//ĩβ����
		
		virtual bool insert(int i, const T& e) = 0;//����Ԫ��
		virtual bool remove(int i) = 0;//�Ƴ�Ԫ��
		virtual bool set(int i, const T& e) = 0;//����Ԫ��
		virtual bool get(int i, T& e)const = 0;//��ȡԪ��
		virtual int length()const = 0;//���Ա���
		virtual void clear() = 0;//���

		virtual int find(const T& e)const = 0;//�����Ƿ��ж�Ӧ��Ԫ�� ���ض����±� ��һ�γ���

	};


}


#endif // !List_H

