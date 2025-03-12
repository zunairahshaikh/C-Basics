#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

const int SIZE = 5;

void generateRandomArray(char array[SIZE][SIZE]);
void printArray(char array[SIZE][SIZE]);
int searchString(char array[SIZE][SIZE], char *str);

int main() {
    char array[SIZE][SIZE];
    char input[100];
    int score = 0;

    srand(time(0));  //random number generator

    while (1) {
        generateRandomArray(array);
        printf("Current Array:\n");
        printArray(array);

        printf("Enter a string to search (or 'END' to stop): ");
        scanf("%s", input);

        for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]);
        }

        if (strcmp(input, "END") == 0) {
            printf("Re-populating the array with new random characters...\n");
            continue;  
        }    


        if (searchString(array, input)) {
            score++;
            printf("String found! Score: %d\n", score);
            printf("\n");
        } else {
            score--;
            printf("String not found. Score: %d\n", score);
             printf("\n");
        }
    }

    return 0;
}

void generateRandomArray(char array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = 'A' + rand() % 26;  // random uppercase letter
        }
    }
    
    array[SIZE - 1][0] = '0';
    array[SIZE - 1][1] = '9';
    array[SIZE - 1][2] = '8';
    array[SIZE - 1][3] = '6';
    for (int j = 4; j < SIZE; j++) {
        array[SIZE - 1][j] = 'A' + rand() % 26;  // random character for remaining columns
    }
}

void printArray(char array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

int searchString(char array[SIZE][SIZE], char *str) {
    int len = strlen(str);

    // l to r search
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (array[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }

    // top to d search
    for (int i = 0; i <= SIZE - len; i++) {
        for (int j = 0; j < SIZE; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (array[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }
}