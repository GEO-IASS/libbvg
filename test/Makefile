
LINKER = $(CC)
CFLAGS += -I../include -I../src -O3
LOADLIBES += -lbvg
LDFLAGS += -L../

allcfiles := $(wildcard *.c)
allprogs := $(allcfiles:.c=)

all: $(allprogs) test test_big_mem
small: $(allprogs) test 
clean: 
	rm -rf $(allprogs) $(allcfiles:.c=.o)
	rm -rf bv_head_tail_1000.graph
	rm -rf bv_line.graph

.PHONY: all clean test

refill_test: refill_test.o
check_bvgraph: check_bvgraph.o

testfull: test
	./bvgraph_64bit_test bv_head_tail_1000 0

test_big_mem: bv_line.graph 
	./bvgraph_64bit_random_test ../data/bv_line

test: bv_head_tail_1000.graph
	./bitfile_test
	./bitfile_64bit_test
	./refill_test
	./eflist_test
	./bvgraph_test ../data/harvard500
	./check_bvgraph ../data/harvard500 random 10000
	./check_bvgraph ../data/wb-cs.stanford random 10000
	./bvgraph_64bit_test bv_head_tail_1000 1

bv_line.graph: bv_line.graph.bz2
	bzip2 -d -k -f bv_line.graph.bz2

bv_head_tail_1000.graph: bv_head_tail_1000.graph.bz2
	bzip2 -d -k -f bv_head_tail_1000.graph.bz2	
	
	


