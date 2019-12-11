SOURCE:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCE))
OUTS:=$(patsubst %.o,%.out,$(OBJECTS))
all:$(OUTS)

%.out:%.o
	g++ -o $@  $<
.PHOHY:clean
clean:
	rm -rf *.out *.o
