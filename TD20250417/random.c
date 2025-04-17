#include "random.h"

long long current_time_in_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

void init_random_generator(void) {
    srand( (unsigned int)current_time_in_ms() );
}

double get_random_value(const double min, const double max) {
    double output=0.;
    output=rand()*((max-min)/(RAND_MAX))+min;
    return output;
}
