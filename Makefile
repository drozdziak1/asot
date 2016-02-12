CFLAGS=-Wall -g -std=c99

objs:=bubblesort mergesort quicksort

all: $(objs)

clean:
	rm -f $(objs)
