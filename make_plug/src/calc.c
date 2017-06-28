#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
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

	int t, i,sh = 0;
	struct my_complex a, b, c;
	char *g, **func, **fname;
	void *ext_lib;
	struct dirent *dir;
	char (*func_name)(char* namef);
	struct my_complex (*funct)(struct my_complex, struct my_complex);
	DIR *dp;
	dp=opendir("plugin");

	func=malloc(sizeof(char *)*25);
	fname=malloc(sizeof(char*)*25);
	for(i=0; i<25; i++){
		func[i]=malloc(sizeof(char)*256);
		fname[i]=malloc(sizeof(char)*256);
	}

	while((dir=readdir(dp)) != NULL){
		if(dir->d_name[strlen(dir->d_name)-2] == 's' && dir->d_name[strlen(dir->d_name)-1] == 'o'){
			if(sh > 24){
				func=realloc(func, (sizeof(char*)*25+sizeof(char*)));
				func[sh]=malloc(sizeof(char)*256);
				func[sh]="/home/2016/karatt24/complex/make_plug/plugin/";
			}
			strcat(func[sh], dir->d_name);
		/*	func[sh] = redact(func[sh]);*/
			printf("\n%s\n%s\n", func[sh], dir->d_name);
			sh++;
		}
	}
printf("\n%d, ", sh);
	while(1){

/*		system("clear");
*/
		printf("Select the menu item:\n");

		for(i=0; i<sh; i++){
		/*	func[i]=redact(func[i]);*/
			ext_lib = dlopen(func[i], RTLD_NOW);
/*			func_name = dlsym(ext_lib, "namef");
*/			printf("\n%s\n", func_name);
			printf("\n%s",dlerror());
		/*	funct[i] = dlsym(ext_lib, fname[i]);
			dlclose(ext_lib);*/
		}

		for(i=0; i<sh; i++){
			printf("%d - %s;\n", i, fname[i]);
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
                	scanf("%d", &b.b);

		/*	c = funct[sh](a, b);*/
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
