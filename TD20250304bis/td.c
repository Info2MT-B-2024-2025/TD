#include <stdio.h>
#include <string.h>
#include <math.h>

double deg2rad(const double alpha);
double rad2deg(const double alpha);

double deg2rad(const double alpha)
{
	return alpha * M_PI / 180.;
}

double rad2deg(const double alpha)
{
	return alpha * 180. / M_PI;
}

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.txt"; // relatif
	char *mode = "w";						  // create and write into the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	const double RADIUS = 2.;
	const double L = 12.;
	const double ALPHA_MIN = 0.;
	const double ALPHA_MAX = 360.;
	const double ALPHA_STEP = 1E-1;

	// ⚠️⚠️⚠️ cos, sin use radians 😃

	// fprintf(f,"%5.1lf %+6.3lf %+6.3lf %5.2lf\n", alpha,x,y,h);
	double alpha = 0.;
	for (alpha = ALPHA_MIN; alpha <= ALPHA_MAX; alpha += ALPHA_STEP)
	{
		double r = RADIUS * cos(deg2rad(alpha));
		double i = RADIUS * sin(deg2rad(alpha));
		fprintf(f, "%+8.3lf %+8.3lf %+8.3lf\n", alpha, r, i);
	}

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}