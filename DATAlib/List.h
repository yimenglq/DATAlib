#ifndef List_H
#define List_H
#include"Object.h"
namespace DATAlib
{

	//线性表
	template <typename T>
	class List :public Object
	{
	public:
		virtual	bool insert(const T& e) = 0;//末尾插入
		
		virtual bool insert(int i, const T& e) = 0;//插入元素
		virtual bool remove(int i) = 0;//移除元素
		virtual bool set(int i, const T& e) = 0;//设置元素
		virtual bool get(int i, T& e)const = 0;//获取元素
		virtual int length()const = 0;//线性表长度
		virtual void clear() = 0;//清除

		virtual int find(const T& e)const = 0;//查找是否有对应的元素 返回对于下标 第一次出现

	};


}


#endif // !List_H

