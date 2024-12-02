/*Write a C Program to Find Largest Number in an array Using Dynamic Memory Allocation. Note:
The array must be dynamically resized and initially the array size will be taken by the user and
then resized by the user
Example arr[5]={1,2,3,4,5}
//After resizing
Arr[7]={1,2,3,4,5,6,7}
Take the same array and resize it. */

#include <stdio.h>
#include <stdlib.h>

void findLargest(int n, int *arr);

int main() {
    int n;
    int *arr;
    char choice;
    do{
     printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", (arr + i));
    }

    findLargest(n,arr);
    
    printf("Want to try again?(y/n): ");
    scanf(" %c", &choice);
    }
    while(choice == 'y' || choice == "Y");

    return 0;
}

void findLargest(int n, int *arr){
    int largest = arr[0];
    for(int i = 1; i <= n; i++){
        if(arr[i] > largest)
            largest = arr[i];
    }
    printf("\nThe largest element in the array is: %d\n", largest);
   
}
