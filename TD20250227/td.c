#include <stdio.h>

int main(int argc, const char *argv[])
{
	const char *filename = "./data/list.txt"; // relatif
	// const char *filename="/workspaces/TD/TD20250227/data/list.txt"; // absolu
	char *mode = "r"; // read the file

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}
	// read the file and count the number of characters (EOF excluded)
	char c = ' ';
	size_t filesize = 0;

	do
	{
		c = fgetc(f);
		if (c != EOF)
		{
			printf("%c", c);
			filesize++;
		}
	} while (c != EOF);

	printf("\nfilesize=%lu bytes.\n", filesize);

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	// create ./data/ascii.txt
	const char *output_filename = "./data/ascii.txt";
	mode = "w";

	f = fopen(output_filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", output_filename);
		return 1;
	}

	fprintf(f, "ASCII TABLE\n");
	fprintf(f, "-----------\n");
	for (int i = 32; i < 128; i++)
		fprintf(f, "%5d %5c\n", i, i);

	// close the file
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}