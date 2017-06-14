#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "strcompl.h"

int main(){

	int t;
	struct my_complex a, b, c;
	char *g;


	while(1){

		system("clear");

		printf("Select the menu item:\n");
		printf("1 - ADD;\n");
		printf("2 - SUBSTRACTION;\n");
		printf("3 - MULTIPLICATION\n");
		printf("4 - DIVISION\n");
		printf("5 - QUIT\n");
		scanf("%d", &t);

		if(t != 5){
			printf("\nEnter complex number Z1:\na = ");
                	scanf("%d", &a.a);
                	printf("b = ");
                	scanf("%d",&a.b);

               		printf("\nEnter complex number Z2:\na = ");
                	scanf("%d", &b.a);
                	printf("b = ");
                	scanf("%d",&b.b);
		}

		switch(t){
			case 1:
				c =mcompl_add(a,b);
				break;
			case 2:
				c = mcompl_sub(a,b);
				break;
			case 3:
				c = mcompl_mult(a,b);
				break;
			case 4:
				c = mcompl_div(a,b);
				break;
			default:
				exit(0);
				break;
		}
		printf("Answer = %d, %d\n",c.a, c.b);
		scanf("%s",&g);
//		system("clear");

	}

}
