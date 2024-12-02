/*Using Task. 4, resize that dynamic array of character and append the array with your studentId.
That student id must be taken input from the user.

DynamicArray = &quot;Muhib Ahmed&quot;; // Before

DynamicArray = &quot;K241234 Muhib Ahmed&quot;; // After the text append */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    char *dynamicArr, name[100], studentId[7];
    printf("Enter the total number of characters in your name (first+last with the space): ");
    scanf("%d", &N);

    dynamicArr = (char *)malloc(N, 1);
    if (dynamicArr == NULL)
    {
        printf("Cannot Allocate memory\n");
        return 1;
    }

    printf("Enter Your Name: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    strncpy(dynamicArr, name, N);

    printf("Enter your Student ID (KYYXXXX): ");
    fgets(studentId, sizeof(studentId), stdin);

    studentId[strcspn(studentId, "\n")] = '\0';

    int newSize = N + strlen(studentId) + 2; // +2 for space and null terminator
    dynamicArr = (char *)realloc(dynamicArr, newSize * sizeof(char));
    if (dynamicArr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    strcat(dynamicArr, " ");
    strcat(dynamicArray, studentId);

    printf("Full Name with Student ID: %s\n", dynamicArr);

    free(dynamicArr);
    return 0;
}
