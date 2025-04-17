#include "polar.h"
#include "random.h"
#include <math.h> // M_PI
#include <stdio.h> 



// fonction

int main(int argc, const char *argv[])
{
	polar ap={.rho=1., .theta=M_PI/4.};
	cart  ac={.x=0., .y=0.};

	init_random_generator();
	
	ac=polar2cartesian(ap);
	display_cartesian(ac);

	printf("random value=%lf\n", get_random_value(-5.,+5.));
	return 0;
}