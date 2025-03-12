#include <stdio.h>

int main() {
   int arr[5];
   int smallest, sec_smallest;
   for(int i=0;i<5;i++){
       printf("element-%d: ",i);
       scanf("%d", &arr[i]);
   }
   if(arr[0]<arr[1]){
       smallest=arr[0];
       sec_smallest =arr[1];
   }
   else{
       smallest=arr[1];
       sec_smallest=arr[0];
   }
   for(int i=2;i<5;i++){
       if(arr[i]<smallest){
           sec_smallest=smallest;
           smallest=arr[i];
       }
       else if(arr[i]<sec_smallest){
           sec_smallest=arr[i];
       }
   }
   printf("The second smallest number in the array is: %d", sec_smallest);

   return 0;
}
