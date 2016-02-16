CFLAGS=-Wall -g -std=c99 -lm

objs:=bubblesort mergesort quicksort insertionsort radixsort shellsort
objs+=die.o queue.o

all: $(objs)

pseudoradixsort: die.o

radixsort: die.o queue.o

queue.o: die.o

clean:
	rm -f $(objs)
