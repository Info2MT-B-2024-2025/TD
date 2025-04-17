#pragma once

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
    int bidon;
} bato;


long long current_time_in_ms();
void init_random_generator(void);
double get_random_value(const double min, const double max);