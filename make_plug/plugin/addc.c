#include <math.h>
#include "../include/strcompl.h"

char namef[4] = "Add\0";
/*
char* namef(void){
	char *a;
	a = malloc(sizeof(char)*256);
	a = "Add";
	return a;
}
*/
struct my_complex Add(struct my_complex a, struct my_complex b){
        struct my_complex c;
        c.a=a.a+b.a;
        c.b=a.b+b.b;
        return c;
}

