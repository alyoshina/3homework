#include "high_scores.h"

#include <iostream>
#include <fstream>

#include <map>

int write_new_score(const std::string user_name, int attempts_count, const std::string filename) {

	std::ofstream out_file{filename, std::ios_base::app};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << filename << "!" << std::endl;
		return -1;
	}

	// Append new results to the table:
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;

	return 0;
}

int read_score(const std::string filename) {
	std::ifstream in_file{filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}

	return 0;
}

//Read the table of records for each user,
//determine the minimum value of number attempts and output them
int read_the_best_score(const std::string filename) {
	std::ifstream in_file{filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
		return -1;
	} else {
		std::map<std::string, int> users_map;
		std::string username;
		int high_score = 0;
		while (in_file >> username >> high_score) {
			std::map<std::string, int>::iterator it = users_map.find(username);
			if (it != users_map.end() && (high_score < it->second)) {
				users_map[it->first] = high_score;
			} else {
				users_map[username] = high_score;
			}
		}
		in_file.close();
		
		//Print scores table
		std::cout << "The best scores table:" << std::endl;
		std::map<std::string, int>::iterator it = users_map.begin();
		for (; it != users_map.end(); it++) {
			std::cout << it->first << '\t' << it->second << std::endl;
		}
	}
	return 0;
}