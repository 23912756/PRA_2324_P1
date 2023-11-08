#include "Shape.h"

Shape::Shape() : color{"red"} {}

Shape::Shape(std::string color){
	if(color == "red" || color == "blue" || color == "green"){
		this->color = color;
	}else{
		throw std::invalid_argument("Color erroneo");
	}
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
         if(c == "red" || c == "blue" || c == "green"){
        	color = c;
	 }else{
                throw std::invalid_argument("Color erroneo");
	}
}
