#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Invoice {
public:
	string currentAccountPayer; // расчетный счет плательщика
	string currentAccountBayer; // расчетный счет покупателя
	string transfer; // перечисляемая сумма
	int Date; // дата
	int operator <(Invoice b); // перегрузка оператора меньше
	Invoice(); // конструктор
	~Invoice(); // диструктор
	static int comfortableDate(int day, int month, int year); // метод для преобразования даты в удобный нам вид
	static int getDate(); // метод для ввода даты с консоли
};

//Функциональный аргумент для find_if
struct foName {
	string value;
	int operator()(Invoice a)
	{
		return (a.currentAccountPayer == value);
	}
};

//класс для контейнера vector
class VectorInvoice {
	vector <Invoice> VecInvoice;
public:
	VectorInvoice() {}; // конструктор
	void readFromFile(fstream& finput); //чтение данных из файла
	void searchForDateandScore(int find, string currentAccount, foName fo); // вывод сумм снятых с заданного расчетного счета до задаваемой даты
	~VectorInvoice() {}; // деструктор
};

//класс для контейнера Map
class MapInvoice {
	multimap <string, Invoice> MapInvoice;
public:
	void readFromFile(fstream& finput); //чтение данных из файла
	void searchForDateandScore(int find, string currentAccount); // вывод сумм снятых с заданного расчетного счета до задаваемой даты
	~MapInvoice() {}; // деструктор
};
