#pragma once

struct Point { double x, y; };

class Shape {
protected:
	char Id;
	double diagonal;
	Point centerOfGravity; //центр тяжести (center of gravity)
	double area; //площадь
	double perimeter; //периметр
	double RadOP; //радиус описанной окружности
	double RadVP; //радиус вписанной окружности

public:
	Point* arc;
	virtual void info();
	virtual ~Shape();
	static Shape* createShape(char);
	virtual double getParam();
	virtual double getArea();
	virtual double getPerimeter();
	virtual Point getCG();
	virtual double getRadOP();
	virtual double getRadVP();
	virtual void calculateParam();
	virtual void showParam();
	virtual void Move(double , double);
	virtual void Rotate(double);
	virtual bool IsPointInclude(Point);
	virtual bool IsShapeInclude(Shape*);
	virtual bool IsShapeIntersect(Shape*);
	virtual bool IsAreaMore(Shape*);
};

class Rectangle : public Shape
{
private:
	double a;
	double b;
public:
	Rectangle();
	void info();
	~Rectangle();
	double getParam();
	double getArea();
	double getPerimeter();
	Point getCG();
	double getRadOP();
	double getRadVP();
	void calculateParam();
	void showParam();
	void Move(double, double);
	void Rotate(double);
	bool IsPointInclude(Point);
	bool IsShapeInclude(Shape*);
	bool IsShapeIntersect(Shape*);
	bool IsAreaMore(Shape*);
	bool IsRectangle();
};

class Square : public Shape
{
private:
	double a;
public:
	Square();
	void info();
	~Square();
	double getParam();
	double getArea();
	double getPerimeter();
	Point getCG();
	double getRadOP();
	double getRadVP();
	void calculateParam();
	void showParam();
	void Move(double, double);
	void Rotate(double);
	bool IsPointInclude(Point);
	bool IsShapeInclude(Shape*);
	bool IsShapeIntersect(Shape*);
	bool IsAreaMore(Shape*);
	bool IsSquare();
};
