#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ASCII_SIZE 256

// Function to count the occurrences of characters in the file
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

int main() {
    char filename[100];

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Call the function to count characters in the file
    countCharacters(filename);

    return 0;
}
