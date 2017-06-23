SUBDIRS=lib src plugin
OBJECTS=calc.o
vpath %.c src: plugin
vpath %.h include
vpath %.o src: plugin
CFLAGS= -O2 -Wall -pedantic -ansi
LDFLAGS = -lm -ldl


.PHONY: prepare execute $(SUBDIRS) clear

all: one $(SUBDIRS)

one: $(OBJECTS)
		gcc -o calc $^ $(CFLAGS) $(LDFLAGS) -g

$(SUBDIRS):
		make -C $@


clear:
		rm calc.o ./plugin/libaddc.so ./plugin/libsubc.o .so ./plugin/libmultc.so ./plugin/libdivc.so ./plugin/addc.o ./plugin/subc.o ./plugin/multc.o ./plugin/divc.o
