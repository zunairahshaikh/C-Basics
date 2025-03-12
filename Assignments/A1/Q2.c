#include <stdio.h>
#include <string.h>

void countFrequencies(char slogans[3][14]);
int main() {
    char slogans[3][20]; 

    for (int i = 0; i < 3; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogans[i], 14, stdin);
    }

    countFrequencies(slogans);
    
    return 0;
}

void countFrequencies(char slogans[3][14]) {
    int freq[256] = {0};  // 256 for all ASCII characters

    // Count frequencies of characters in the slogans
    for (int word = 0; word < 3; word++) {
        for (int i = 0; slogans[word][i] != '\0'; i++) {
            freq[slogans[word][i]]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%s: \n", slogans[i]);
        for (int j = 0; j < 256; j++) {
            if (freq[j] > 0) {  // Checking if character appears
                printf(" '%c': %d", j, freq[j]);
            }
        }
        printf("\n");
    }
}
