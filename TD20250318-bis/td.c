#include <stdio.h>
#include <stdlib.h>
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
	printf("height=%4u pixels\n", info_header.height);
	printf("width=%4u pixels\n", info_header.width);
	printf("data offset=%4u bytes\n", file_header.data_offset);
	
	fseek(f, file_header.data_offset, SEEK_SET); 

// 1. alloc dyn
// num_cells = info_header.height * info_header.width
// type = uint8_t
// pointer : uint8_t *pixels
	size_t num_cells = info_header.height * info_header.width;
	uint8_t *pixels=NULL;

	pixels=(uint8_t *)malloc(num_cells*sizeof(uint8_t));
	if(NULL==pixels) {
		printf("error while allocating memory for pixels at line %d\n",__LINE__);
	}
	else {
		ret=fread(pixels, sizeof(uint8_t), num_cells, f);
		if(ret!=num_cells) {
			printf("Error, unable to read data from [%s].\n", filename);
		}
		else {
			uint8_t min_value=pixels[0];
			uint8_t max_value=pixels[0];
			uint8_t mean_value=0;
			size_t sum_of_pixels=pixels[0];
			for(size_t index=1;index<num_cells;index++) {
				min_value = pixels[index] < min_value ? pixels[index] : min_value;
				max_value = pixels[index] > max_value ? pixels[index] : max_value;
				sum_of_pixels+=pixels[index];
			}
			mean_value=sum_of_pixels/num_cells;
			printf("min  = %3hhu\n", min_value);
			printf("max  = %3hhu\n", max_value);
			printf("mean = %3hhu\n", mean_value);
		}
		free(pixels);
		pixels=NULL;
	}

	// close the file 
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}
