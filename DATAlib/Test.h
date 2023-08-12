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

using namespace DATAlib;
using namespace std;
class Test : public Object
{

};



int main()
{
	

	try
	{
		DynamicArray<int> list(10);

		//cout << list.capacity() << endl;
		cout << list.length() << endl;
		for (int i = 0; i < list.length(); i++)
		{
			//int e;
			list.set(i, i+9);
			
		}


		cout << list.set(9,10) << endl;
		for (int i = 0; i < list.length(); i++)
		{
			int e;
			list.get(i,e);
			cout <<  e<< endl;
		}


		cout << list.resize(11) << endl;
		for (int i = 0; i < list.length(); i++)
		{
			int e;
			list.get(i, e);
			cout << e << endl;
		}
		cout << list.length() << endl;

		cout<<	list[55]<<endl;

		for (int i = 0; i < list.length(); i++)
		{
			int e;
			list.get(i, e);
			cout << e << endl;
		}
		THROW_EXCEPTION(AritthmeticException, "text");
		//throw Exception("e", __FILE__, __LINE__);
	}
	catch (const AritthmeticException& e)
	{
		cout << "const AritthmeticException& e" << endl;
		cout << e.message() << endl;
		cout << e.location() << endl;
	}
	catch (const Exception& e)
	{
		cout << "const Exception& e" << endl;
		cout << e.message() << endl;
		cout << e.location() << endl;
	}
	
	return 0;
}