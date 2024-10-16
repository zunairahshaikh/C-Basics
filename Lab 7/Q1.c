#include <stdio.h>

int main() {
    int temp, val;
    int arr[6];
    
    printf("Enter values for the array: \n");
     for(int i=0;i < 6;i++){
         scanf("%d",&val);
         arr[i]=val;
     }
     for(int i=0;i <6;i++){ //printing og array
         printf("%d " ,arr[i]);
     }
     
     printf("\n");
     
    temp =arr[5];
    for(int i=5;i > 0;i--){
            arr[i]= arr[i-1];
    }
    arr[0]=temp;
    
     for(int i=0;i <6;i++){ //printing shifted array
         printf("%d ",arr[i]);
     }
    

    return 0;
}
