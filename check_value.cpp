#include "check_value.h"

#include <iostream>
#include <string>

int check_value(const int target_value) {

	int attempts_count = 0;
	int current_value = 0;
	std::string str;
	bool not_win = true;

	do {
		attempts_count++;

		std::cout << "Enter number:" << std::endl;
		std::cin >> str;

		try {
            current_value = std::stoi(str);
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
        } catch (std::invalid_argument const& ex) {
            std::cout << "Entered not a number: " << str << '\n';
        }
		
	} while(true);

	return attempts_count;
}