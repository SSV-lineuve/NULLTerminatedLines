#include <iostream>
using namespace std;
const int n = 15;

void main()
{
	char* month_name(int);
	/* ------------- */
	for (int i = 0; i < n; i++)
		cout << "Month number " << i << " - " <<
		month_name(i) << "\n";
}
/* ------------------------------------------- */
char* month_name(int k) /* Название k-го месяца */
{
	static char* name[] = {
	"none","January",
	"February","March","April",
	"May","June","July","August",
	"September","October","November",
	"December"
	};
	return (k < 1 || k>12) ? name[0] : name[k];
}

//int n = 5; //Почему тут допускается не константа?
	//// Инициализация строкового массива.
	//char line[5] = { 'C','a','t','!','\0' };
	//
	//	cout << "Word: ";
	//	for (int i = 0; i < n; i++)
	//		cout << line[i];

#include <iostream>
#include <string.h>
using namespace std;
void main()
{
	// Резервирование места для ввода трех строк.
	char* fam = new char[128];
	char* im = new char[128];
	char* otch = new char[128];
	// Ввод данных.
	cout << "Enter" << "\n";
	cout << "\tSurname: ";
	cin >> fam;
	cout << "\tName: ";
	cin >> im;
	cout << "\tLastname: ";
	cin >> otch;
	// Резервирование места для результата.
	// Нужно учесть два пробела и результирующий
	// нулевой символ.
	char* rez = new char[strlen(fam) + strlen(im) +
		strlen(otch) + 3];
	//"Сборка" результата.
	strcat(strcat(strcpy(rez, fam), " "), im);
	strcat(strcat(rez, " "), otch);
	// Возврат памяти в кучу.
	delete[] fam; //Где для них выделяется память???
	delete[] im;
	delete[] otch;
	// Вывод результата.
	cout << "\nResult: " << rez;
	delete[] rez;
}