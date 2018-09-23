CFLAGS=-std=c99
CFLAGS=-Wl,-etestmain

CC ?= gcc
PYTHON ?= python

TEST_OBJS = test.o sakk.o

all: test 
	mkdir -p regressions
	cgcreate -g cpu,memory:limiter
	echo 20000 > /sys/fs/cgroup/cpu/limiter/cpu.cfs_period_us
	echo 10000 > /sys/fs/cgroup/cpu/limiter/cpu.cfs_quota_us
	echo 20M > /sys/fs/cgroup/memory/limiter/memory.limit_in_bytes
	echo 0 > /sys/fs/cgroup/memory/limiter/memory.swappiness
	cgexec -g cpu,memory:limiter ./test


test: $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) -L../ -lcu

clean:
	rm -f *.o
	rm -f test
	rm -f test-segfault
	rm -f tmp.*


.PHONY: all clean
