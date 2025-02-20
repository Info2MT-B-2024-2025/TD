#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	double length; // no init !!
	double width;
	double height;
	unsigned char num_legs;
	double thickness;
	int material;
} table;

void display_table(const table u);
bool reset_table(table *u);

bool reset_table(table *u) {
	if(NULL==u) {
		return false;
	}

	// only if u is a pointer :
	// u->field
	// (*u).field
	
	u->length=0.;

	(*u).length=0.;
	(*u).width=0.;
	(*u).height=0.;
	(*u).num_legs=0;
	(*u).thickness=0.;
	(*u).material=0;

	return true;
}

void display_table(const table u) {
	printf("%-9s : %7.2lf\n", "length", u.length);
	printf("%-9s : %7.2lf\n", "width", u.width);
	printf("%-9s : %7.2lf\n", "height", u.height);
	printf("%-9s : %4d\n", "num_legs", u.num_legs);
	printf("%-9s : %7.2lf\n", "thickness", u.thickness);
	printf("%-9s : %4d\n", "material", u.material);
	return;
}

int main(int argc, const char *argv[])
{
	//printf("Size of int = %ld bytes.\n", sizeof(int));
	//printf("Size of table = %ld bytes.\n", sizeof(table)); // Warning PADDING
	table t={ .length=1.2, .height=0.8, .thickness=0.025, .width=0.6, .material=0, .num_legs=4};
	display_table(t);
	t.num_legs=5;
	display_table(t);
	reset_table(&t);
	display_table(t);
	return 0;
}