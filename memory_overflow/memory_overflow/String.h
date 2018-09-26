//#pragma once
#ifndef STRING_H_
#define STRING_H_
using namespace std;
class String 
{
private:
	char * str;
	int len;
public:
	String(const String &s);
	String(const char *s);
	String();
	~String();
	friend ostream & operator<<(ostream &, const String &);
	String& operator=(const String& a);
};
#endif // !STRING_H_

