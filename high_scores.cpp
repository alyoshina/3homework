#include "high_scores.h"

#include <iostream>
#include <fstream>
#include <sstream>
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

//Search for the first entry with name and replace its score
int overwrite_score(const std::string name, int score, const std::string filename) {
	bool is_new_name = true;
	
	std::fstream io_file{filename};
	if (io_file.is_open()) {
		std::string username;
		int high_score = 0;
		std::streamoff pos_p = io_file.tellp(); //returns the output position indicator
		while (io_file >> username >> high_score) {
			if (username == name) {
				is_new_name = false;
				
				//Save the rest of file
				io_file.ignore();
				std::stringstream file_rest;
				file_rest << io_file.rdbuf();
				
				//Write new score for username
				io_file.seekp(pos_p);
				io_file << name << ' ' << score << std::endl;
				
				//Write the rest of file
				io_file << file_rest.str();
				break;
			} else {
				io_file.ignore();
				pos_p = io_file.tellp();
			}
		}
	}
	io_file.close();
	
	if (is_new_name && (write_new_score(name, score, filename) < 0)) {
		return -1;
	}
	return 0;
}