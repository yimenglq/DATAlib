#include<stdio.h>

#ifndef Object_h 
#define Object_h

namespace DATAlib
{
	class Object
	{
	

		
	public:

		void* operator new (size_t size) throw();
		void operator delete (void* p);
		void* operator new[](size_t size) throw();
		void operator delete[](void* p);
		virtual	~Object() = 0;

		virtual bool operator==(const Object& obj);
		virtual bool operator!=(const Object& obj);
	};


}


#endif // !Object_h 


