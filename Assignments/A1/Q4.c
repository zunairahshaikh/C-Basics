#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sortString(char *str) { //sorting all the chars of the anagrams
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int findGroup(char keys[100][100], int count, char *key) { //checking if group alr exists
    for (int i = 0; i < count; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    char transactions[][100] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    n = sizeof(transactions) / sizeof(transactions[0]);

    char keys[100][100];
    char groups[100][100][100];
    int groupSizes[100] = {0};  // tracking of the size of each group
    int groupCount = 0;

    for (int i = 0; i < n; i++) {
        char sortedWord[100];
        strcpy(sortedWord, transactions[i]);
        sortString(sortedWord);

        // check if this sorted word matches an existing group key
        int groupIndex = findGroup(keys, groupCount, sortedWord);
        if (groupIndex == -1) {
            // make new group
            strcpy(keys[groupCount], sortedWord);
            strcpy(groups[groupCount][groupSizes[groupCount]], transactions[i]);
            groupSizes[groupCount]++;
            groupCount++;
        } else {
            strcpy(groups[groupIndex][groupSizes[groupIndex]], transactions[i]); //included in prev group
            groupSizes[groupIndex]++;
        }
    }

    // display the groups of anagrams
    printf("Grouped Anagrams:\n");
    for (int i = 0; i < groupCount; i++) {
        printf("[");
        for (int j = 0; j < groupSizes[i]; j++) {
            printf("%s", groups[i][j]);
            if (j < groupSizes[i] - 1) 
                printf(", ");
        }
        printf("]\n");
    }

    return 0;
}