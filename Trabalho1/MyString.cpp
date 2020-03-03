#include "MyString.h"
#include <iostream>

using namespace std;

const char* _string;

MyString::MyString() {
	cout << "default constructor\n";
	_string = "unitialized";
}

MyString::MyString(char character) {
	cout << "MyString(char) constructor\n";
	_string = &character;
}

MyString::MyString(const char* string) {
	cout << "MyString(const char*) constructor\n";
	_string = string;
}

const char* MyString::getString() {
	return _string;
}

int MyString::getLength() {

	int count = 0;
	const char* current = _string;
	char currentValue = *current;

	while (currentValue != '\0')
	{
		count++;
		current++;
		currentValue = *current;
	}

	return count;
}

int MyString::strLength(const char* string) {
	int count = 0;
	const char* current = string;
	char currentValue = *current;

	while (currentValue != '\0')
	{
		count++;
		current++;
		currentValue = *current;
	}

	return count;
}

int MyString::indexOf(const char character) {

	int count = 0;
	bool found = false;

	while (*(_string + count) != '\0')
	{
		if (*(_string + count) == character)
		{
			found = true;
			break;
		}
		count++;
	}

	if (found)
	{
		return count;
	}
	else
	{
		return -1;
	}
}

void MyString::operator=(const char& other) {
	_string = &other;
}

MyString* MyString::operator+(const char* other) {
	int size = this->getLength() + this->strLength(other) + 1;
	char* newString = new char[size];

	int count = 0;
	const char* current = _string;
	char currentValue = *current;

	while (currentValue != '\0')
	{
		newString[count] = *current;
		current++;
		count++;
		currentValue = *current;
	}

	//count--;
	current = other;
	currentValue = *current;

	while (currentValue != '\0')
	{
		newString[count] = *current;
		current++;
		count++;
		currentValue = *current;
	}

	newString[size] = '\0';

	return new MyString(newString);
}

/*ostream& operator<< (ostream& os, const MyString other) {
	os << other.getString();
}*/

const char& MyString::operator[](const int index) {

	if (index >= this->getLength()) {
		cout << "Index out of bounds" << endl;
		exit(1);
	}

	return *(_string + index);
}

bool MyString::operator==(MyString other) {

	if (other.getLength() != this->getLength())
		return false;

	for (int i = 0; i < this->getLength(); i++)
	{
		if (other[i] != this->_string[i]) {
			return false;
		}
	}

	return true;
}
bool MyString::operator!=(MyString other) {

	if (other.getLength() != this->getLength())
		return true;

	for (int i = 0; i < this->getLength(); i++)
	{
		if (other[i] != this->_string[i]) {
			return true;
		}
	}

	return false;
}

MyString::~MyString() {
	cout << "deleting " << _string << endl;
	//delete[] _string;
}

