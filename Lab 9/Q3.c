/*Implement a function that checks if a given integer is a prime number. Use this function in the main program to check if numbers entered by the user are prime.*/ 

#include <stdio.h>

void checkPrime(int n);
int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    
    checkPrime(num);

    return 0;
}

void checkPrime(int n){
    int isPrime =1;
   for(int i = 2; i < n/2;i++){
       if(n%i == 0){
           isPrime = 0;
       }
       else
        continue;
   }
   if(isPrime){
       printf("Prime");
   }
   else
    printf("Not a prime");
}
