#include "random_value.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int get_random_value(const int max_value) {
	std::srand(std::time(nullptr));
	return std::rand() % max_value;
}