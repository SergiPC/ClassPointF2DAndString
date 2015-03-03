#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "String.h"

String::String()
{
	size = 1;
	str = new char[size];
	str[0] = '\0';
}


String::String(const char* format, ...)
{
	size = 0;
	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;
		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);
		if (res > 0)
		{
			str = new char[res + 1];
			strcpy_s(str, size, tmp);
		}
	}
	if (size == 0)
	{
		str = new char[1];
		clear();
	}
}


String::String(const String& s)
{
	size = strlen(s.str) + 1;
	str = new char[size];
	strcpy_s(str, size, s.str);
}


bool String::operator== (const char* c) const
{
	if (c != NULL)
	{
		if (strcmp(c, str) == 0);
		{
			return true;
		}
	}
	return false;
}


bool String::operator!= (const char* c) const
{
	if (c != NULL)
	{
		if (strcmp(c, str) != 0);
		{
			return true;
		}
	}
	return true;
}


bool String::operator== (const String& s) const
{
	if (strcmp(s.str, str) == 0);
	{
		return true;
	}
	return false;
}


bool String::operator!= (const String& s) const
{
	if (strcmp(s.str, str) != 0);
	{
		return true;
	}
	return false;
}


String& String::operator= (const char* c)
{
	if (c != NULL)
	{
		if (strlen(c) + 1 > size)
		{
			str = new char[strlen(c) + 1];
		}
		else
		{
			clear();
		}
		strcpy_s(str, size, c);
	}
	else
	{
		clear();
	}
	return(*this);
}


String& String::operator= (const String& s)
{
	if (s.length() + 1 > size)
	{
		str = new char[s.length() + 1];
	}
	else
	{
		clear();
	}
	strcpy_s(str, size, s.str);
	return(*this);
}


String& String::operator +=(const char* c)
{
	if (c != NULL)
	{
		if (size < strlen(str) + strlen(c))
		{
			char* aux_str = new char[strlen(str) + 1];
			strcpy_s(aux_str, (strlen(str) + 1), str);
			size = strlen(str) + strlen(c) + 1;
			delete[]str;
			str = new char[size];
			strcpy_s(str, strlen(aux_str), aux_str);
		}
		strcat_s(str, strlen(c), c);
	}
	return(*this);
}


String& String::operator +=(const String& s)
{
	if (size < strlen(str) + strlen(s.str))
	{
		char* aux_str = new char[strlen(str) + 1];
		strcpy_s(aux_str, (strlen(str) + 1), str);
		size = strlen(str) + strlen(s.str) + 1;
		delete[]str;
		str = new char[size];
		strcpy_s(str, strlen(aux_str), aux_str);
	}
	strcat_s(str, strlen(s.str), s.str);
	return(*this);
}


unsigned int String::length() const
{
	return strlen(str);
}


int String::capacity() const
{
	return size;
}


char* String::getString() const
{
	return(str);
}


void String::clear()
{
	str[0] = '\0';
}


String::~String()
{
	delete[] str;
}