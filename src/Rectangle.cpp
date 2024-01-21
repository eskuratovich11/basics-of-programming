#include <Rectangle.hpp>

namespace geo
{
	Rectangle::Rectangle(float width, float height) {
        if(width <= 0 || height <= 0){
            throw std::exception();
        }
		this->width = width;
        this->height = height;
    }

    float Rectangle::find_square() {
        return this->width * this->height;
    }

    float Rectangle::find_perimeter() {
        return 2 * (this->height + this->width);
    }

    float Rectangle::find_diagonal() {
        return sqrtf(powf(height,2.0f) + powf(width,2.0f));
    }

    void Rectangle::print() {
        std::cout << "Perimetr: " << find_perimeter() << std::endl << "Square: " << find_square() << std::endl << "Diagonal: " << find_diagonal() << std::endl;
    }

    Rectangle::Rectangle() {
        this->height = 2;
        this->width = 1;
    }

}