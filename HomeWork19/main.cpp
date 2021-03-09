#include <iostream>
#include <Windows.h>
#include <math.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]); //Возвращает размер строки
void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
int  to_int_number(char str[]);
int  bin_to_dec(char str[]);
int  hex_to_dec(char str[]);

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
	
	char str_2[] = "NULL Terminated Lines!!!";
	//char str_2[] = "Строка, оканчивающаяся нулём!!!";
			
	to_upper(str_2);
	cout << "\nUpper: " << str_2 << endl;
	to_lower(str_2);
	cout << "\nLower: " << str_2 << endl;
	capitalize(str_2);
	cout << "\nCapitalized: " << str_2 << endl;

	char str_3[] = "Хорошо        живет    на   всете       Винни-Пух!!!";
	shrink(str_3);

	char str_4[] = "H?5(J)5?H";
	is_palindrome(str_4) ? cout << "\nСтрока: \"" << str_4 << "\"  является палиндромом" << endl
	: cout << "Строка: \"" << str_4 << "\"  не является палиндромом" << endl;

	char str_5[] = "+2348937";
	is_int_number(str_5)? cout << "\nСтрока: \"" << str_5 << "\" является числом" << endl
	: cout << "Строка \"" << str_5 << "\" не является числом" << endl;
	
	cout << "\nВ строке содержится число: " <<  to_int_number(str_5) << endl;

	char str_6[] = "0b1111";
	cout << "\nЧисло в строке: \"" << str_6 << "\" соответствует десятичному числу: "
		 << bin_to_dec(str_6) << endl;
	
	char str_7[] = "0xDDD57";
	cout << "\nЧисло в строке: \"" << str_7 << "\" соответствует десятичному числу: "
		 << hex_to_dec(str_7) << endl;
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
	/*int sum = 0;
	for (int i = 0; str[i]; i++)
		++sum;
	return sum;*/

	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{	
	int i = 0;
	for (; str[i]; ++i)
	{
	if (str[i]>=97 && str[i]<=122)
	str[i] -= 32;
	}
}

void to_lower(char str[])
{
	int i = 0;
	for (; str[i]; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
		str[i] += 32;
		//if (str[i] >= 192 && str[i] <= 223) str[i] += 32;
	}	
}

void capitalize(char str[])
{	
	if (str[0] >= 97 && str[0] <= 122) str[0] -= 32;
	int i = 0;
	for (; str[i]; ++i)
	{
		if (str[i-1] == 32 && (str[i] >= 97 && str[i] <= 122))
		str[i] -= 32;
	}
}

//void shrink(char str[])
//{	
//	int k = 0;
//	for (; str[k]; ++k);
//		const int n = k;//почему нельзя инициализировать?
//		cout << k << endl;
//	char str_2[60] = "";	
//	int i = 0; int j = 0;
//	for (; str[i]; ++i)
//	{
//		if (!(str[i+1] == 32 && str[i] == 32))			
//		str_2[j++] = str[i];		
//	}		
//		cout << str_2;	
//}

void shrink(char str[])
{		
	char str_2[60] = "";
	int i = 0; int j = 0;
	for (; str[i]; ++i)
	{
		if (!(str[i+1] == 32 && str[i] == 32))			
		str_2[j++] = str[i];		
	}		
		cout << "\nБез лишних пробелов:\n" << str_2 << endl << endl;	
}

bool is_palindrome(char str[])
{	
	int end = StrLen(str) - 1;
	int start = end / 2;
	bool p_drom = true;
	for (int i = 0; end > start; ++i, --end)
	{
		cout << str[i] << '\t' << str[end] << endl;
		if (str[i] != str[end])
		{
			p_drom = false; break;
		}
	}
	return p_drom;
}

bool is_int_number(char str[])
{
	int i = 0;
	bool number = true; //почему нельзя оставить неинициализированной?
	if (str[0] == '-' || str[0] == '+') i = 1;
	for (; str[i]; ++i)
	{
		if (!(str[i] >= 49 && str[i] <= 57))
		{
			number = false; break;
		}
	}
	return number;
}

int  to_int_number(char str[])
{
	int i = 0, number=0;
	if (str[0] == '-' || str[0] == '+') i = 1;
	for (; str[i]; ++i)
	{
		number *= 10;
		number += str[i] - 48;
	}
	return str[0] == '-' ? number *= -1: number;
}

int  bin_to_dec(char str[])
{
	int end = StrLen(str) - 1;
	int number = 0, start = 0;
	if (str[1] == 'b') start = 2;
	for (int i = 0; end >= start; --end, ++i)
	{		
		number += (str[end]-48) * pow(2, i);
		//cout << number << endl;
	}
	return number;
}

// 0xABC = 10 * 16 ^ 2 + 11 * 16 ^ 1 + 12 * 16 ^ 0 = 2748

int  hex_to_dec(char str[])
{
	int k = 0;
	for (; str[k]; ++k);
	//cout << k << endl;	
	int hex = 0, i = 0, number = 0, start = 0;
	k = k - 1;
	if (str[1] == 'x') start = 2;
	for (; k >= start; --k, ++i)
	{
		if (str[k] == 'A' || str[k] == 'a') hex = 10;
		else if (str[k] == 'B' || str[k] == 'b') hex = 11;
		else if (str[k] == 'C' || str[k] == 'c') hex = 12;
		else if (str[k] == 'D' || str[k] == 'd') hex = 13;
		else if (str[k] == 'E' || str[k] == 'e') hex = 14;
		else if (str[k] == 'F' || str[k] == 'f') hex = 15;
		else hex = str[k] - 48;

		number += hex * pow(16, i);
		//cout << number << endl;
	}
	return number;
}