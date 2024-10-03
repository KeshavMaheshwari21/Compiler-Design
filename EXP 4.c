#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ASCII_SIZE 256

void countCharacters(const char *filename) {
    // Array to hold the count of each character
    int count[ASCII_SIZE] = {0};
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Read characters from the file and count them
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = tolower(ch);
        if (ch >= 0 && ch < ASCII_SIZE) {
             count[ch]++; 
        }
    }

    fclose(file);

    // Print the occurrences of each character
    printf("Character counts:\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (count[i] > 0 && isprint(i)) {
            printf("'%c' : %d\n", i, count[i]);
        }
    }
}
