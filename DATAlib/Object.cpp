#include"Object.h"
#include <malloc.h>

#include<iostream>

using namespace std;
namespace DATAlib
{
	void* Object::operator new (size_t size) throw()
	{
		//cout << "Object::operator new:  size = " << sizeof(size_t) << endl;
		return malloc(size);
	}
	void Object::operator delete (void* p)
	{

		free(p);
	}
	void* Object::operator new[](size_t size) throw()
	{
		//cout << "Object::operator new[]:  size = " << size << endl;
		return malloc(size);
	}
		void Object::operator delete[](void* p)
	{
		free(p);
	}

		Object::~Object()
	{

	}
}

