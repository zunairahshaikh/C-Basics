#include <stdio.h>

int main() {
  int num[10];
  int freq[10] ={0};
  
  printf("Enter numbers: \n");
  for(int i=0;i<10;i++){
      scanf("%d", &num[i]);
      freq[num[i]]++;
  }
  
  for(int i=0;i<10;i++){
      if(freq[i]>0){
          printf("%d occurs %d times",i,freq[i]);
      }
  }

    return 0;
}
