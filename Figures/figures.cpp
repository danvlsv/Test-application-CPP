
#include "figures.h"

double Figure::GetArea() {
    return _area;
}

Circle::Circle(const double radius)
{
    if (radius <= 0)
    {
        throw std::invalid_argument("Radius must be bigger than zero");
    }
    _radius = radius;
    Circle::Area();
}

void Circle::Area() {
    _area = (M_PI * pow(_radius, 2));
}

Triangle::Triangle(const double a, const double b, const double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw std::invalid_argument("Sides of a triangle must be bigger than zero");
    }
    else if (a + b <= c || a + c <= b || b + c <= a)
    {
        throw std::invalid_argument("Triangle is not possible");
    }
    _a = a; _b = b; _c = c;
    Triangle::Area();
}

void Triangle::Area() {
    const double s = (_a + _b + _c) / 2;
    _area = sqrt(s * (s - _a) * (s - _b) * (s - _c));
}

Rectangle::Rectangle(double a, double b)
{
    if (a <= 0 || b <= 0)
    {
        throw std::invalid_argument("Sides of a rectangle must be bigger than zero");
    }
    _a = a; _b = b;
    Rectangle::Area();
}

void Rectangle::Area() {
    _area = _a * _b;
}