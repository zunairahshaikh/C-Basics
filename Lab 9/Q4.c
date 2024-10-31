/*Write a C program with a user-defined function calculate to perform basic arithmetic operations such as addition, subtraction, multiplication, and division. The program should take two numbers and an operation choice as input, and then use the function to perform the operation.*/ 

#include <stdio.h>

double arith(int n1,int n2, char opr);
int main() {
    int num1, num2;
    float result;
    char opr;
    printf("Enter numbers: \n");
    scanf("%d %d", &num1, &num2);
    printf("Enter your desired operation: ");
    scanf(" %c", &opr);
    while(opr!='+' && opr!='-' && opr!= '*' && opr!='/'){
        printf("Invalid operation \n");
        printf("Enter your desired operation: ");
        scanf(" %c", &opr);
    }
    
    result = arith(num1,num2, opr);
    printf("answer = %.2f", result);
    return 0;
}

double arith(int n1,int n2, char opr){
    double ans;
   switch(opr){
       case '+':
        ans = n1+n2;
        break;
       case '-':
        ans = n1-n2;
        break;  
       case '*':
        ans = n1*n2;
        break;
       case '/':
        ans = n1/n2;
        break;
   }
   return ans;
}
