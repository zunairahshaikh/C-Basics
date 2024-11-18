#include <stdio.h>

#define maxTemp 45

void checkTemp(int userTemp){
    static int exceeded = 0;

    if(userTemp > maxTemp){
        printf("Temperature higher than the limit!");
        exceeded++;
    }

    printf("Number of times temperature was exceeded = %d", exceeded);
}
