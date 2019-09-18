#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct base
{
	string surname;
	int day;
	int mouth;
	int year;
};


void write(base* b, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "������� �����:  ";
		cin >> b[i].surname;
		cout << "���� ����������:  ";
		cin >> b[i].day;
		cout << "̳���� ����������:  ";
		cin >> b[i].mouth;
		cout << endl;
		cout << "г� ����������:  ";
		cin >> b[i].year;
		cout << endl;
	}

	ofstream outfile;
	outfile.open("info.dat");
	for (int i = 0; i < size; i++) {
		outfile << "�������: " << b[i].surname << endl
			<< "���� ����������: " << b[i].day << endl
			<< "̳���� ����������: " << b[i].mouth << endl
		    << "г� ����������: " << b[i].year << endl << endl;
	}
}

void read()
{
	string ptr = "info.dat";
	ifstream inFile;
	inFile.open(ptr);



	string str;
	while (!inFile.eof())
	{
		getline(inFile, str);
		cout << str << endl;
	}

	inFile.close();

}
void fo(base* b, int size)
{

	for (int i = 0; i < size; i++)
	{
		if ((b[i].mouth <= 11)&&(b[i].mouth>=9))
		{
			cout << "��������� ������: " << b[i].surname << endl;
		}
	}

}
int main()
{

	system("chcp 1251");
	system("cls");

	int MAX; //���-�� ����������� ���������//
	cout << "ʳ������ �����: ";
	cin >> MAX;
	cout << endl;

	base* b = new base[MAX];
	write(b, MAX);
	cout << "------------------------------" << endl;
	read();
	cout << "------------------------------" << endl;
	fo(b, MAX);

	delete[] b;
	return 0;
}