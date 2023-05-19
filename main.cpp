#include "random_value.h"
#include "check_value.h"
#include "high_scores.h"

#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char** argv) {

    Arguments arguments;
    for (int i = 0; i < argc; i++) {
        std::string arg{ argv[i] };

        if (arg == "-help") {
            int n = 20;
            std::cout << std::setiosflags(std::ios::left);
            //std::cout << std::setw(n) << "-level" << " - difficulty level. It depends on the maximum value of given number." << std::endl;
            std::cout << std::setw(n) << "-max" << " - sets the maximum value for hidden number." << std::endl;
            std::cout << std::setw(n) << "-table" << " - displays the scores table, without the need to play." << std::endl;
            std::cout << std::setiosflags(std::ios::right);

            std::cout << "Do you want to start game? yes/no" << std::endl;
            std::string is_end;
	        std::cin >> is_end;
            if (is_end != "yes") {
                return 0;
            }           
        }

        if (arg == "-max") {
            arguments.max_value = std::stoi(argv[++i]);
        }

        if (arg == "-table") {
            read_score();
            return 0;
        }
        
        if (arg == "-level") {
            arguments.level_value = std::stoi(argv[++i]);
        }
    }

    if (args_status(arguments) == 1) {
        std::cout << "Error situation: ";
        std::cout << "input parameters “-level” and “-max” simultaneously. ";
        std::cout << "Set either “-level“ or “-max”." << std::endl;
        return 0;
    }
    
    std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
    
    int max_value = get_max_value(arguments.level_value, arguments.max_value);
    std::cout << "Max value: " << max_value << std::endl;
    
    int attempts_count = check_value(get_random_value(max_value));
    
    //write_new_score(user_name, attempts_count);
    overwrite_score(user_name, attempts_count);
    read_the_best_score();

    return 0;
}