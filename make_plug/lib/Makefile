vpath %.h ../include

libcond.so: cond.o
		gcc -shared -o libcond.so cond.o

cond.o: cond.c strcompl.h
		gcc -c cond.c -fPIC
