SOURCE =addc.c subc.c divc.c multc.c
OBJECTS = $(SOURCE:.c=.o)
LIBS = $(addprefix lib, $(SOURCE:.c=.so))

all:$(LIBS)

lib%.so: %.o 
		gcc -shared $< -o $@ 

%.o: %.c strcompl.h
		gcc -c $^ -fPIC 
