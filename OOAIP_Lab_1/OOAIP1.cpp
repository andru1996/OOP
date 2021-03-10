#include "Set.h"
#include <vld.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int cardinality;
	

	try
	{
		cout << "������� ������ ������� ���������: ";
		cin >> cardinality;
		Set setA(cardinality);
		for (int i = 0; i < cardinality; i++) //���� ���������
			setA.AddElement();
		setA.ShowSet(); //����� �� ������� ������� ���������
		cout << "������� ������ ������� ���������: ";
		cin >> cardinality;
		Set setB(cardinality);
		for (int i = 0; i < cardinality; i++)
			setB.AddElement();
		setB.ShowSet(); //����� �� ������� ������� ���������
		setA.ShowIntersection(setB); //����� �� ������� ��������� ����������� ���� ��������
		cout << setA.IsIntersection(setB) << endl; //����� �� ������� ������������ �� ���������
	}
	catch (int a)
	{
		switch (a)
		{
		case 1:
			cout << "error 1: �������� ������� ������ ��������" << endl;
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}
