#include <stdio.h>
#include <math.h>
// generation préprocesseur : gcc -E td.c > td.i
/*
allemand
anglais
français
portugais
espagnol
vietnamien
romanche
*/
#define FR 0

#define DEBUG 1

#if FR == 1
#define TEXT "BONJOUR"
#else
#define TEXT "HELLO"
#endif
int main()
{
	puts(TEXT);

#if FR == 1
	puts("Version française");
#endif
#if FR == 0
	puts("Version anglaise");
#endif

	int i = 42;
	double t = sqrt(i);
#if DEBUG >= 1
	printf("t=%lf\n", t);
#endif

#undef DEBUG
#define DEBUG 45



	return 0;
}