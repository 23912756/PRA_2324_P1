#include "Square.h"

Square::Square(){ //por defecto invoca a Rectangle()
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1,-1);
	vs[3] = Point2D(-1,-1);	
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices){
	if(!Square::check(vertices)){
		throw std::invalid_argument("Cuadrado Inválido");
	}
}

void Square::set_vertices(Point2D* vertices){
	if(Square::check(vertices)){
		for(int i = 0; i < N_VERTICES; i++){
			this->vs[i] = vertices[i];
		}
	}else{
		throw std::invalid_argument("Cuadrado Inválido");
	}
}

std::ostream& operator<<(std::ostream &out, const Square &square){
	out << "Square: Color: " << square.get_color();
	for(int i = 0; i < Square::N_VERTICES; i++){
		out << " v[" << i << "] = (" << square.vs[i].x << ", " << square.vs[i].y << ")";
	}
	return out;
}

double Square::area() const{
	return (Point2D::distance(this->vs[0], this->vs[1])) *
	       (Point2D::distance(this->vs[1], this->vs[2]));
}

double Square::perimeter() const{
	return 4 * Point2D::distance(this->vs[0], this->vs[1]);
}

void Square::translate(double incX, double incY){
	for(int i = 0; i < N_VERTICES; i++){
		this->vs[i].x += incX;
		this->vs[i].y += incY;
	}
}

void Square::print(){
	std::cout << *this;
}
