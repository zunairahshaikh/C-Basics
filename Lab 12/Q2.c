/*2: Write a program to implement the exchange or swap the values of 3 variables{a,b,c}. To
implement this, you need to write a function called swaped().
void swaped(int *aPtr, int *bPtr, int *cPtr);
such that;
b ----> temp
a ---->; b
c ----> a
temp ---> a */

#include <stdio.h>

void swapped(int *aPtr, int *bPtr, int *cPtr);

int main() {
    int a,b,c;
    int *aPtr, *bPtr, *cPtr;
    aPtr = &a;
    bPtr = &b;
    cPtr = &c;
    
    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);
    printf("Enter value for c: ");
    scanf("%d", &c);

    swapped(aPtr,bPtr,cPtr);

    return 0;
}

void swapped(int *aPtr, int *bPtr, int *cPtr){
    int temp;
    temp = *bPtr;
    *bPtr = *aPtr;
    *aPtr = *cPtr;
    *cPtr = temp;
    
    printf("After swapping the values are:\na = %d\nb = %d\nc = %d", *aPtr, *bPtr, *cPtr);
}
