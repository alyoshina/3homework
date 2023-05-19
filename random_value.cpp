#include "random_value.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int get_random_value(const int max_value) {
	std::srand(std::time(nullptr));
	return std::rand() % max_value;
}

int args_status(const Arguments &args) {
	int error = 0;
	if (args.max_value != 0 && args.level_value != 0) {
		error = 1;
	}
	return error;
}

int get_max_value(int level_val, int max_val) {
	int max_value = MAX_VAL;
	if (max_val > 0) {
		if (max_val < 1000) {
			max_value = max_val;
		} else {
			std::cout << "Max value is incorrect: " << max_val << std::endl;
		}
	} else if (level_val > 0) {
		switch (level_val) {
		case 1:
			max_value = 10;
			break;
		case 2:
			max_value = 50;
			break;
		case 3:
			max_value = 100;
			break;
		default:
			std::cout << "Level value is incorrect: " << level_val << std::endl;
			level_val = 0;
			break;
		}
	}
	
	return max_value;
}