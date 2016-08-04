CC=gcc
LDFLAGS=$(shell pkg-config --cflags --libs check)

SOURCES=converter.c
TESTS=converter-test.c

TEST_OBJECT=converter-test.o

build: converter-test.c converter.c
	$(CC) -o $(TEST_OBJECT) $(SOURCES) $(TESTS) $(LDFLAGS)

test:
	./$(TEST_OBJECT)

clean:
	rm -rf *.o