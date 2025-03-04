#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 102 // 100 +1 (\n) +1 (\0)

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.txt"; // relatif
	char *mode = "r";						  // read the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	size_t num_lines = 0;
	char c = 0;
	do
	{
		c = fgetc(f);
		num_lines += c == '\n' || c == EOF;
	} while (c != EOF);
	printf("num lines=%lu\n", num_lines);

	rewind(f);
#if 0
	char s[MAX_STRING_SIZE]={0};
	fgets(s,MAX_STRING_SIZE,f);
	printf("original line : [%s]\n",s);

	char *tmp=NULL;
	tmp=strchr(s,'\n');
	if(NULL!=tmp) {
		*tmp='\0';
	}
	printf("modified line : [%s]\n",s);
#endif

	for (size_t line_index = 0; line_index < num_lines; line_index++)
	{
		char s[MAX_STRING_SIZE] = {0};
		fgets(s, MAX_STRING_SIZE, f);
		char *tmp = NULL;
		tmp = strchr(s, '\n');
		if (NULL != tmp)
		{
			*tmp = '\0';
		}
		printf("[%s]\n", s);
	}

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}