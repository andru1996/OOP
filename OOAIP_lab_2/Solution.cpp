#include "Solution.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

//------------------------------Solution-----------------------------
void Solution::SetVariables() {};
void Solution::CalvulateAnswer() {};
void Solution::ShowAnswer() {};

Solution::~Solution() {}
//------------------------------Linear-----------------------------
Linear::Linear() //пустой конструктор
{
	this->variables = new float[2];
	this->answers = new float;
}

Linear::Linear(float a, float b) //конструктор с параметрами
{
	this->variables = new float[2];
	this->answers = new float;
	if (a == 0) throw 1;
	this->variables[0] = a;
	this->variables[1] = b;
}

void Linear::SetVariables() //ввод переменных линейного уравнения
{
	cout << "Введите параметры линейного уровнения:" << endl;
	cout << "Введите переменную a: ";
	cin >> this->variables[0];
	if (this->variables[0] == 0) throw 1;
	cout << "Введите переменную b: ";
	cin >> this->variables[1];
}

void Linear::CalvulateAnswer() // вычисление корня уравнения
{
	this->answers[0] = -this->variables[1] / this->variables[0];
}

void Linear::ShowAnswer() //вывод ответа на консоль
{
	cout << "Ответ линейного уровнения: ";
	cout << "x=" << this->answers[0] << endl;
}

Linear::~Linear() //деструктор
{
	delete[] variables;
	delete[] answers;
}
//------------------------------Square-----------------------------
Square::Square() //пустой конструктор
{
	this->variables = new float[3];
	this->answers = new float[2];
}

Square::Square(float a, float b, float c) //конструктор с параметрами
{
	this->variables = new float[3];
	this->answers = new float[2];
	this->variables[0] = a;
	this->variables[1] = b;
	this->variables[2] = c;
}

void Square::SetVariables() //ввод переменных квадратного уравнения
{
	cout << "Введите параметры квадратного уровнения:" << endl;
	cout << "Введите переменную a: ";
	cin >> this->variables[0];
	cout << "Введите переменную b: ";
	cin >> this->variables[1];
	cout << "Введите переменную c: ";
	cin >> this->variables[2];
}

void Square::CalvulateAnswer() // вычисление корней уравнения
{
	this->d = this->variables[1] * this->variables[1] - 4 * this->variables[0] * this->variables[2]; //вычисление дискриминанта
	if (this->d > 0) //два корня если дискриминант больше 0
	{
		this->answers[0] = (-this->variables[1] + sqrt(this->d)) / (2 * this->variables[0]);
		this->answers[1] = (-this->variables[1] - sqrt(this->d)) / (2 * this->variables[0]);
	}
	if (this->d == 0) //один корень если диксриминант равен 0
	{
		this->answers[0] = -this->variables[1] / (2 * this->variables[0]);
	}
}

void Square::ShowAnswer() //вывод корня, корней или сообщение об их отсутствии на консоль
{
	cout << "Ответ квадратного уровнения: ";
	if (this->d > 0)
	{
		cout << "x1=" << this->answers[0] << "; x2=" << this->answers[1] << endl;
	}
	if (this->d == 0)
	{
		cout << "x=" << this->answers[0] << endl;
	}
	if (this->d < 0)
	{
		cout << "нет корней уровнения" << endl;
	}
}

Square::~Square() //деструктор
{
	delete[] variables;
	delete[] answers;
}
//------------------------------Series-----------------------------

Series::Series() //конструктор
{
	cout << "Введите количество линейных уровнений: ";
	cin >> this->LinearNum;
	cout << "Введите количество квадратных уровнений: ";
	cin >> this->SquareNum;
	int a = this->LinearNum + this->SquareNum;
	this->equation = new Solution * [a];
	for (int i = 0; i < this->LinearNum; i++)
	{
		this->equation[i] = new Linear();
	}
	for (int i = this->LinearNum; i < this->LinearNum + this->SquareNum; i++)
	{
		this->equation[i] = new Square();
	}
}

Series::~Series() //деструктор
{
	for (int i = 0; i < this->LinearNum + this->SquareNum; i++)
	{
		delete this->equation[i];
	}
	delete[] this->equation;
}

void Series::SetVariables() //ввод переменных уравнений
{
	for (int i = 0; i < this->LinearNum + this->SquareNum; i++)
	{
		this->equation[i]->SetVariables();
		this->equation[i]->CalvulateAnswer();
	}
}

void Series::ShowAnswers() //вывод ответов уравнений на консоль
{
	for (int i = 0; i < this->LinearNum + this->SquareNum; i++)
	{
		this->equation[i]->ShowAnswer();
	}
}