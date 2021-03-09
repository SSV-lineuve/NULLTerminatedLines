#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]); //Возвращает размер строки

void main()
{
	setlocale(LC_ALL, "Russian");
	//char str[] = {'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;
	//cout << sizeof("Hello") << endl;

	const int n = 20;
	char str[n] = "";
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << str << endl;//CP866

	int sum = StrLen(str);
	cout << sum << endl;
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);//CP1251	
	SetConsoleCP(866);
}

int StrLen(char str[])
{
	int sum = 0;
	for (int i = 0; str[i]; i++)		
	++sum;
	return sum;
}