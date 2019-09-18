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
		cout << "Прізвище друга:  ";
		cin >> b[i].surname;
		cout << "День народження:  ";
		cin >> b[i].day;
		cout << "Місяць народження:  ";
		cin >> b[i].mouth;
		cout << endl;
		cout << "Рік народження:  ";
		cin >> b[i].year;
		cout << endl;
	}

	ofstream outfile;
	outfile.open("info.dat");
	for (int i = 0; i < size; i++) {
		outfile << "Прізвище: " << b[i].surname << endl
			<< "День народження: " << b[i].day << endl
			<< "Місяць народження: " << b[i].mouth << endl
		    << "Рік народження: " << b[i].year << endl << endl;
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
			cout << "Народився восени: " << b[i].surname << endl;
		}
	}

}
int main()
{

	system("chcp 1251");
	system("cls");

	int MAX; //кол-во экземпляров структуры//
	cout << "Кількість друзів: ";
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