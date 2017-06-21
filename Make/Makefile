SUBDIRS=lib src
OBJECTS=cond.o calc.o
vpath %.c src: lib
vpath %.h include
vpath %.o src: lib
LDFLAGS = -lm

.PHONY: prepare $(SUBDIRS)

prepare: $(SUBDIRS)

$(SUBDIRS):
		make -C $@

all: $(OBJECTS)
		gcc -o calc $^ $(LDFLAGS)
