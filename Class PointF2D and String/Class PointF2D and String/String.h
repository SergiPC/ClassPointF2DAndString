#ifndef STRING_H
#define STRING_H

#define TMP_STRING_SIZE 4096

class String{

private:

public:
	int size;
	char* str;

	String();
	String(const char* format, ...);
	String(const String& s);
	bool operator== (const char* c) const;
	bool operator!= (const char* c) const;
	bool operator== (const String& s) const;
	bool operator!= (const String& s) const;
	String& operator= (const char* c);
	String& operator= (const String& s);
	String& operator+= (const char* c);
	String& operator+= (const String& s);
	unsigned int length() const;
	int capacity() const;
	char* getString() const;
	void clear();
	~String();
};

#endif