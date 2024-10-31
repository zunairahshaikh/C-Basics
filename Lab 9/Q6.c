// Create a function that returns the maximum and minimum element in an integer array. Use this function in the main program to find the maximum and minimum from an array entered by the user.

#include <stdio.h>
void MaxAndMin(int arr[100],int size);
int main() {
    int nums[100];
    int len;
    printf("Enter length of array: ");
    scanf("%d",&len);
    for(int i = 0; i<len;i++){
      printf("Element %d: ", i+1);  
      scanf("%d", &nums[i]);
    }
    
    MaxAndMin(nums,len);

    return 0;
}

void MaxAndMin(int arr[100], int size){
    int max = arr[0];
    int min = arr[0];
    
    for(int i =1; i <size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("Maxiumum value is: %d \n", max);
    printf("Minimum value is: %d \n", min);
}
