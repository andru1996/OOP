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
Linear::Linear() //������ �����������
{
	this->variables = new float[2];
	this->answers = new float;
}

Linear::Linear(float a, float b) //����������� � �����������
{
	this->variables = new float[2];
	this->answers = new float;
	if (a == 0) throw 1;
	this->variables[0] = a;
	this->variables[1] = b;
}

void Linear::SetVariables() //���� ���������� ��������� ���������
{
	cout << "������� ��������� ��������� ���������:" << endl;
	cout << "������� ���������� a: ";
	cin >> this->variables[0];
	if (this->variables[0] == 0) throw 1;
	cout << "������� ���������� b: ";
	cin >> this->variables[1];
}

void Linear::CalvulateAnswer() // ���������� ����� ���������
{
	this->answers[0] = -this->variables[1] / this->variables[0];
}

void Linear::ShowAnswer() //����� ������ �� �������
{
	cout << "����� ��������� ���������: ";
	cout << "x=" << this->answers[0] << endl;
}

Linear::~Linear() //����������
{
	delete[] variables;
	delete[] answers;
}
//------------------------------Square-----------------------------
Square::Square() //������ �����������
{
	this->variables = new float[3];
	this->answers = new float[2];
}

Square::Square(float a, float b, float c) //����������� � �����������
{
	this->variables = new float[3];
	this->answers = new float[2];
	this->variables[0] = a;
	this->variables[1] = b;
	this->variables[2] = c;
}

void Square::SetVariables() //���� ���������� ����������� ���������
{
	cout << "������� ��������� ����������� ���������:" << endl;
	cout << "������� ���������� a: ";
	cin >> this->variables[0];
	cout << "������� ���������� b: ";
	cin >> this->variables[1];
	cout << "������� ���������� c: ";
	cin >> this->variables[2];
}

void Square::CalvulateAnswer() // ���������� ������ ���������
{
	this->d = this->variables[1] * this->variables[1] - 4 * this->variables[0] * this->variables[2]; //���������� �������������
	if (this->d > 0) //��� ����� ���� ������������ ������ 0
	{
		this->answers[0] = (-this->variables[1] + sqrt(this->d)) / (2 * this->variables[0]);
		this->answers[1] = (-this->variables[1] - sqrt(this->d)) / (2 * this->variables[0]);
	}
	if (this->d == 0) //���� ������ ���� ������������ ����� 0
	{
		this->answers[0] = -this->variables[1] / (2 * this->variables[0]);
	}
}

void Square::ShowAnswer() //����� �����, ������ ��� ��������� �� �� ���������� �� �������
{
	cout << "����� ����������� ���������: ";
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
		cout << "��� ������ ���������" << endl;
	}
}

Square::~Square() //����������
{
	delete[] variables;
	delete[] answers;
}
//------------------------------Series-----------------------------

Series::Series() //�����������
{
	cout << "������� ���������� �������� ���������: ";
	cin >> this->LinearNum;
	cout << "������� ���������� ���������� ���������: ";
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

Series::~Series() //����������
{
	for (int i = 0; i < this->LinearNum + this->SquareNum; i++)
	{
		delete this->equation[i];
	}
	delete[] this->equation;
}

void Series::SetVariables() //���� ���������� ���������
{
	for (int i = 0; i < this->LinearNum + this->SquareNum; i++)
	{
		this->equation[i]->SetVariables();
		this->equation[i]->CalvulateAnswer();
	}
}

void Series::ShowAnswers() //����� ������� ��������� �� �������
{
	for (int i = 0; i < this->LinearNum + this->SquareNum; i++)
	{
		this->equation[i]->ShowAnswer();
	}
}