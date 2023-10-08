#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "primes.h"

void primeFinder(int n, int* primes[], int* count) {
    // Create an array to mark composites 
    // it finally worked
    bool* isComposite = (bool*)malloc((n + 1) * sizeof(bool));
    if (isComposite == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }


    for (int i = 0; i <= n; i++) {
        isComposite[i] = false;
    }

    int sqrtN = (int)sqrt(n);
    int primeCount = 0;

    for (int p = 2; p <= sqrtN; p++) {
        // If p is not marked as composite, it's a prime
        if (!isComposite[p]) {
            primeCount++;
            // Mark all multiples of p as composite
            for (int i = p * p; i <= n; i += p) {
                isComposite[i] = true;
            }
        }
    }

    // Count remaining unmarked numbers as prime
    for (int p = sqrtN + 1; p <= n; p++) {
        if (!isComposite[p]) {
            primeCount++;
        }
    }

    // Allocate memory for the primes array
    *primes = (int*)malloc(primeCount * sizeof(int));
    if (*primes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(isComposite);
        exit(1);
    }

    // Store prime numbers in the primes array
    int index = 0;
    for (int i = 2; i <= n; i++) {
        if (!isComposite[i]) {
            (*primes)[index++] = i;
        }
    }

    free(isComposite);

    // Set the count of primes
    *count = primeCount;
}