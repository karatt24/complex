#include <stdio.h>
#include <math.h>
#include "strcompl.h"

struct my_complex mcompl_add(struct my_complex a, struct my_complex b){
	struct my_complex c;
	c.a=a.a+b.a;
	c.b=a.b+b.b;
	return c;
}

struct my_complex mcompl_sub(struct my_complex a, struct my_complex b){
        struct my_complex c;
        c.a=a.a-b.a;
        c.b=a.b-b.b;
        return c;
}

struct my_complex mcompl_mult(struct my_complex a, struct my_complex b){
	struct my_complex c;
	c.a=a.a*b.a-a.b*b.b;
	c.b=a.a*b.b+a.b*b.a;
	return c;
}

struct my_complex mcompl_div(struct my_complex a, struct my_complex b){
        struct my_complex c;
        c.a=(a.a*b.a+a.b*b.b)/(pow(b.a,2)+pow(b.b, 2));
        c.b=(b.a*a.b - a.a*b.b)/(pow(b.a,2)+pow(b.b, 2));
	return c;
}




