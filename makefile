CC=gcc
LDFLAGS=$(shell pkg-config --cflags --libs check)

OBJECTS=converter.c
TESTS=converter-test.c

build: converter-test.c converter.c
	$(CC) -o converter-test.o $(OBJECTS) $(TESTS) $(LDFLAGS)

clean:
	rm -rf *.o