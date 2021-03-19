#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]); //Возвращает размер строки
void to_lower(char str[]);
void shrink(char str[]); //Удаляет лишние пробелы из предложения
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);

bool is_int_number(char str[]); //Проверяет, является ли строка целым числом
int  to_int_number(char str[]); //Возвращает значение десятичного числа, хранящегося в строке
bool is_bin_number(char str[]);
int  bin_to_dec(char str[]);
bool is_hex_number(char str[]);
int hex_to_dec(char str[]);
bool is_mac_address(char str[]);
bool is_ip_address(char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");
	//char str[] = {'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	//cout << str << endl; //Выводится без цикла for!!!
	//cout << sizeof(str) << endl;
	//cout << sizeof("Hello") << endl;

	const int n = 256;
	char str[n] = "";
	cout << (int)'0' << endl;
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << str << endl;//CP866
	//cout << "Длина введенной строки: " << StrLen(str) << " символов" << endl;
	//shrink(str);
	//cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом!" << endl;
	//cout << "Строка " << (is_int_number(str) ? "" : "НЕ ") << "является числом!" << endl;
	//cout << str << endl;
	//cout << "Значение введенного числа: " << to_int_number(str)*2 << endl;

	//cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом!" << endl;
	//cout << str << "(bin) = " << bin_to_dec(str) << "(dec)" << endl;
	
	//cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является hex числом!" << endl;
	cout << str << "(hex) = " << hex_to_dec(str) << "(dec)" << endl;

	//cout << "Строка " << (is_mac_address(str) ? "" : "НЕ ") << "является MAC-адресом!" << endl;
	
	//cout << "Строка " << (is_ip_address(str) ? "" : "НЕ ") << "является IP-адресом!" << endl;
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

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
		str[i] = tolower(str[i]);
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0)) || str[0] == ' ')		
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j+1];
			}
			i--;
		}
	}	
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == symbol)		
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

bool is_palindrome(char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1]{};	
	char* revbuffer;	
	strcpy_s(buffer, n+1, str);	
	revbuffer = _strrev(buffer);		
	remove_symbol(buffer, ' ');	
	remove_symbol(revbuffer, ' ');	
	int result = _stricmp(buffer, revbuffer);
	//delete[] buffer;
	delete[] revbuffer;
	
	return result ? false : true;
}

bool is_int_number(char str[])
{
	cout << atoi(str) << endl; //преобразует в число до первого нечислового символа
	return atoi(str);
}

int  to_int_number(char str[])
{	
	return atoi(str);
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{		
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') return false;		
		if (str[i-1] == ' ' && str[i] == ' ' && str[i+1] == ' ') return false; //допускается только 2 пробела
	}
	return true;
}

int bin_to_dec(char str[])
{
	if (!is_bin_number(str)) return 0;	
	char* end;	
	return strtol(str, &end, 2); //берет число из строки до первого нечислового символа
}

bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= 'a' && str[i] <= 'f')
			&& !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != ' ') return false;

		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ') return false; //допускается только 2 пробела
	}
	return true;
}

int hex_to_dec(char str[])
{
	if (!is_hex_number(str)) return 0;	
	char* end;
	return strtol(str, &end, 16); //берет число из строки до первого нечислового символа
}

bool is_mac_address(char str[])
{
	int n = strlen(str);
	int numbers = 0, delims = 0; //numbers - количестко hex чисел до разделителя, delims - разделитель (двоеточие или минус)
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') i++; //если пробел, идем к следующему символу
		if ((str[i] == ':' || str[i] == '-') && str[i + 1] == 0) return false; //если нет последнего октета
		if (!(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= 'a' && str[i] <= 'f')
			&& !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != ':' && str[i] != '-') return false; //допустимые символы в строке
		if (str[i] != ':' && str[i] != '-') numbers++; //считаем кол-во hex-чисел до разделителя
		if (numbers > 2) return false; //если кол-во hex-чисел до разделителя больше 2-х
		if (str[i] == ':' || str[i] == '-')
		{
			if (numbers == 1 || numbers == 0) return false; //если одно hex-чисело до разделителя или их нет
			numbers = 0;
			delims++;
		}
	}
	if (delims != 5) return false; //разделителей должно быть ровно 5
	return true;
}

bool is_ip_address(char str[])
{		
	int number = 0, dots = 0; //number - число между точками; dots - количество точек
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') i++; //если пробел, идем к следующему символу
		if (str[i] == '.' && str[i + 1] == 0) return false; //если нет последнего октета
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') return false; //допустимые символы в строке
		if (str[i] != '.') //считаем число до разделителя
		{
			number *= 10;
			number += str[i] - 48;
		}		
		if (number > 255) return false; //число не должно быть больше 255
		if (str[i] == '.')
		{
			//cout << number << '\n'; //отладочное
			number = 0;
			dots++;
		}
	}
	//cout << number << '\n' << "всего точек: " << dots << '\n'; //отладочное
	if (dots != 3) return false; //точек-разделителей должно быть ровно 3
	return true;	
}