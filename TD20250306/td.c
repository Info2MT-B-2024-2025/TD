#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.txt"; // relatif
	char *mode = "r";						  // read from the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}
	char s[MAX_STRING_SIZE];
	char *tmp = NULL;
	do
	{
		tmp = fgets(s, MAX_STRING_SIZE, f);

		if (NULL == tmp)
		{
			printf("Error, nothing to read from file.\n");
		}
		else
		{ // process s
			// remove the \n from s
			if (s[strlen(s) - 1] == '\n')
				s[strlen(s) - 1] = '\0';
		}
		printf("%p, [%s], %d\n", tmp, s, feof(f));
	} while (!feof(f));

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};
	return 0;
}
