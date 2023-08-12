#include "Exception.h"
#include<cstring>
#include <stdlib.h>

namespace DATAlib
{

	void DATAlib::Exception::init(const char* message, const char* file, int line)
	{
		m_message = _strdup(message);//�����ַ���
		if (file != NULL)//�����쳣���ļ�
		{
			char sl[16] = { 0 };
			_itoa(line, sl, 10);
			m_location = (char*) malloc(strlen(file) + strlen(sl) + 2);
			m_location = strcpy(m_location, file);
			m_location = strcat(m_location, ":");
			m_location = strcat(m_location, sl);

		}
		else
		{
			m_location = NULL;
		}
	}
	Exception::Exception(const char* message)
	{
		init(message, NULL, 0);
	}
	Exception::Exception(const char* file, int line)
	{
		init(NULL, file, line);
	}
	Exception::Exception(const char* message, const char* file, int line)
	{
		init(message, file, line);
	}

	Exception::Exception(const Exception& e)//���
	{
		m_message = _strdup(e.m_message);
		m_location = _strdup(e.m_location);
	}
	Exception& Exception::operator = (const Exception& e)
	{
		if (this != &e)//�ǲ������ҿ���
		{
			free(m_location);
			free(m_message);

			m_message = _strdup(e.m_message);
			m_location = _strdup(e.m_location);
		}

		return *this;
	}

	const char* Exception::message() const
	{
		return m_message;
	}
	const char* Exception::location() const
	{
		return m_location;
	}
	Exception::~Exception()
	{

	}
}