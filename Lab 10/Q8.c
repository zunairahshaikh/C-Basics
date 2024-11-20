/*Write a recursive function linearSearch that takes an array, its size, the target element
to search for, and the current index. It checks if the target is at the current index and
continues searching in the subsequent indices until it either finds the target or exhausts
the array.*/

#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; //if the key is not found
}

int main() {
    int arr[] = {2,332,5,3,78,89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, result;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, size, key);

    if (result != -1) {
        printf("Element found at index: %d", result);
    } else {
        printf("Element not found in the array.");
    }

    return 0;
}
