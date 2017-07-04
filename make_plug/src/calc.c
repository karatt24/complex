#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include "../include/strcompl.h"

char* redact(char *path){
	int i;
	char begin[256]="/home/2016/karatt24/complex/make_plug/plugin/";
	for(i=0; i<strlen(path); i++){
		begin[strlen(begin)+i]=path[i];
	}
	begin[strlen(begin)+1]='\0';
	return begin;
}

int main(){

	int t, i,sh = 0, sh2 = 0;
	struct my_complex a, b, c;
	char *g, **func, **fname, *buf;
	void **ext_lib;
	struct dirent **dir;
	char (*func_name)(char* namef);
	struct my_complex (*funct)(struct my_complex, struct my_complex);
	DIR *dp;
/*	dp=opendir(".");*/
	chdir("plugin");
	sh = scandir(get_current_dir_name(), &dir,0,NULL);
	func=malloc(sizeof(char*)*256);
	fname=malloc(sizeof(char*)*256);
	buf=malloc(23);
	for(i=0; i<sh; i++){
		func[i]=malloc(sizeof(char)*256);
		fname[i]=malloc(sizeof(char)*256);
	}

	buf="./";
	for(i=0; i<sh; i++){
		if(dir[i]->d_name[strlen(dir[i]->d_name)-2] == 's' && dir[i]->d_name[strlen(dir[i]->d_name)-1] == 'o'){
			snprintf(func[sh2],256, "%s%s", buf, dir[i]->d_name);
			sh2++;

		}
	}

	for(i=0; i<sh2; i++){
		printf("%d - %s\n\n", i+1, func[i]);
	}

	while(1){

/*		system("clear");
*/
		printf("Select the menu item:\n");

		for(i=0; i<sh2; i++){
			ext_lib[i] = dlopen(func[i], RTLD_NOW);
			func_name = dlsym(ext_lib, "namef");
			snprintf(fname[i], 256, "%s", func_name);
			printf("\n%s\n", func_name);
			dlclose(ext_lib);
		}

		for(i=0; i<sh2; i++){
			printf("%d - %s;\n", i, fname[i]);
		}
		printf("%d - QUIT\n", sh2);
		scanf("%d", &t);

		if(t != sh){
			printf("\nEnter complex number Z1:\na = ");
                	scanf("%d", &a.a);
                	printf("b = ");
                	scanf("%d",&a.b);

               		printf("\nEnter complex number Z2:\na = ");
                	scanf("%d", &b.a);
                	printf("b = ");
                	scanf("%d", &b.b);

			c = fname[t](a, b);
			printf("\nAnswer: Re=%d, Im=%d.", c.a, c.b);
		}

		if ( t == sh){
			exit(0);
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
		}*/
		printf("Answer = %d, %d\n",c.a, c.b);

	}
	dlclose(ext_lib);
	closedir(dp);

}
