CFLAGS=-Wall -g -std=c99

objs:=bubblesort mergesort

all: $(objs)

clean:
	rm -f $(objs)
