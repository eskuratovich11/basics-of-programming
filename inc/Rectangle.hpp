#pragma once
#include <cmath>
#include <iostream>

namespace geo
{

	class Rectangle {

		float width,height;

	public:
		Rectangle();
        Rectangle(float width, float height);
		~Rectangle() = default;
        float find_square();
        float find_perimeter();
        float find_diagonal();
        void print();
	}; 

}