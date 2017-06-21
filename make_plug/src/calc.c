#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/strcompl.h"

int main(){

	int t, i;sh = 0;
	struct my_complex a, b, c;
	char *g, **func, *func_name;
	void *ext_lib;
	struct dirent *dir
	DIR *dp;
	dp=opendir("plugin");

	func=malloc(sizeof(char *)*25);
	for(i=0; i<25; i++){
		func[i]=malloc(sizeof(char)*256);
	}

	while(dir=readdir(dp) != NULL){
		if(dir->d_name[strlen(dir->d_name)-2] == "s" && dir->d_name[strlen(dir->d_name)-1] == "o"){
			if(sh > 24){
				func=realloc(func, sizeof(char*));
				func[sh]=malloc(sizeof(char)*256);
			}
			func[sh] = dir->d_name;
			sh++;
		}
	}

	while(1){

		system("clear");

		printf("Select the menu item:\n");
/*		printf("1 - ADD;\n");
		printf("2 - SUBSTRACTION;\n");
		printf("3 - MULTIPLICATION\n");
		printf("4 - DIVISION\n");.
*/
		for(i=0; i<sh; i++){
			printf("%d - %s;\n", i, func[i]);
		}
		printf("%d - QUIT\n", sh);
		scanf("%d", &t);

		if(t != sh){
			printf("\nEnter complex number Z1:\na = ");
                	scanf("%d", &a.a);
                	printf("b = ");
                	scanf("%d",&a.b);

               		printf("\nEnter complex number Z2:\na = ");
                	scanf("%d", &b.a);
                	printf("b = ");
                	scanf("%d",&b.b);

			void (*funct)(struct my_complex; struct my_complex);

			ext_lib = dlopen(func[t], RTLD_NOW);
			func_name = dlsym(ext_lib, "func_name");
			funct = dlsym(ext_lib, func_name);
			c = funct(a, b);
			printf("\nAnswer: Re=%d, Im=%d.", c.a, c.b);
			dlclose(ext_lib);
		}

		if ( t == sh){
			break;
		}
/*		switch(t){
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
*/		printf("Answer = %d, %d\n",c.a, c.b);
		scanf("%s",&g);
//		system("clear");

	}

}
