// Q1 Write a recursive function that takes an array and its size as input and prints all the elements.
#include <stdio.h>

void printArr(int arr[], int n, int start);

int main() {
    int nums[]= {33,4,16,81,55};
    int start = 0;
    int size = sizeof(nums)/sizeof(nums[0]);
    printArr(nums, size, start);
    printf("\n \n");

    return 0;
}

void printArr(int arr[], int n, int start){
    if(start >=n){  // base case
        return;
    }
    else{
        printf("%d ", arr[start]);
        printArr(arr, n, start+1);
    }
}
