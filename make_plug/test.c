#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(){
	char asd[256]="123456789";
	printf("\n%s\n", asd);
	int i=strlen(asd);
	printf("\n%d\n", i);

	printf("\n<%c>\n", asd[strlen(asd)-1]);
}
