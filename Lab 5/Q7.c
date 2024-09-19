#include <stdio.h>

int main() {
  int num;
  printf("enter a number: ");
  scanf("%d" , &num);
  num%10 ==0? printf("last digit zero"): printf("last digit non zero");
  
}
