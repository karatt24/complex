#include <stdio.h>

struct my_complex mcompl_add(struct my_complex, struct my_complex);
struct my_complex mcompl_sub(struct my_complex, struct my_complex);
struct my_complex mcompl_mult(struct my_complex, struct my_complex);
struct my_complex mcompl_div(struct my_complex, struct my_complex);


struct my_complex{
	int a;
	int b;
};
