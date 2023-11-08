#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h" 

class Square : public Rectangle{
	private:
		static bool check(Point2D* vertices){
			return (Point2D::distance(vertices[0], vertices[2]) ==
				Point2D::distance(vertices[1], vertices[3])) &&
				(Point2D::distance(vertices[0], vertices[1]) ==
				 Point2D::distance(vertices[1], vertices[2]));
		}

	public:
		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;
};

#endif
