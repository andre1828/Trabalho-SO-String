// Trabalho1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{

	MyString string("coffee");

	MyString other("coffee");

	cout << string.getString() << "  ==  " << other.getString() << ": " << std::noboolalpha << (string == other) << std::endl;
}
