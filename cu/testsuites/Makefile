CFLAGS=-std=c99
CFLAGS=-Wl,-etestmain

CC ?= gcc
PYTHON ?= python

TEST_OBJS = test.o sakk.o

all: test 
	mkdir -p regressions
	-./test


test: $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) -L../ -lcu

clean:
	rm -f *.o
	rm -f test
	rm -f test-segfault
	rm -f tmp.*
	rm -rf regressions


.PHONY: all clean
