#include<cstring>
#include "string1.h"
using std::cin;
using std::cout;
int String::num_string = 0;

int String::HowMany()
{
	return num_string;
}

String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_string++;
}
String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_string++;
}
String::String(const String &s)
{
	num_string++;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1,s.str );
}
String::~String()
{
	--num_string;
	delete [] str;
}

String &String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}
String &String::operator=(const char *s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}
char &