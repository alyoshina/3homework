#include "check_value.h"

#include <iostream>

int check_value(const int target_value) {

	int attempts_count = 0;
	int current_value = 0;
	bool not_win = true;

	do {
		attempts_count++;

		std::cout << "Enter number:" << std::endl;
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << current_value << " is less than the number" << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << current_value << " is greater than the number" << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);

	return attempts_count;
}