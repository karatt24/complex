#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "answer.h"

/*struct answer{
	char* a;
	char* b;
};

void screen(struct answer buf){
	printf("%s ", buf.a);
	printf("%s ", buf.b);
}
*/
int main(){

	system("clear");
	void *ext;
	struct answer buf;
	void (*qwer)(struct answer b);

	ext = dlopen("./lib2.so", RTLD_NOW);
	qwer = dlsym(ext, "screen");
	buf.a=malloc(sizeof(char));
	buf.b=malloc(sizeof(char));
	buf.a="Priveeeet\n";
	buf.b="\nKaak dela?)\n";
	printf("\n\n\nHello world!)\n\n\n\n");

	qwer(buf);
	dlclose(ext);


	return 0;
}
