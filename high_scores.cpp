#include "high_scores.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int write_new_score(const std::string& user_name, int attempts_count, const std::string& filename) {

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

int read_score(const std::string& filename) {
	std::ifstream in_file{filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;

	for (std::string line; std::getline(in_file, line); ) {
		username = "";
		high_score = get_data_from_line(line, username);
		if (high_score) {
			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
	}

	return 0;
}

std::vector<std::string> split(const std::string& str, char delimiter) {
   std::vector<std::string> v;
   std::string s;
   std::istringstream stream(str);
   while (std::getline(stream, s, delimiter)) {
      v.push_back(s);
   }
   return v;
}

int get_data_from_line(std::string& line, std::string& username) {
	int high_score = 0;
	std::vector<std::string> v = split(line, char{' '});
	if (!v.empty()) {
		high_score = std::stoi(v.back());
		auto it = v.begin();
		username = *it;
		it++;
		for (it; it != v.end() - 1; it++) {
			username += " " + *it;
		}
	}
	return high_score;
}

int get_users_map(std::map<std::string, int>& users_map, const std::string& filename) {
	std::ifstream in_file{filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
		return -1;
	} else {
		std::string username;
		int high_score = 0;

		for (std::string line; std::getline(in_file, line); ) {
			username = "";
			high_score = get_data_from_line(line, username);
			if (high_score) {
				std::map<std::string, int>::iterator it = users_map.find(username);
				if (it != users_map.end()) {
					if (high_score < it->second) {
						users_map[it->first] = high_score;
					}
				} else {
					users_map[username] = high_score;
				}
			}
		}
	}

	in_file.close();
	return 0;
}

//Read the table of records for each user,
//determine the minimum value of number attempts and output them
int read_the_best_score(const std::string& filename) {
	std::map<std::string, int> users_map;
	get_users_map(users_map, filename);

	//Print scores table
	std::cout << "The best scores table:" << std::endl;
	std::map<std::string, int>::iterator it = users_map.begin();
	for (; it != users_map.end(); it++) {
		std::cout << it->first << '\t' << it->second << std::endl;
	}
	
	return 0;
}

//Search for name and replace its score
int overwrite_score(const std::string& name, int score, const std::string& filename) {
	std::map<std::string, int> users_map;
	get_users_map(users_map, filename);

	{
		std::map<std::string, int>::iterator it = users_map.find(name);
		if (it != users_map.end()) {
			if (score < it->second) {
				users_map[it->first] = score;
			}
		} else {
			users_map[name] = score;
		}
	}

	std::ofstream out_file{filename};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << filename << "!" << std::endl;
		return -1;
	}

	for (auto it = users_map.begin(); it != users_map.end(); it++) {
		out_file << it->first << ' ';
		out_file << it->second;
		out_file << std::endl;
	}
	out_file.close();

	return 0;
}