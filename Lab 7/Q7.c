#include <stdio.h>

int main() {
    int n;
    printf("array size: ");
    scanf("%d",&n);

  int num[n];
  int freq[100] ={0};
  
  for(int i = 0; i < n; i++){
      printf("Element %d: ",i+1);
      scanf("%d",&num[i]);
      freq[num[i]]++;
  }
  
  for (int i = 0; i < 100; i++) {
        if (freq[i] > 1) {
            printf("%d occurs more than once \n",i);
        }
    }

    return 0;
}
