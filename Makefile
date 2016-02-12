CFLAGS=-Wall -g -std=c99

objs:=bubblesort mergesort quicksort insertionsort

all: $(objs)

clean:
	rm -f $(objs)
