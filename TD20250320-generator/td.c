#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_SIZE 100

int main(int argc, const char *argv[])
{
	size_t num_cells = 0;
	size_t filename_index = 0;
	char filename[MAX_FILENAME_SIZE];
	const char *mode = "wb";
	FILE *f = NULL;
	int ret = 0;
	double *t = NULL;
	size_t index = 0; // for loop to fill t
	double min_value = 0.;
	double max_value = 0.;
	double sum_of_values = 0.;
	double mean_value = 0.;

	// read / check arguments
	// - num_cells
	// - filename_index
	// => filename
	if (3 != argc)
	{
		printf("usage: %s num_cells file_index\n", argv[0]);
		return 1;
	}
	num_cells = atoi(argv[1]);
	filename_index = atoi(argv[2]);
	// TODO: check if num_cells > 0
	sprintf(filename, "./data/d%lu.bin", filename_index);
	printf("filename : [%s]\n", filename);

	// open file
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error while opening %s\n", filename);
		return 1;
	}

	// write header to file (num_cells)
	ret = fwrite(&num_cells, sizeof(size_t), 1, f);
	if (1 != ret)
	{
		printf("Error while write header to %s\n", filename);
		return 2;
	}

	// dynamic allocation of table
	// t (double*)
	t = (double *)malloc(num_cells * sizeof(double));
	if (NULL == t)
	{
		printf("Error while allocating memory at line %d\n", __LINE__);
		return 4;
	}

	// fill t with random value,s [0..1] rand()/(double)RAND_MAX
	for (index = 0; index < num_cells; index++)
	{
		t[index] = rand() / (double)RAND_MAX;
	}
	// compute min, max and mean values of t (=> previous TD)
	// - min_value (double)
	// - max_value (double)
	// - mean_value (double)
	min_value = t[0];
	max_value = t[0];
	sum_of_values = t[0];
	for (index = 1; index < num_cells; index++)
	{
		min_value = t[index] < min_value ? t[index] : min_value;
		// NIET !! t[index] < min_value ? min_value = t[index] : min_value = min_value;
		max_value = t[index] > max_value ? t[index] : max_value;
		sum_of_values += t[index];
	}
	mean_value=sum_of_values/num_cells;
	printf("min_value  = %.6lf\n", min_value);
	printf("max_value  = %.6lf\n", max_value);
	printf("mean_value = %.6lf\n", mean_value);

	// write t to file (num_cells)
	ret = fwrite(t, sizeof(double), num_cells, f);
	if (num_cells != ret)
	{
		printf("Error while write data to %s\n", filename);
	}
	// write min_value to file
	ret = fwrite(&min_value, sizeof(double), 1, f);
	if (1 != ret)
	{
		printf("Error while write min_value to %s\n", filename);
	}
	// write max_value to file
	ret = fwrite(&max_value, sizeof(double), 1, f);
	if (1 != ret)
	{
		printf("Error while write max_value to %s\n", filename);
	}
	// write mean_value to file
	ret = fwrite(&mean_value, sizeof(double), 1, f);
	if (1 != ret)
	{
		printf("Error while write mean_value to %s\n", filename);
	}

	// close file
	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
	}

	// free t
	free(t);
	t = NULL;

	return 0;
}
