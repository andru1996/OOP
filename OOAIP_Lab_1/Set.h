#pragma once

class Set
{
private:
	int cardinality; //задаваемая мощность множества
	int cardinalityNow; //нынешняя мощность множества
	int* elements = nullptr; //массив элементов множества

public:
	Set(); //пустой контсруктор
	Set(int); //конструктор с параметром

	void AddElement(); //дабавление элемента множества
	void ShowSet(); //вывод множества на консоль
	bool IsIntersection(Set&); // определение пересечения двух множеств
	void ShowIntersection(Set&); //вывод элементов пересечения двух множеств
	
	~Set(); //деструктор
};