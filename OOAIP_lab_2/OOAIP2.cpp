#include "Solution.h"
#include <vld.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		Series a;
		a.SetVariables();
		a.ShowAnswers();
	}
	catch (int a)
	{
		switch (a)
		{
		case 1:
			cout << "error 1: переменная не может быть равна 0" << endl;
			break;
		case 2:
			cout << "error 2: нет ответа. Решите уровнение" << endl;
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}