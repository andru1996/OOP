#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

Set::~Set() //деструктор
{
	delete[] elements;
}

Set::Set() //пустой конструктор
{

}

Set::Set(int cardinality) //конструктор с параметром
{
	this->cardinality = cardinality;
	this->elements = new int[cardinality];
	this->cardinalityNow = 0;
}

void Set::AddElement() //добавление элемента в множество
{
	int element;
	int i;
	cout << "Введите новый элемент множества: " << endl;
	cin >> element;
	for (i = 0; i < cardinalityNow; i++)
	{
		if (this->elements[i] == element)
		{
			cout << "данный элемент существует в множестве" << endl;
			i = -1;
			break;
		}
	}
	if (i >= 0)
	{
		this->elements[cardinalityNow] = element;
		cardinalityNow++;
		if (cardinalityNow > cardinality) throw 1;
	}
}

void Set::ShowSet() //вывод множества на консоль
{
	for (int i = 0; i < this->cardinalityNow; i++)
		cout << this->elements[i]<<" ";
	cout << endl;
}

bool Set::IsIntersection(Set& set) // определение пересечения двух множеств
{
	bool m = false;
	for (int i = 0; i < this->cardinalityNow; i++)
	{
		for (int j = 0; j < set.cardinalityNow; j++)
		{
			if(this->elements[i] == set.elements[j])
			{
				m = true;
				break;
			}
		}
		if (m) break;
	}

	return m;
}

void Set::ShowIntersection(Set& set) //вывод элементов пересечения двух множеств
{
	bool m =false;
	for (int i = 0; i < this->cardinalityNow; i++)
	{
		for (int j = 0; j < set.cardinalityNow; j++)
		{
			if (this->elements[i] == set.elements[j])
			{
				cout << this->elements[i] << " ";
				m = true;
				break;
			}
		}
	}
	if (!m) cout << "множества не пересекаются";
	cout << endl;
}