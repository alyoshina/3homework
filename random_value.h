#pragma once

#define MAX_VAL 100

struct Arguments{
    int max_value = 0;
    int level_value = 0;
};

int args_status(const Arguments &args);
int get_max_value(int level_val, int max_val);
int get_random_value(const int max_value = MAX_VAL);