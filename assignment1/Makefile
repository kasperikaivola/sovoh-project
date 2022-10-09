
CFLAGS=-Wall -pedantic

all: morse

main: main.o
	gcc $^ -o $@

child: child.o
	gcc $^ -o $@

.PHONY: clean

clean:
	rm -rf *.o *~
	
