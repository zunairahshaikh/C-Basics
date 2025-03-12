#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    int atCount = 0;
    int dotAfterAt = 0;
    int len = strlen(email);

    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atCount++;
            if (i < len - 1 && email[i+1] == '.') {
                dotAfterAt = 1;
            }
        } else if (email[i] == '.') {
            if (atCount > 0) {
                dotAfterAt = 1;
            }
        }
    }

    if (atCount == 1 && dotAfterAt) {
        return 1;
    }
    return 0;
}

int main() {
    char *email;
    int length;

    printf("Enter your email address: ");
    scanf("%d", &length);
    email = (char*)malloc(length + 1);

    if (email == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    scanf("%s", email);

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}
