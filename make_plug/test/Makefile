vpath %.h ./

CFLAGS= -O2 -Wall -ansi
LDFLAGS= -ldl


111: 1.o lib2.so
		gcc 1.o -o 111 $(CFLAGS) $(LDFLAGS)

1.o: 1.c answer.h
		gcc -c 1.c

lib2.so: 2.o
		gcc -shared -o lib2.so 2.o

2.o:
		gcc -c 2.c -fPIC
		 
