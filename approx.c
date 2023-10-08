#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "primes.h"

int main() {
    // Approximate value for the 1001st prime
    int n = 2 * (int)(1001 * log(1001));
    int* primeNumbers;
    int count;

    primeFinder(n, &primeNumbers, &count);

    if (count >= 1001) {
        printf("The 1001st prime number is: %d\n", primeNumbers[1000]); // 0-based index
    } else {
        printf("We could not find enough prime numbers.\n");
    }

    free(primeNumbers);

    return 0;
}
