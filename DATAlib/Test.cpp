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



class A
{
	int a;
public:

	A()
	{
		cout << "A()" << endl;
		a = 0;
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

int main()
{

	/*B c;
	A* v = reinterpret_cast<A*>(&c);
	v->clea();*/


	StaticLinkList<int, 3> list;
	

	return 0;
}