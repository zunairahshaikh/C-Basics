#include <stdio.h>

int main()
{
    char character;

    printf("Enter a character: ");
    scanf(" %c", &character); 

    if (character >= 'A' && character <= 'Z') {
        printf("This is a capital letter\n");
    } 
else if (character >= 'a' && character <= 'z') {
        printf("This is a small letter\n");
    } else if (character >= '0' && character <= '9') {
        printf("This is a digit");
    } else if ((character >= '!' && character <= '/') || (character >= ':' && character <= '@') ||
               (character >= '[' && character <= '`') || (character >= '{' && character <= '~')) {
        printf("This is a special character");
    } else {
        printf("This is an undefined character"); 
    }

    return 0;
}
