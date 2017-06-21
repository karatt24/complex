#include <stdio.h>
#include <stdlib.h>

struct a {
	char c;
	int b;
} __attribute__((packed));


int main(){
	char ch[10]={'a',0,0,0,0,'b',0,0,0,0};

	struct a *str;
        str=(struct a *)ch;
        printf("%c %d\n", str->c, str->b);
        str++;
        printf("%c %d\n", str->c, str->b); 
}
