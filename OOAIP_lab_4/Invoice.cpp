#include "Invoice.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

Invoice::Invoice() {} // конструктор
Invoice::~Invoice() {} // деструктор

//Перегружаем оператор "<" для корректной сортировки
int Invoice::operator <(Invoice b)
{
	return Date < b.Date;
}

//Преобразовываем дату из формата dd.mm.yyyy в числовой формат
int Invoice::comfortableDate(int day, int month, int year)
{
	long long int sum = 0;
	int months[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	sum += day;
	for (int i = 0; i < month - 1; i++)
	{
		sum += months[i];
	}
	sum += 365 * year;
	return sum;
}

void VectorInvoice::readFromFile(fstream& finput) //чтение данных из файла
{
	while (!finput.eof())
	{
		Invoice item;
		int Year, Month, Day;

		finput >> item.currentAccountPayer;
		finput >> item.currentAccountBayer;
		finput >> item.transfer;

		finput >> Day;
		finput.ignore(1, ' '); // пропуск одного символа
		finput >> Month;
		finput.ignore(1, ' ');
		finput >> Year;

		item.Date = Invoice::comfortableDate(Day, Month, Year); //перевод даты в числовой формат
		VecInvoice.push_back(item);
	}
	sort(VecInvoice.begin(), VecInvoice.end());
	finput.close();
}

void MapInvoice::readFromFile(fstream& finput)
{
	while (!finput.eof())
	{
		Invoice item;
		int Year, Month, Day;

		finput >> item.currentAccountPayer;
		finput >> item.currentAccountBayer;
		finput >> item.transfer;

		finput >> Day;
		finput.ignore(1, ' ');
		finput >> Month;
		finput.ignore(1, ' ');
		finput >> Year;

		item.Date = Invoice::comfortableDate(Day, Month, Year);
		MapInvoice.insert(pair <string, Invoice>(item.currentAccountPayer, item));
	}
	finput.close();
}

void VectorInvoice::searchForDateandScore(int date, string currentAccount, foName fo)
{
	bool m = 0; // флаг наличия результата
	vector<Invoice> ::iterator it;

	it = VecInvoice.begin();
	for (it; it != VecInvoice.end(); it++)
	{
		it = find_if(it, VecInvoice.end(), fo);
		if (it != VecInvoice.end())
		{
			if ((it->Date < date) && (it->currentAccountPayer == currentAccount))
			{
				m = 1;
				cout << it->transfer << endl;
			}
		}
		if (it == VecInvoice.end()) break;
	}

	if (m == 0)
	{
		throw 1;
	}
}

void MapInvoice::searchForDateandScore(int date, string currentAccount)
{
	bool m = 0;
	map<string, Invoice> ::iterator it;
	it = MapInvoice.find(currentAccount);
	int countOfKeys = MapInvoice.count(currentAccount);// возврат количества объектов с нужным расчетным счетом
	for (int i = 0; i < countOfKeys; i++)
	{
		if (it != MapInvoice.end())
		{
			if ((it->second.Date < date) && (it->second.currentAccountPayer == currentAccount))
			{
				m = 1;
				cout << it->second.transfer << endl;
			}
			it++;
		}
	}

	if (m == 0)
	{
		throw 1;
	}
}

// Ввод даты с консоли
int Invoice::getDate()
{
	int day, month, year;

	cin >> day;
	cin.ignore(1, ' ');
	cin >> month;
	cin.ignore(1, ' ');
	cin >> year;

	return Invoice::comfortableDate(day, month, year); // возвращаем уже преобразованную дату
}
