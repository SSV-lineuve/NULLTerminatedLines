#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]); //���������� ������ ������
void to_lower(char str[]);
void shrink(char str[]); //������� ������ ������� �� �����������
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);

bool is_int_number(char str[]); //���������, �������� �� ������ ����� ������
int  to_int_number(char str[]); //���������� �������� ����������� �����, ����������� � ������
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
	//cout << str << endl; //��������� ��� ����� for!!!
	//cout << sizeof(str) << endl;
	//cout << sizeof("Hello") << endl;

	const int n = 256;
	char str[n] = "";
	cout << (int)'0' << endl;
	cout << "������� ������: ";
	InputLine(str, n);
	cout << str << endl;//CP866
	//cout << "����� ��������� ������: " << StrLen(str) << " ��������" << endl;
	//shrink(str);
	//cout << "������ " << (is_palindrome(str) ? "" : "�� ") << "�������� �����������!" << endl;
	//cout << "������ " << (is_int_number(str) ? "" : "�� ") << "�������� ������!" << endl;
	//cout << str << endl;
	//cout << "�������� ���������� �����: " << to_int_number(str)*2 << endl;

	//cout << "������ " << (is_bin_number(str) ? "" : "�� ") << "�������� �������� ������!" << endl;
	//cout << str << "(bin) = " << bin_to_dec(str) << "(dec)" << endl;
	
	//cout << "������ " << (is_hex_number(str) ? "" : "�� ") << "�������� hex ������!" << endl;
	//cout << str << "(hex) = " << hex_to_dec(str) << "(dec)" << endl;

	cout << "������ " << (is_mac_address(str) ? "" : "�� ") << "�������� MAC-�������!" << endl;
	
	//cout << "������ " << (is_ip_address(str) ? "" : "�� ") << "�������� IP-�������!" << endl;
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
		//�������� ����� �������� ����� ������� � � ����� ������
		{
			for (int j = i; str[j]; j++)// ���� ������� j=i+1, �� ����� ������ ��������
			{
				str[j] = str[j+1];// �������� ������ �����
			}
			i--;//��� ����� ��� ������� �� ��� �������
		}
	}

	//for (int i = 0; str[i]; i++)
	//{
	//	while (str[i] == ' ' && str[i + 1] == ' ') //��������� �� ���� (if) �������, � ���� (while) �������
	//	{
	//		for (int j = i; str[j]; j++)// ���� ������� j=i+1, �� ����� ������ ��������
	//		{
	//			str[j] = str[j + 1];// �������� ������ �����
	//		}
	//	}
	//}
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
	//strcpy(buffer, str);// ���������� ������ ��������������, ��� ������� ������������
	strcpy_s(buffer, n+1, str);// �������� ������ str � ����� buffer
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n/2; i++)// ���������� ����� �� �������� ������
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')//����� ����� ������� ���� �������
			return false;
		if (str[i] == ' ' && str[i+1] == ' ')//����� ����� ������� ������ 1 ������
			return false;
	}
	return true;
}

int  to_int_number(char str[])
{
	if(!is_int_number(str)) return 0;
	int number = 0; //�������� �����
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			number *= 10; //�������� ����� �� ���� ������ �����, ����� ���������� ������� ������ ��� ��������� �����
			number += str[i] - 48; //48 - ASCII-��� ������� '0'
		}
	}
	return number;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{		
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') return false;		
		if (str[i-1] == ' ' && str[i] == ' ' && str[i+1] == ' ') return false; //����������� ������ 2 �������
	}
	return true;
}

int bin_to_dec(char str[])
{
	if (!is_bin_number(str)) return 0;
	int decimal = 0;
	int weight = 1; //������� ����������� ������� (2 � �����. �������)
	//remove_symbol(str, ' '); //����� ��� ������� �������� � pow()
	int n = strlen(str);
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}		
	}
	/*for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * pow(2, --n);
		}
	}*/
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= 'A' && str[i] <= 'F')
		&& !(str[i] >= 'a' && str[i] <= 'f')
		&& !(str[i] >= '0' && str[i] <= '9')
		&& str[i] != ' ') return false;

		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ') return false; //����������� ������ 2 �������
	}
	return true;
}

int hex_to_dec(char str[])
{
	if (!is_hex_number(str)) return 0;
	int hex = 0, number = 0;
	int weight = 1; //������� ����������� ������� (2 � �����. �������)
	//remove_symbol(str, ' '); //����� ��� ������� �������� � pow()
	int n = strlen(str);
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] == 'A' || str[i] == 'a') hex = 10;
		else if (str[i] == 'B' || str[i] == 'b') hex = 11;
		else if (str[i] == 'C' || str[i] == 'c') hex = 12;
		else if (str[i] == 'D' || str[i] == 'd') hex = 13;
		else if (str[i] == 'E' || str[i] == 'e') hex = 14;
		else if (str[i] == 'F' || str[i] == 'f') hex = 15;
		else hex = str[i] - 48;
		
		if (str[i] != ' ')
		{
			number += hex * weight;
			weight *= 16;
		}
	}
	/*for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * pow(2, --n);
		}
	}*/
	return number;
}

bool is_mac_address(char str[])
{
	int n = strlen(str);
	int numbers = 0, delims = 0; //numbers - ���������� hex ����� �� �����������, delims - ����������� (��������� ��� �����)
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') i++; //���� ������, ���� � ���������� �������
		if ((str[i] == ':' || str[i] == '-') && str[i + 1] == 0) return false; //���� ��� ���������� ������
		if (!(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= 'a' && str[i] <= 'f')
			&& !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != ':' && str[i] != '-') return false; //���������� ������� � ������
		if (str[i] != ':' && str[i] != '-') numbers++; //������� ���-�� hex-����� �� �����������
		if (numbers > 2) return false; //���� ���-�� hex-����� �� ����������� ������ 2-�
		if (str[i] == ':' || str[i] == '-')
		{
			if (numbers == 1 || numbers == 0) return false; //���� ���� hex-������ �� ����������� ��� �� ���
			numbers = 0;
			delims++;
		}
	}
	if (delims != 5) return false; //������������ ������ ���� ����� 5
	return true;
}

bool is_ip_address(char str[])
{		
	int number = 0, dots = 0; //number - ����� ����� �������; dots - ���������� �����
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') i++; //���� ������, ���� � ���������� �������
		if (str[i] == '.' && str[i + 1] == 0) return false; //���� ��� ���������� ������
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') return false; //���������� ������� � ������
		if (str[i] != '.') //������� ����� �� �����������
		{
			number *= 10;
			number += str[i] - 48;
		}		
		if (number > 255) return false; //����� �� ������ ���� ������ 255
		if (str[i] == '.')
		{
			//cout << number << '\n'; //����������
			number = 0;
			dots++;
		}
	}
	//cout << number << '\n' << "����� �����: " << dots << '\n'; //����������
	if (dots != 3) return false; //�����-������������ ������ ���� ����� 3
	return true;	
}