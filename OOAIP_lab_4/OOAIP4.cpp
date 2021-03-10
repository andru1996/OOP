#include "Invoice.h"
#include <iostream>
#include <fstream>
#include "vld.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	std::fstream finput("Input.txt", std::ios::in);
	try
	{
		if (!finput.is_open())
			throw 1;
	}
	catch (int)
	{
		std::cout << "�� ������� ��������� � �����.";
		exit(1);
	}

	int m, date;
	string currentAccount;
	cout << "Write current account payer's (6 ������): " << endl;
	cin >> currentAccount;
	foName fo;
	fo.value = currentAccount;
	cout << "Write date(dd.mm.yyyy): " << endl;
	date = Invoice::getDate();
	cout << "Vector or Multimap(0 or 1)" << endl;
	cin >> m;
	if (m != 0) // Map
	{
		MapInvoice map;
		map.readFromFile(finput);
		try
		{
			map.searchForDateandScore(date, currentAccount);
		}
		catch (int)
		{
			cout << "��� ���������� ����� �� �������� ��������" << endl;
		}
	}
	else // Vector
	{
		VectorInvoice vec;
		vec.readFromFile(finput);
		try
		{
			vec.searchForDateandScore(date, currentAccount, fo);
		}
		catch (int)
		{
			cout << "��� ���������� ����� �� �������� ��������" << endl;
		}
	}

	return 0;
}