#include <stdio.h>

int guaranteed_win(int N){
    if(N % 5==0)
        return -1;
    else
        return N % 5;
}