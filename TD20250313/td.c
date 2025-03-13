#include <stdio.h>
#include <stdint.h>

// https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm

#pragma pack(1)
typedef struct {

	uint16_t signature;
	uint32_t file_size;
	uint32_t unused;
	uint32_t data_offset;

} bitmap_file_header;

typedef struct {

	uint32_t infoheader_size;
	uint32_t width;
	uint32_t height;
	uint16_t num_planes;
	uint16_t bits_per_pixel;
	uint32_t compression_type;
	uint32_t image_size;
	uint32_t horizontal_resolution;
	uint32_t vertical_resolution;
	uint32_t num_used_colors;
	uint32_t num_important_colors;

} bitmap_info_header;
#pragma pack(0)

int main(int argc, const char *argv[])
{
	const char *filename = "./data/im1.bmp";
	char *mode = "rb";

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	bitmap_file_header file_header;
	bitmap_info_header info_header;
	int ret=0;
	
	ret=fread(&file_header, sizeof(bitmap_file_header), 1, f);
	if(ret!=1) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	ret=fread(&info_header, sizeof(bitmap_info_header), 1, f);
	if(ret!=1) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("height=%4lu pixels\n", info_header.height);
	printf("width=%4lu pixels\n", info_header.width);
	printf("data offset=%4lu bytes\n", file_header.data_offset);
	
	fseek(f, file_header.data_offset, SEEK_SET); 
	for (size_t index=0;index<5;index++) {
		uint8_t pixel=0;
		ret=fread(&pixel, sizeof(uint8_t), 1, f);
		if(ret!=1) {
			printf("Error, unable to read from [%s].\n", filename);
			return 4;
		}
		printf("pixel = %02X\n", pixel);
	
	}



	// close the file 
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}


int main_old(int argc, const char *argv[])
{
	const char *filename = "./data/im1.bmp";
	char *mode = "rb";

	printf("sizeof(bitmap_file_header)=%u\n",sizeof(bitmap_file_header));
	printf("sizeof(bitmap_info_header)=%u\n",sizeof(bitmap_info_header));
	return 0;
	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	const size_t WIDTH_OFFSET=18;
#if 0
	for(size_t index=0; index<WIDTH_OFFSET; index++) {
		fgetc(f);
	}
#else
	fseek(f, WIDTH_OFFSET, SEEK_SET); 
#endif

	int ret=0;
	uint32_t width=0;
	ret=fread(&width, sizeof(uint32_t), 1, f);
	if(ret!=1) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("width = %4u pixels\n", width);
	uint32_t height=0;
	ret=fread(&height, sizeof(uint32_t), 1, f);
	if(ret!=1) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("height = %4u pixels\n", height);


	fseek(f, 2, SEEK_CUR); 
	uint16_t bits_per_pixel=0;
	ret=fread(&bits_per_pixel, sizeof(uint16_t), 1, f);
	if(ret!=1) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("bits_per_pixel = %hu bits_per_pixel\n", bits_per_pixel);

	const size_t DATA_OFFSET=0xA;
	fseek(f, DATA_OFFSET, SEEK_SET); 
	uint32_t data_offset=0;
	ret=fread(&data_offset, sizeof(uint32_t), 1, f);
	if(ret!=1) {
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("data_offset = %4u bytes\n", data_offset);

	fseek(f, data_offset, SEEK_SET); 
	for (size_t index=0;index<5;index++) {
		uint8_t pixel=0;
		ret=fread(&pixel, sizeof(uint8_t), 1, f);
		if(ret!=1) {
			printf("Error, unable to read from [%s].\n", filename);
			return 4;
		}
		printf("pixel = %02X\n", pixel);
	
	}


	// close the file 
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}





















