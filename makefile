CC=gcc
COMPILER_FLAGS=-std=c99
LDFLAGS=$(shell pkg-config --cflags --libs check)

SOURCES=roman_math.c
TESTS=roman_math_test.c

TEST_OBJECT=roman_math_test.o

build: roman_math_test.c roman_math.c
	$(CC) $(COMPILER_FLAGS) -o $(TEST_OBJECT) $(SOURCES) $(TESTS) $(LDFLAGS)

test:
	./$(TEST_OBJECT)

clean:
	rm -rf *.o