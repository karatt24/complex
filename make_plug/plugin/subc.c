#include <stdio.h>
#include <math.h>
#include "../include/strcompl.h"

struct my_complex mcompl_sub(struct my_complex a, struct my_complex b){
        struct my_complex c;
        c.a=a.a-b.a;
        c.b=a.b-b.b;
        return c;
}

