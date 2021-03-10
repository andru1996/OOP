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
		cout << "Введите размер первого множества: ";
		cin >> cardinality;
		Set setA(cardinality);
		for (int i = 0; i < cardinality; i++) //ввод элементов
			setA.AddElement();
		setA.ShowSet(); //вывод на консоль первого множества
		cout << "Введите размер второго множества: ";
		cin >> cardinality;
		Set setB(cardinality);
		for (int i = 0; i < cardinality; i++)
			setB.AddElement();
		setB.ShowSet(); //вывод на консоль второго множества
		setA.ShowIntersection(setB); //вывод на консоль элементов пересечения двух множеств
		cout << setA.IsIntersection(setB) << endl; //вывод на консоль пересекаются ли множества
	}
	catch (int a)
	{
		switch (a)
		{
		case 1:
			cout << "error 1: мощность массива больше заданной" << endl;
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}
