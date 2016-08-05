CC=gcc
COMPILER_FLAGS=-std=c99
LDFLAGS=$(shell pkg-config --cflags --libs check)

SOURCES=converter.c
TESTS=converter-test.c

TEST_OBJECT=converter-test.o

build: converter-test.c converter.c
	$(CC) $(COMPILER_FLAGS) -o $(TEST_OBJECT) $(SOURCES) $(TESTS) $(LDFLAGS)

test:
	./$(TEST_OBJECT)

clean:
	rm -rf *.o