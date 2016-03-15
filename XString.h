#pragma once

#include <iostream>

#include "XArray.h"

class XString
{
public:
	XString();

	XString(char* p_string);

	virtual ~XString();

	XString& operator=(XString& p_string);

	XString& operator=(char* p_string);

	char* data() const;

	void print() const;

private:

	XArray<char> m_string;
};

static std::ostream& operator<<(std::ostream& p_out, const XString& p_string)
{
	return p_out << p_string.data();
}

