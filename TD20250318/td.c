#include <stdio.h>
#include <stdlib.h> // malloc, free

int main(int argc, const char *argv[])
{
	// usage : ./app 1000
	if(2!=argc) {
		printf("error, not enough args\n");
		return 1;
	}
	int num_cells = atoi(argv[1]);  // ret=sscanf(argv[1],"%d", &num_cells);
	double *t=NULL;

	t=(double *)malloc( num_cells * sizeof(double) );
	if(NULL==t) {
		printf("error while allocating memory at line %d\n",__LINE__);
		return 1;
	}
	printf("t=%p\n", t);
	printf("main=%p\n", main);

	free(t);
	t=NULL;

	return 0;
}


#if 0
#define N 4

double t_glob[N]; // global



void usage(void) {
	static int ssss=42;
	int anti=34;
	printf("ok, ssss=%d\n", ssss);
	printf("ssss=%p\n", &ssss);
	printf("anti=%p\n", &anti);
	ssss++;
	return;
}
int main(int argc, const char *argv[])
{
	double t[N]; // local
	printf("t=%p\n", t);
	printf("t_glob=%p\n", t_glob);
	printf("main=%p\n", main);
	printf("usage=%p\n", usage);

	usage();
	usage();
	return 0;
}
	#endif