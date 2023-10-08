#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    // Convert the command-line argument to an integer
    int limit = atoi(argv[1]);

    // Error check to ensure a valid number was provided
    if (limit <= 0) {
        printf("Enter a positive number.\n");
        return 1;
    }

    // Calculate the sum of multiples of 3 or 5 below the given limit
    int sum = 0;
    for (int i = 1; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("The sum of multiples of 3 or 5 below %d is: %d\n", limit, sum);

    return 0;
}

