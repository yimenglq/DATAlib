#pragma once
#define _CRT_SECURE_NO_WARNINGS
namespace DATAlib
{
#define THROW_EXCEPTION(e,m) (throw e(m,__FILE__,__LINE__))//����λ�ú�

	class Exception
	{
	protected:
		char* m_message;//������Ϣ
		char* m_location;//����λ��

		void init(const char* message, const char* file, int line);
	public:

		Exception(const char* message);
		Exception(const char* file, int line);
		Exception(const char* message,const char* file, int line);
		
		Exception(const Exception& e);
		Exception& operator = (const Exception& e);

		virtual	const char* message() const;
		virtual	const char* location() const;
		virtual	~Exception()=0;
	};

	class AritthmeticException : public Exception
	{
	public:
		AritthmeticException() :Exception(0) {}
		AritthmeticException(const char* message) :Exception(message) {}
		AritthmeticException(const char* file,int line) :Exception(file,line) {}
		AritthmeticException(const char* message,const char* file, int line) :Exception(message,file,line) {}

		AritthmeticException(const AritthmeticException& e) :Exception(e) {}
		AritthmeticException& operator= (const AritthmeticException& e)
		{
			Exception::operator=(e);
			return *this;
		}
	};

	class NullPointerException : public Exception
	{
	public:
		NullPointerException() :Exception(0) {}
		NullPointerException(const char* message) :Exception(message) {}
		NullPointerException(const char* file, int line) :Exception(file, line) {}
		NullPointerException(const char* message, const char* file, int line) :Exception(message, file, line) {}

		NullPointerException(const NullPointerException& e) :Exception(e) {}
		NullPointerException& operator= (const NullPointerException& e)
		{
			Exception::operator=(e);
			return *this;
		}
	};

}
