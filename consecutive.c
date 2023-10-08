#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define NUM_DIGITS 1000
#define CONSECUTIVE_DIGITS 5

int main(int argc, char* argv[]) {
    // Check arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file and handle any error 
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the number from the file
    char digit;
    char number[NUM_DIGITS];
    int i = 0;

    while ((digit = fgetc(file)) != EOF) {
        if (isdigit(digit)) {
            // Convert character to integer
            number[i++] = digit - '0'; 
        }
    }

    fclose(file);
    
    //error handling
    if (i != NUM_DIGITS) {
        fprintf(stderr, "Error: Expected %d digits, but found %d digits in the file.\n", NUM_DIGITS, i);
        return 1;
    }

    // Find the greatest product of five consecutive digits
    int64_t maxProduct = 0;
    for (int j = 0; j <= NUM_DIGITS - CONSECUTIVE_DIGITS; j++) {
        int64_t product = 1;
        for (int k = 0; k < CONSECUTIVE_DIGITS; k++) {
            product *= number[j + k];
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }

    printf("The greatest product of %d consecutive digits is: %lld\n", CONSECUTIVE_DIGITS, maxProduct);

    return 0;
}
