#pragma once

#define MAX_VAL 100

struct Arguments{
    int max_value = MAX_VAL;
};

int get_random_value(const int max_value = MAX_VAL);