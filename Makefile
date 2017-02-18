# Makefile for HPC 6220 Programming Assignment 1
CXX=mpic++

# activate for compiler optimizations:
CCFLAGS=-Wall -O3 -std=c++11
LDFLAGS=

all: poly-eval

poly-eval: main.o evaluator.o mpi_evaluator.o utils.o
	$(CXX) $(LDFLAGS) -o $@ $^


%.o: %.cpp %.h
	$(CXX) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CCFLAGS) -c $<

clean:
	rm -f *.o poly-eval
