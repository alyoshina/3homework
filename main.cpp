#include "random_value.h"
#include "check_value.h"
#include "high_scores.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    int random_value = get_random_value();
    //std::cout << random_value << std::endl;

    std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

    int attempts_count = check_value(random_value);

    write_new_score(user_name, attempts_count);
    read_score();

    return 0;
}