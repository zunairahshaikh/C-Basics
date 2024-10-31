/*Create a C program that swaps the values of two integers using a user-defined function,
swapIntegers. The user inputs two integer values, and the program uses the function to swap
them. It should perform the swap and display the updated values.*/ 

#include <stdio.h>

void swapintegers(int n1,int n2);
int main() {
    int num1,num2;
    printf("Enters numbers: \n");
    scanf("%d %d", &num1,&num2);
    
    swapintegers(num1,num2);

    return 0;
}

void swapintegers(int n1,int n2){
    int temp;
    temp =n1;
    n1=n2;
    n2=temp;
    
    printf("swapped: %d , %d", n1,n2);
}
