#include "polar.h"

cart polar2cartesian(polar p) {
	cart result;
	result.x = p.rho * cos(p.theta);
	result.y = p.rho * sin(p.theta);
	return result;
}


void display_cartesian(cart p) {
    printf("x = %+6.3lf\n", p.x);
	printf("y = %+6.3lf\n", p.y);
    
    return;
}