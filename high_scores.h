#pragma once
#include <string>

#define HIGH_SCORES_FILENAME "high_scores.txt"

int write_new_score(const std::string user_name, int attempts_count, 
                            const std::string filename = HIGH_SCORES_FILENAME);
int read_score(const std::string filename = HIGH_SCORES_FILENAME);
int read_the_best_score(const std::string filename = HIGH_SCORES_FILENAME);


