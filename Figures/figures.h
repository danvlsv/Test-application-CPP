#ifndef FIGURES_H
#define FIGURES_H


#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>

class Figure
{
protected:
	double _area = 0;
	virtual void Area() = 0;
public:
	double GetArea();

};



class Circle : public Figure
{
private:
	double _radius;
	void Area() override;
public:
	Circle(double radius);
};

class Triangle : public Figure
{
private:
	double _a, _b, _c;
	double _radius{};
	void Area() override;
public:
	Triangle(double a, double b, double c);

};


class Rectangle : public Figure
{
private:
	double _a, _b;
	double _radius;
	void Area() override;
public:
	Rectangle(double a, double b);

};

#endif