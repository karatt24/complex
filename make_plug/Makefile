SUBDIRS=src plugin
OBJECTS=calc.o
vpath %.c src: plugin
vpath %.h include
vpath %.o src: plugin
CFLAGS= -O2 -Wall -pedantic -ansi
LDFLAGS = -lm -ldl -g


.PHONY: prepare execute $(SUBDIRS) clear

all: one $(SUBDIRS)

one: $(OBJECTS)
		gcc -o calc $^ $(CFLAGS) $(LDFLAGS)

$(SUBDIRS):
		make -C $@


clear:
		rm calc.o calc ./plugin/libaddc.so  ./plugin/libmultc.so ./plugin/libdivc.so ./plugin/libsubc.so ./src/calc.o 
