#include <stdio.h>
#include <string.h>

char* minimizer(char InString[]);

int main() {
    int original_len, min_len, char_removed;
    char words[5][100];
    char minimized[100];
    
    for(int i = 0; i < 5; i++){
        printf("Enter word %d: ",i+1);
        scanf("%s", words[i]);
    }
    printf("\n");
    
    for(int i = 0; i < 5; i++){
        original_len = strlen(words[i]);
        strcpy(minimized, minimizer(words[i]));
        min_len = strlen(minimized);
        char_removed = original_len - min_len;

        printf("Minimized word: %s\nCharacters removed: %d\n", minimized, char_removed);
    }

    return 0;
}

char* minimizer(char InString[]){
    static char OutString[100];
    int OutStringPtr = 1;
    OutString[0] = InString[0];

    for(int letter = 1; InString[letter] != '\0'; letter++){
        if(InString[letter] != InString[letter - 1]){
            OutString[OutStringPtr] = InString[letter];
            OutStringPtr++;
        }
    }
    OutString[OutStringPtr] = '\0';
    return OutString;
}