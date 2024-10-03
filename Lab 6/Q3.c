#include <stdio.h>

int main() {
    int num, isPrime=1, num1=0, num2=1, temp;
    printf("Enter the number you want to check: ");
    scanf("%d", &num);
    if(num==1 ||num ==0)
        printf("Not a prime number");
    for(int i=2; i<num;i++){
        if(num%i==0)
            isPrime =0;
    }
    if (isPrime ==0)
        printf("Number is not a prime");
    else
        printf("Number is a prime\n");
   
   if (isPrime ==1){
       for(int j =0;j<num; j++){
           printf("%d,", num1);
           temp = num1+num2;
           num1= num2;
           num2=temp;
       }
   }
}
