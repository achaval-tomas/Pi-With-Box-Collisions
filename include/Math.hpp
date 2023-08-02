#pragma once
#include <iostream>

struct Vector2f{
	Vector2f(){x = 0; y = 0;}

	Vector2f(long double p_x, long double p_y)
	:x(p_x), y(p_y)
	{}

	void print(){
		std::cout << x << ", " << y << std::endl;
	}

	long double x, y;
};