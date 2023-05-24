#pragma once
#include <string>
#include <vector>
#include <map>

#define HIGH_SCORES_FILENAME "high_scores.txt"

int write_new_score(const std::string& user_name, int attempts_count, 
                            const std::string& filename = HIGH_SCORES_FILENAME);
int read_score(const std::string& filename = HIGH_SCORES_FILENAME);
int read_the_best_score(const std::string& filename = HIGH_SCORES_FILENAME);
int overwrite_score(const std::string& name, int score, const std::string& filename = HIGH_SCORES_FILENAME);
int get_users_map(std::map<std::string, int>& users_map, const std::string& filename = HIGH_SCORES_FILENAME);
std::vector<std::string> split(const std::string& str, char delimiter);
int get_data_from_line(std::string& line, std::string& username);
