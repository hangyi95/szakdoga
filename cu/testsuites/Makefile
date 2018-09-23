CFLAGS=-std=c99
CFLAGS=-Wl,-etestmain

CC ?= gcc
PYTHON ?= python

TEST_OBJS = test.o sakk.o

all: test 
	mkdir -p regressions
	cgcreate -g cpu,memory,devices,blkio:group
	cgset -r cpu.cfs_period_us=10000 group
	cgset -r cpu.cfs_quota_us=2000 group
	cgset -r  memory.limit_in_bytes=20M group
	cgset -r  memory.swappiness=0 group
	cgset -r devices.deny=a group
#	cgset -r blkio.throttle.read_bps_device="&{dev} 1048756" group
#	cgset -r blkio.throttle.write_bps_device="&{dev} 1048756" group
	cgexec -g cpu,memory,devices,blkio:group ./test


test: $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) -L../ -lcu

clean:
	rm -f *.o
	rm -f test
	rm -f test-segfault
	rm -f tmp.*


.PHONY: all clean
