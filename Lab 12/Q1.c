//q1 Write a program that calculates the sum of all the elements in array using pointers
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int *arr;

    printf("Enter the number of elements in the array: ");
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

    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }

    printf("The sum of all elements in the array is: %d\n", sum);

    free(arr);

    return 0;
}
