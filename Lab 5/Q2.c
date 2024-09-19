#include <stdio.h>

int main() {
   int weekday, vacation, sleepIn;
   printf("is today a weekday? enter 1 for yes, 0 for no: ");
   scanf("%d", &weekday);
   printf("are you on vacation? enter 1 for yes, 0 for no: ");
   scanf("%d", &vacation);
    if (!weekday || vacation){
        sleepIn = 1;
    }
    if (sleepIn ==1){
        printf("true");
    }
    else{
        printf("false");
    }
}