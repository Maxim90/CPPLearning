#include "stdafx.h"
#include "XString.h"


XString::XString()
{
}

XString::XString(char* p_string)
{
	XArray<char> tmp{ p_string, (int)strlen(p_string) + 1 };
	m_string = tmp;
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
	XArray<char> tmp{ p_string, (int)strlen(p_string) + 1 };
	m_string = tmp;

	return *this;
}

int XString::getSize() const
{
	return m_string.getSize() - 1; // we do not want the \0
}

char* XString::data() const
{
	return m_string.data();
}

void XString::print() const
{
	std::cout << m_string.data() << std::endl;
}
