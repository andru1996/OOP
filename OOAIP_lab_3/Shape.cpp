#include "vld.h"
#include "Shape.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;


//-------------------------------Основа----------------------------
void Shape::info() {};
Shape::~Shape() {};
void Shape::calculateParam() {};
void Shape::showParam() {};
void Shape::Move(double x, double y) {};
void Shape::Rotate(double grad) {};
double Shape::getParam() { return NULL; };
double Shape::getArea() { return NULL; };
double Shape::getPerimeter() { return NULL; };
double Shape::getRadOP() { return NULL; };
double Shape::getRadVP() { return NULL; };
Point Shape::getCG() { Point x; x.x = 0; x.y = 0; return x; };
bool Shape::IsAreaMore(Shape* shape) { return NULL; };
bool Shape::IsPointInclude(Point x) { return NULL; };
bool Shape::IsShapeInclude(Shape* shape) { return NULL; };
bool Shape::IsShapeIntersect(Shape* shape) { return NULL; }

//-----------------------------------Квадрат--------------------------------

void Rectangle::info()
{
	cout << "Прямоугольник" << endl;
	cout << "Вершины:" << endl;
	for (int i = 0; i <= 3; i++)
	{
		cout << "Вершина "<< i+1 <<": (" << arc[i].x << "," << arc[i].y << ");" << endl;
	}
}

bool Rectangle::IsRectangle() //функция определяющая квадрат ли это по координатам
{
	int kol90 = 0;
	for (int i = 0; i <= 3; i++)
	{
		double x1 = arc[(i + 1) % 4].x - arc[i].x;
		double y1 = arc[(i + 1) % 4].y - arc[i].y;
		double x2 = arc[(i + 2) % 4].x - arc[i].x;
		double y2 = arc[(i + 2) % 4].y - arc[i].y;
		double x3 = arc[(i + 3) % 4].x - arc[i].x;
		double y3 = arc[(i + 3) % 4].y - arc[i].y;
		double f1 = acos((x1 * x2 + y1 * y2) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)))) * 180 / M_PI;
		double f2 = acos((x3 * x2 + y3 * y2) / (sqrt(pow(x3, 2) + pow(y3, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)))) * 180 / M_PI;
		double f3 = acos((x1 * x3 + y1 * y3) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x3, 2) + pow(y3, 2)))) * 180 / M_PI;
		if (round(f1) == 90) kol90++;
		if (round(f2) == 90) kol90++;
		if (round(f3) == 90) kol90++;
	}
	if (kol90 == 4) return true;
	return false;
}

Rectangle::Rectangle()
{
	Id = 'R';
	arc = new Point[4];
	while (true)
	{
		cout << "Введите координаты прямоугольника:" << endl;
		for (int i = 0; i <= 3; i++)
		{
			cout << "Введите координаты вершины " << i + 1 << ":";
			cin >> arc[i].x >> arc[i].y;
		}
		if (IsRectangle()) break;
		else
		{
			cout << "Координаты не соответствуют фигуре. Повторите ввод координат." << endl;
		}
	}
}

Rectangle::~Rectangle()
{
	delete[] arc;
}

double Rectangle::getParam()
{
	a = sqrt(pow((arc[1].x - arc[0].x), 2) + pow((arc[1].y - arc[0].y), 2));
	b = sqrt(pow((arc[2].x - arc[0].x), 2) + pow((arc[2].y - arc[0].y), 2));
	diagonal = sqrt(pow((arc[3].x - arc[0].x), 2) + pow((arc[3].y - arc[0].y), 2));
	if (a > b)
	{
		double c;
		c = a;
		a = b;
		b = c;
	}
	if (a > diagonal)
	{
		double c;
		c = a;
		a = diagonal;
		diagonal = c;
	}
	if (b > diagonal)
	{
		double c;
		c = b;
		b = diagonal;
		diagonal = c;
	}

	return a;
}

double Rectangle::getArea()
{
	getParam();
	area = a * b;
	if (area <= 0) throw 2;
	return area;
}

double Rectangle::getPerimeter()
{
	getParam();
	perimeter = (a + b) * 2;
	if (perimeter <= 0) throw 3;
	return perimeter;
}

Point Rectangle::getCG()
{
	Point CG;
	getParam();
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (sqrt(pow((arc[i].x - arc[j].x), 2) + pow((arc[i].y - arc[j].y), 2)) == diagonal)
			{
				if (arc[i].x <= arc[j].x) CG.x = (arc[j].x - arc[i].x) / 2 + arc[i].x;
				else CG.x = (arc[i].x - arc[j].x) / 2 + arc[j].x;

				if (arc[i].y <= arc[j].y) CG.y = (arc[j].y - arc[i].y) / 2 + arc[i].y;
				else CG.y = (arc[i].y - arc[j].y) / 2 + arc[j].y;
			}
		}
	}
	centerOfGravity = CG;
	return CG;
}

double Rectangle::getRadOP()
{
	getParam();
	RadOP = diagonal / 2;
	if (RadOP <= 0) throw 5;
	return RadOP;
}

double Rectangle::getRadVP()
{
	getParam();
	if (a == b) RadVP = a / 2;
	else cout << "нельзя вписать окружность" << endl;
	if (RadVP < 0) throw 6;
	return RadVP;
}

void Rectangle::calculateParam()
{
	getParam();
	getArea();
	getPerimeter();
	getCG();
	getRadOP();
	getRadVP();
}

void Rectangle::showParam()
{
	cout << "стороны: a-" << a << ", b-" << b << endl;
	cout << "центр тяжести: (" << centerOfGravity.x <<"," <<centerOfGravity.y <<")" << endl;
	cout << "площадь: " << area << endl;
	cout << "периметр: " << perimeter << endl;
	cout << "радиус описанной окружности: " << RadOP << endl;
	cout << "радиус вписанной окружности: " << RadVP << endl;
}

void Rectangle::Move(double x, double y)
{
	for (int i = 0; i <= 3; i++)
	{
		arc[i].x += x;
		arc[i].y += y;
	}
}

void Rectangle::Rotate(double grad)
{
	getCG();
	for (int i = 0; i <= 3; i++)
	{
		Point oldArc = arc[i];
		oldArc.x = oldArc.x - centerOfGravity.x;
		oldArc.y = oldArc.y - centerOfGravity.y;
		arc[i].x = (oldArc.x * cos(grad * (M_PI / 180))) - (oldArc.y * sin(grad * (M_PI / 180)));
		arc[i].y = (oldArc.x * sin(grad * (M_PI / 180))) + (oldArc.y * cos(grad * (M_PI / 180)));
		arc[i].x = arc[i].x + centerOfGravity.x;
		arc[i].y = arc[i].y + centerOfGravity.y;
	}
}

bool Rectangle::IsPointInclude(Point x)
{
	for (int i = 0; i <= 3; i++)
	{
		if (arc[i].x == x.x && arc[i].y == x.y) return true;
	}
	double sum = 0;
	for (int i = 0; i <= 2; i++)
	{
		double Ta = sqrt(pow((arc[i].x - x.x), 2) + pow((arc[i].y - x.y), 2));
		double Tb = sqrt(pow((arc[i + 1].x - x.x), 2) + pow((arc[i + 1].y - x.y), 2));
		double Tc = sqrt(pow((arc[i + 1].x - arc[i].x), 2) + pow((arc[i + 1].y - arc[i].y), 2));
		double f = acos((pow(Ta, 2) + pow(Tb, 2) - pow(Tc, 2)) / (2 * Ta * Tb));
		sum += f * 180 / M_PI;
	}
	double Ta = sqrt(pow((arc[3].x - x.x), 2) + pow((arc[3].y - x.y), 2));
	double Tb = sqrt(pow((arc[0].x - x.x), 2) + pow((arc[0].y - x.y), 2));
	double Tc = sqrt(pow((arc[3].x - arc[0].x), 2) + pow((arc[3].y - arc[0].y), 2));
	double f = acos((pow(Ta, 2) + pow(Tb, 2) - pow(Tc, 2)) / (2 * Ta * Tb));
	sum += f * 180 / M_PI;
	if (sum >= 355 && sum <= 365) return true;
	return false;
}

bool Rectangle::IsShapeInclude(Shape* shape)
{
	int kol=0;
	for (int i = 0; i <= 3; i++)
	{
		if (IsPointInclude(shape->arc[i])) kol++;
	}
	if (kol == 4) return true;
	return false;
}

bool Rectangle::IsShapeIntersect(Shape* shape)
{
	int kol = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (IsPointInclude(shape->arc[i])) kol++;
		if (shape->IsPointInclude(this->arc[i])) kol++;
	}
	if (kol < 4 && kol>0) return true;
	return false;
}

bool Rectangle::IsAreaMore(Shape* shape)
{
	if (this->getArea() > shape->getArea()) return true;
	return false;
}

//-----------------------------------Квадрат--------------------------------

void Square::info()
{
	cout << "Квадрат" << endl;
	cout << "Вершины:" << endl;
	for (int i = 0; i <= 3; i++)
	{
		cout << "Вершина "<<i+1<<": (" << arc[i].x << "," << arc[i].y << ");" << endl;
	}
}

bool Square::IsSquare() //функция определяющая квадрат ли это по координатам
{
	int kol90 = 0;
	int kol45 = 0;
	for (int i = 0; i <= 3; i++)
	{
		double x1 = arc[(i + 1) % 4].x - arc[i].x;
		double y1 = arc[(i + 1) % 4].y - arc[i].y;
		double x2 = arc[(i + 2) % 4].x - arc[i].x;
		double y2 = arc[(i + 2) % 4].y - arc[i].y;
		double x3 = arc[(i + 3) % 4].x - arc[i].x;
		double y3 = arc[(i + 3) % 4].y - arc[i].y;
		double f1 = acos((x1 * x2 + y1 * y2) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)))) * 180 / M_PI;
		double f2 = acos((x3 * x2 + y3 * y2) / (sqrt(pow(x3, 2) + pow(y3, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)))) * 180 / M_PI;
		double f3 = acos((x1 * x3 + y1 * y3) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x3, 2) + pow(y3, 2)))) * 180 / M_PI;
		if (round(f1) == 90) kol90++;
		if (round(f2) == 90) kol90++;
		if (round(f3) == 90) kol90++;
		if (round(f1) == 45) kol45++;
		if (round(f2) == 45) kol45++;
		if (round(f3) == 45) kol45++;
	}
	if (kol90 == 4 && kol45 == 8) return true;
	return false;
}

Square::Square()
{
	Id = 'S';
	arc = new Point[4];
	while (true)
	{
		cout << "Введите координаты квадрата:" << endl;
		for (int i = 0; i <= 3; i++)
		{
			cout << "Введите координаты вершины " << i + 1 << ":";
			cin >> arc[i].x >> arc[i].y;
		}
		if (IsSquare()) break;
		else
		{
			cout << "Координаты не соответствуют фигуре. Повторите ввод координат." << endl;
		}
	}
}

Square::~Square()
{
	delete[] arc;
}

double Square::getArea()
{
	getParam();
	area = a * a;
	if (area <= 0) throw 2;
	return area;
}

double Square::getPerimeter()
{
	getParam();
	perimeter = a * 4;
	if (perimeter <= 0) throw 3;
	return a * 4;
}

Point Square::getCG()
{
	Point CG;
	getParam();
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (sqrt(pow((arc[i].x - arc[j].x), 2) + pow((arc[i].y - arc[j].y), 2)) == diagonal)
			{
				if (arc[i].x <= arc[j].x) CG.x = (arc[j].x - arc[i].x) / 2 + arc[i].x;
				else CG.x = (arc[i].x - arc[j].x) / 2 + arc[j].x;

				if (arc[i].y <= arc[j].y) CG.y = (arc[j].y - arc[i].y) / 2 + arc[i].y;
				else CG.y = (arc[i].y - arc[j].y) / 2 + arc[j].y;
			}
		}
	}
	centerOfGravity = CG;
	return CG;
}

double Square::getRadVP()
{
	getParam();
	RadVP = a / 2;
	if (RadVP <= 0) throw 6;
	return RadVP;
}

double Square::getRadOP()
{
	getParam();
	RadOP = sqrt(2) / 2 * a;
	if (RadOP <= 0) throw 5;
	return RadOP;
}
double Square::getParam()
{
	a = sqrt(pow((arc[1].x - arc[0].x), 2) + pow((arc[1].y - arc[0].y), 2));
	diagonal = sqrt(pow((arc[1].x - arc[0].x), 2) + pow((arc[1].y - arc[0].y), 2));
	for (int i = 2; i <= 3; i++)
	{
		if (sqrt(pow((arc[i].x - arc[0].x), 2) + pow((arc[i].y - arc[0].y), 2)) < a) a = sqrt(pow((arc[i].x - arc[0].x), 2) + pow((arc[i].y - arc[0].y), 2));
		if (sqrt(pow((arc[i].x - arc[0].x), 2) + pow((arc[i].y - arc[0].y), 2)) > diagonal) diagonal = sqrt(pow((arc[i].x - arc[0].x), 2) + pow((arc[i].y - arc[0].y), 2));
	}
	if (a <= 0) throw 8;
	return a;
}

void Square::calculateParam()
{
	getParam();
	getCG();
	getArea();
	getPerimeter();
	getRadOP();
	getRadVP();
}

void Square::showParam()
{
	cout << "сторона: a-" << a << endl;
	cout << "центр тяжести: (" << centerOfGravity.x << "," << centerOfGravity.y << ")" << endl;
	cout << "площадь: " << area << endl;
	cout << "периметр: " << perimeter << endl;
	cout << "радиус описанной окружности: " << RadOP << endl;
	cout << "радиус вписанной окружности: " << RadVP << endl;
}

void Square::Move(double x, double y)
{
	for (int i = 0; i <= 3; i++)
	{
		arc[i].x += x;
		arc[i].y += y;
	}
}

void Square::Rotate(double grad)
{
	getCG();
	for (int i = 0; i <= 3; i++)
	{
		Point oldArc = arc[i];
		oldArc.x = oldArc.x - centerOfGravity.x;
		oldArc.y = oldArc.y - centerOfGravity.y;
		arc[i].x = (oldArc.x * cos(grad * (M_PI / 180))) - (oldArc.y * sin(grad * (M_PI / 180)));
		arc[i].y = (oldArc.x * sin(grad * (M_PI / 180))) + (oldArc.y * cos(grad * (M_PI / 180)));
		arc[i].x = arc[i].x + centerOfGravity.x;
		arc[i].y = arc[i].y + centerOfGravity.y;
	}
}

bool Square::IsPointInclude(Point x)
{
	for (int i = 0; i <= 3; i++)
	{
		if (arc[i].x == x.x && arc[i].y == x.y) return true;
	}
	double sum = 0;
	for (int i = 0; i <= 2; i++)
	{
		double Ta = sqrt(pow((arc[i].x - x.x), 2) + pow((arc[i].y - x.y), 2));
		double Tb = sqrt(pow((arc[i + 1].x - x.x), 2) + pow((arc[i + 1].y - x.y), 2));
		double Tc = sqrt(pow((arc[i + 1].x - arc[i].x), 2) + pow((arc[i + 1].y - arc[i].y), 2));
		double f = acos((pow(Ta, 2) + pow(Tb, 2) - pow(Tc, 2)) / (2 * Ta * Tb));
		sum += f * 180 / M_PI;
	}
	double Ta = sqrt(pow((arc[3].x - x.x), 2) + pow((arc[3].y - x.y), 2));
	double Tb = sqrt(pow((arc[0].x - x.x), 2) + pow((arc[0].y - x.y), 2));
	double Tc = sqrt(pow((arc[3].x - arc[0].x), 2) + pow((arc[3].y - arc[0].y), 2));
	double f = acos((pow(Ta, 2) + pow(Tb, 2) - pow(Tc, 2)) / (2 * Ta * Tb));
	sum += f * 180 / M_PI;
	if (sum >= 355 && sum <= 365) return true;
	return false;
}

bool Square::IsShapeInclude(Shape* shape)
{
	int kol = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (IsPointInclude(shape->arc[i])) kol++;
	}
	if (kol == 4) return true;
	return false;
}

bool Square::IsShapeIntersect(Shape* shape)
{
	int kol = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (IsPointInclude(shape->arc[i])) kol++;
		if (shape->IsPointInclude(this->arc[i])) kol++;
	}
	if (kol < 4 && kol>0) return true;
	return false;
}

bool Square::IsAreaMore(Shape* shape)
{
	if (this->getArea() > shape->getArea()) return true;
	return false;
}


//Фабричный метод----------------ститик.Класс--------------
Shape* Shape::createShape(char cd)
{
	Shape* sh = 0;
	switch (cd) {
	case 'R':
		sh = new Rectangle(); break;
	case 'S':
		sh = new Square(); break;
	}
	return sh;
}