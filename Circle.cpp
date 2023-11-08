#include "Circle.h"
#include <cmath>

Circle::Circle(){
	center = Point2D();
	radius = 1.0;
}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color){
	this->center = center;
	this->radius = radius;
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center = p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "Color: " << c.get_color() << " Centro: (" << c.center.x << ", " << c.center.y << ") Radio: " << c.radius;
	return out;
}

double Circle::area() const{
	return 3.141592 * pow(this->radius, 2);
}

double Circle::perimeter() const{
	return 2 * 3.141592 * this->radius;
}

void Circle::translate(double incX, double incY){
	this->center.x += incX;
	this->center.y += incY;
}

void Circle::print(){
	std::cout << *this;
}
