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
char* month_name(int k) /* �������� k-�� ������ */
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

//int n = 5; //������ ��� ����������� �� ���������?
	//// ������������� ���������� �������.
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
	// �������������� ����� ��� ����� ���� �����.
	char* fam = new char[128];
	char* im = new char[128];
	char* otch = new char[128];
	// ���� ������.
	cout << "Enter" << "\n";
	cout << "\tSurname: ";
	cin >> fam;
	cout << "\tName: ";
	cin >> im;
	cout << "\tLastname: ";
	cin >> otch;
	// �������������� ����� ��� ����������.
	// ����� ������ ��� ������� � ��������������
	// ������� ������.
	char* rez = new char[strlen(fam) + strlen(im) +
		strlen(otch) + 3];
	//"������" ����������.
	strcat(strcat(strcpy(rez, fam), " "), im);
	strcat(strcat(rez, " "), otch);
	// ������� ������ � ����.
	delete[] fam; //��� ��� ��� ���������� ������???
	delete[] im;
	delete[] otch;
	// ����� ����������.
	cout << "\nResult: " << rez;
	delete[] rez;
}