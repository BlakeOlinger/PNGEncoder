CC = gcc
CFLAGS = -x c -std=c17 -Wall -Werror -O3 -march=native

build-tests: png.tests.o png.o
	$(CC) -o bin/png.tests bin/png.tests.o bin/png.o

png.tests.o: tests/png.tests.c
	$(CC) $(CFLAGS) -c -Iinclude/ -o bin/png.tests.o tests/png.tests.c

png.o: include/png.h src/png.c
	$(CC) $(CFLAGS) -c -Iinclude/ -o bin/png.o src/png.c

run-tests:
	clear
	./bin/png.tests
