#pragma once

#include <stdio.h>
#include <math.h>

// structures
typedef struct {
	double rho;
	double theta; // rad
} polar;

typedef struct {
	double x;
	double y;
} cart;

// prototype
cart polar2cartesian(polar p);
void display_cartesian(cart p);

