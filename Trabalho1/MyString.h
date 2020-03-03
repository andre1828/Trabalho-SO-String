#pragma once
class MyString
{
private:
	const char* _string;

public:

	MyString();

	MyString(char);

	MyString(const char*);

	const char* getString();

	int getLength();

	int indexOf(const char);

	//ostream& operator<<(const char&);

	void operator=(const char&);

	MyString* operator+(const char* other);

	const char& operator[](int index);

	bool operator==(MyString other);

	bool operator!=(MyString other);

	~MyString();

	int strLength(const char* string);
};

