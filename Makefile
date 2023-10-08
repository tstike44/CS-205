CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g3
LDFLAGS =

all: program consecutive sums

program: approx.c primes.c
	$(CC) $(CFLAGS) -o program approx.c primes.c $(LDFLAGS)

consecutive: consecutive.c
	$(CC) $(CFLAGS) -o consecutive consecutive.c $(LDFLAGS)

sums: sums.c
	$(CC) $(CFLAGS) -o sums sums.c $(LDFLAGS)

.PHONY: clean

prime: program
	./program

con: consecutive
	./consecutive nums.txt

sumnum: sums
	./sums 2000

clean:
	rm -f primes approx consecutive sums
