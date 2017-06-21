#include <stdio.h>
#include <math.h>
#include "../include/strcompl.h"


struct my_complex mcompl_mult(struct my_complex a, struct my_complex b){
        struct my_complex c;
        c.a=a.a*b.a-a.b*b.b;
        c.b=a.a*b.b+a.b*b.a;
        return c;
}

