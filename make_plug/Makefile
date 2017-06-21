SUBDIRS=lib src
OBJECTS=calc.o
vpath %.c src: lib
vpath %.h include
vpath %.o src: lib
CFLAGS= -O2 -Wall -pedantic -ansi
LDFLAGS = -lm -ldl


.PHONY: prepare execute $(SUBDIRS)

all: one $(SUBDIRS)

one: $(OBJECTS)
		gcc -o calc $^ $(CFLAGS) $(LDFLAGS) -g

$(SUBDIRS):
		make -C $@
