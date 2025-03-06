#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.bin"; // relatif
	char *mode = "rb";						  // read from the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	double p=0.;
	size_t n=1;
	size_t r=0;
	r=fread( &p, sizeof(double), n, f);
	if(n!=r) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("p=%.15lf\n",p);

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};
	return 0;
#if 0
	const char *filename = "./data/data.bin"; // relatif
	char *mode = "wb";						  // write to the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	// store π/2 in data.txt with 15 digits after decimal point
	double p = M_PI / 2.;

	// memory dump of p
	uint8_t *ptr=(uint8_t *)&p;
	for(size_t i=0;i<sizeof(double);i++, ptr++)
		printf("%02X ", *ptr);
	puts("");

	size_t r=0;
	r=fwrite( &p, sizeof(double), 1, f);
	printf("r=%lu\n",r);
	if(1!=r) {
		printf("Error, unable to write into [%s].\n", filename);
		return 4;
	}

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};
	return 0;
#endif
#if 0
	const char *filename = "./data/data.txt"; // relatif
	char *mode = "w";						  // read from the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	// store π/2 in data.txt with 15 digits after decimal point
	double p=M_PI/2.;
	fprintf(f, "%.15lf", p);

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};
	return 0;
#endif
}
#if 0
int main2(int argc, const char *argv[])
{
	const char *filename = "./data/data.txt";	// relatif
	char *mode = "w";							// create and write into the file
	const char *filename_b = "./data/data.bin"; // relatif
	char *mode_b = "wb";						// create and write into the file
	if (argc < 2)
		return 4;

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}
	FILE *fb = NULL;
	fb = fopen(filename_b, mode_b);
	if (NULL == fb)
	{
		printf("Error, unable to open [%s].\n", filename_b);
		return 1;
	}
	int num_digits = atoi(argv[1]);
	long double p = M_PI / 2.;
	fprintf(f, "%.*Lf", num_digits, p);
	fwrite(&p, sizeof(long double), 1, fb);
	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};
	if (0 != fclose(fb))
	{
		printf("Error, unable to close [%s].\n", filename_b);
		return 2;
	};

	fb = fopen(filename_b, "rb");
	if (NULL == fb)
	{
		printf("Error, unable to open [%s].\n", filename_b);
		return 1;
	}
	fread(&p, sizeof(long double), 1, fb);
	printf("%.*Lf", num_digits, p);

	if (0 != fclose(fb))
	{
		printf("Error, unable to close [%s].\n", filename_b);
		return 2;
	};

	return 0;
}
#endif