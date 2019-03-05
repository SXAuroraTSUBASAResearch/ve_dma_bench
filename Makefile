NCC = /opt/nec/ve/bin/ncc
GCC = gcc

ALL = mkshm.x86 bench.ve

all: $(ALL)

mkshm.x86: mkshm.c
	$(GCC) -o $@ $^

bench.ve: bench.c
	$(NCC) -o $@ $^ -lveio -lpthread

clean:
	rm -f $(ALL) *.o
