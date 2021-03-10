#include "Shape.h"
#include <vld.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		Shape* sh1;
		char T;
		cout << "Type: ";
		cin >> T;
		sh1 = Shape::createShape(T);
		if (!sh1) return 0;
		sh1->info();
		Shape* sh2;
		cout << "Type: ";
		cin >> T;
		sh2 = Shape::createShape(T);
		if (!sh2) return 0;
		sh2->info();
		cout << sh1->IsShapeInclude(sh2) << endl;
		cout << sh2->IsShapeInclude(sh1) << endl;
		cout << sh1->IsShapeIntersect(sh2) << endl;
		cout << sh1->IsAreaMore(sh2) << endl;
		/*while (true)
		{
			double grad;
			cout << "Rotate: ";
			cin >> grad;
			if (grad == 0) break;
			sh1->Rotate(grad);
			sh1->info();
		}*/

		delete sh1;
		delete sh2;
	}
	catch (int a)
	{
		/*switch (a)
		{
		case 1:
			cout << "" << endl;
			break;
		case 2:
			break;
		default:
			break;
		}*/
	}


	system("pause");
	return 0;
}