#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_SIZE 100

int main(int argc, const char *argv[])
{
	FILE *f=NULL;
	char filename[MAX_FILENAME_SIZE];
	const char* mode="rb";
	size_t num_cells=0;
	size_t ret=0;
	double *t=NULL;
	double computed_min_value=0.;
	double computed_max_value=0.;
	double computed_mean_value=0.;
	double sum=0.;
	size_t index=0;
	double read_min_value=0.;
	double read_max_value=0.;
	double read_mean_value=0.;

	// check args -> argc=2 ok else return 1
	if(2!=argc) {
		printf("Error, bad number of args.\n");
		return 1;
	}
	// read header from file -> num_cells (size_t)
	sprintf(filename,"data/d%s.bin", argv[1]);
	f=fopen(filename,mode);
	if(NULL==f) {
		printf("Error while opening [%s]\n", filename);
		return 2;
	}
	ret=fread(&num_cells,sizeof(size_t),1,f);
	if(1!=ret) {
		printf("Error while reader header\n");
		return 4;
	}
	printf("num_cells=%lu\n",num_cells);

	// dynamic allocation -> t (double*) : size=num_cells*sizeof(double)
	// check t!=NULL
	//t=(double*)malloc(num_cells*sizeof(double));
	t=(double*)calloc(num_cells, sizeof(double)); // idem malloc + set area to zero
	if(NULL==t) {
		printf("Error while allocating memory\n");
		return 8;
	}

	// read data from file -> t
	// check read ok (num_cells)
	ret=fread(t,sizeof(double),num_cells,f);
	if(num_cells!=ret) {
		printf("Error while reader data\n");
		free(t);
		return 4;
	}

	// compute min, max, mean with data
	computed_min_value=t[0];
	computed_max_value=t[0];
	sum=t[0];
	for(index=1;index<num_cells;index++) {
		computed_min_value=t[index]<computed_min_value?t[index]:computed_min_value;
		computed_max_value=t[index]>computed_max_value?t[index]:computed_max_value;
		sum+=t[index];
	}
	computed_mean_value=sum/num_cells;

	// read min, max, mean from file
	ret=fread(&read_min_value,sizeof(double),1,f);
	ret+=fread(&read_max_value,sizeof(double),1,f);
	ret+=fread(&read_mean_value,sizeof(double),1,f);
	if(3!=ret) {
		printf("Error while reader min/max/mean\n");
		free(t);
		return 16;
	}
	// compare min, max, mean file/data
	// display result
	printf("%s\n",
		(read_min_value==computed_min_value) &&
		(read_max_value==computed_max_value) &&
		(read_mean_value==computed_mean_value) ? "OK" : "NG"
	);

	if(0!=fclose(f)) {
		printf("Error while closing file\n");
	}
	free(t);
	t=NULL;
	return 0;
}