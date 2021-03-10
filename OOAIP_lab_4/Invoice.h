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
	string currentAccountPayer; // ��������� ���� �����������
	string currentAccountBayer; // ��������� ���� ����������
	string transfer; // ������������� �����
	int Date; // ����
	int operator <(Invoice b); // ���������� ��������� ������
	Invoice(); // �����������
	~Invoice(); // ����������
	static int comfortableDate(int day, int month, int year); // ����� ��� �������������� ���� � ������� ��� ���
	static int getDate(); // ����� ��� ����� ���� � �������
};

//�������������� �������� ��� find_if
struct foName {
	string value;
	int operator()(Invoice a)
	{
		return (a.currentAccountPayer == value);
	}
};

//����� ��� ���������� vector
class VectorInvoice {
	vector <Invoice> VecInvoice;
public:
	VectorInvoice() {}; // �����������
	void readFromFile(fstream& finput); //������ ������ �� �����
	void searchForDateandScore(int find, string currentAccount, foName fo); // ����� ���� ������ � ��������� ���������� ����� �� ���������� ����
	~VectorInvoice() {}; // ����������
};

//����� ��� ���������� Map
class MapInvoice {
	multimap <string, Invoice> MapInvoice;
public:
	void readFromFile(fstream& finput); //������ ������ �� �����
	void searchForDateandScore(int find, string currentAccount); // ����� ���� ������ � ��������� ���������� ����� �� ���������� ����
	~MapInvoice() {}; // ����������
};
