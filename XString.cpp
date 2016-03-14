#include "stdafx.h"
#include "XString.h"


XString::XString()
{
}

XString::XString(char* p_string)
{
	std::cout << "calling XString(char* p_string)" << std::endl;
	XArray<char> tmp{ p_string, (int)strlen(p_string) + 1 };
	m_string.operator=( XArray<char>{ p_string, (int)strlen(p_string) + 1 }); // for some reason first element ptr is only copying the ptr
}

XString::~XString()
{
}

XString& XString::operator=(XString& p_string)
{
	
	return *this;
}

XString& XString::operator=(char* p_string)
{
	std::cout << "calling XString::operator=" << std::endl;
	XArray<char> tmp{ p_string, (int)strlen(p_string) + 1 };
	m_string = tmp;

	return *this;
}

char* XString::data() const
{
	return m_string.data();
}

void XString::print() const
{
	std::cout << m_string.data() << std::endl;
}
