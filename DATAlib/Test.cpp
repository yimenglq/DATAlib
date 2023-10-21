#pragma once
#include"Object.h"

#include"Exception.h"
#include"List.h"
#include"SeqList.h"

#include<iostream>
#include "StaticList.h"
#include"DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"

#include"SmartPointers.h"
#include"LinkList.h"
#include"Exception.h"
#include"StaticLinkList.h"
#include"SharedPointer.h"
#include"LoopLinkList.h"


using namespace DATAlib;
using namespace std;
class Test :	public Object
{
public:
	int c;
	int l;

	bool operator ==(const Test& e)
	{
		bool ret = 0;
		if ((c == e.c) && (l == e.l))
		{
			ret = 1;
		}
		return ret;
	}
};



class A/*:public Object*/
{
	int a;
public:
	A(int c) :a(c) {}

	A()
	{
		cout << "A()" << endl;
		a = 0;
	}

	void Seta(int i)
	{
		a = i;
	}

	int geta()
	{
		return a;
	}


	int geta()const
	{
		return a;
	}

   virtual void clea()
	{
	   
		cout << "A::clea()" << endl;
		c();
	}
	virtual	void c()
   {
		cout << "A::c()" << endl;
   }

	virtual	~A()
	{
		cout << "~A()" << endl;
		clea();
		
	}

	bool operator==(const A& a)
	{
		return this == &a;
	}

	bool operator!=(const A& a)
	{
		return !(*this==a);
	}
};


class B : public A
{
	int b;
public:

	B():A()
	{
		cout << "B()" << endl;
		b = 0;
	}

	virtual	void c() override
	{
		cout << "B::c()" << endl;
	}


	virtual void clea() override
	{
		cout << "B::clea()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
		//A::c();
		A::clea();
		

	}
};

class C
{
	C();
public:
	static	C* creat()
	{
		C* ret = new C();
		return ret;
	}


};

class D :public A,public Test
{
	B v;
public:
	D():A(),Test(),v()
	{
		cout << "D()" << endl;

	}


};

class text
{
public:
	text(int a = NULL):val(a) { cout << "text() \t";}

	~text() { cout << "~text()"; }


	bool operator==(const text& a)
	{
		return this == &a;
	}

	bool operator!=(const text& a)
	{
		return !(*this == a);
	}


public:
	int val;
};

int main()
{

	/*B c;
	A* v = reinterpret_cast<A*>(&c);
	v->clea();*/


	/*StaticLinkList<int, 3> list;

	for (int i = 0; i < 3; i++)
	{
		list.insert(0, i);
	}
	list.remove(	list.find(list.current()));
	cout<< list.current() <<endl;
	*/

	//D c;

	/*A* lpv = new A();
	const	SmartPointers<A> v = new A();*/

	/*SharedPointer<A> sp = new A();
	const SharedPointer<A> csp = sp;
	SharedPointer<A> NUsp;
	NUsp = sp;
	sp->Seta(100);

	std::cout << sp.getRel() << endl;

	std::cout << sp->geta() << endl;
	std::cout << csp->geta() << endl;
	std::cout << NUsp->geta() << endl;
	std::cout << "比较"<<(NUsp == csp) << endl;
	std::cout << (NUsp != csp) << endl;*/
	
	text c1 (1);
	/*text&& c2 = static_cast<text&&>(c1);*/ 
	text&& c3 = text(3);
	/*text& c4 = c3;
	c3 = c4;*/
	/*A c2(2);
	A c3(3);*/
	//LinkList<A> c;
	LoopLinkList<text> c;
	c.insert(c1);
	c.insert(c3);
	//c.insert(c3);
	/*for (c.move(0); !c.end(); c.next())
	{
		cout << "开始" << endl;
		cout << c.current().geta() << endl;
	}*/

	//cout << "零号元素更改之前" << c.get(0).geta() << endl;
	//c.set(0, c2);
	//cout << "零号元素更改后" << c.get(0).geta() << endl;


	/*for (c.move(0); !c.end(); c.next())
	{
		cout << "删除零号元素之前 " << endl;
		cout << c.current().geta() << endl;

	}*/
	c.remove(0);


	/*for (c.move(0); !c.end(); c.next())
	{
		cout << "删除零号元素" << endl;
		cout << c.current().geta() << endl;

	}*/
	 


	return 0;
}