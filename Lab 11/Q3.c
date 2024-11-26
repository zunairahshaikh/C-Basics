//create a function to replace a word in a file with another word. read the file in memory, perform a search and replace, amd write the modified content back into the file

#include <stdio.h>
#include <string.h>

void replaceWordInFile(const char *filePath, const char *oldWord, const char *newWord) {
    FILE *file;
    FILE *tempFile;
    char line[1024];
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: Could not open the file '%s'.\n", filePath);
        return;
    }

   
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Could not create a temporary file.\n");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *pos = line;


        while ((pos = strstr(pos, oldWord)) != NULL) {
            
            fwrite(line, 1, pos - line, tempFile);

            fwrite(newWord, 1, newWordLen, tempFile);

            pos += oldWordLen;

            memmove(line, pos, strlen(pos) + 1);
            pos = line;
        }
      
        fputs(line, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove(filePath);
    rename("temp.txt", filePath);

    printf("All occurrences of '%s' have been replaced with '%s' in '%s'.\n", oldWord, newWord, filePath);
}

int main() {
    char filePath[100];
    char oldWord[50], newWord[50];

    printf("Enter the file path: ");
    scanf("%s", filePath);

    printf("Enter the word to replace: ");
    scanf("%s", oldWord);

    printf("Enter the new word: ");
    scanf("%s", newWord);

    replaceWordInFile(filePath, oldWord, newWord);

    return 0;
}
