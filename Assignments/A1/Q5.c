#include <stdio.h>

void inputValues(int nums[], int *size);
void horizontalHistogram(int nums[], int size);
void verticalHistogram(int nums[], int size);

int main() {
    int nums[100];
    int size;

    inputValues(nums, &size);
    horizontalHistogram(nums, size);
    verticalHistogram(nums, size);

    return 0;
}

void inputValues(int nums[], int *size){
    printf("Enter the number of values: ");
    scanf("%d", size);
    
    printf("Enter %d values: ", *size);
    for (int i = 0; i < *size; i++){
        scanf("%d", &nums[i]);
    }
}

void horizontalHistogram(int nums[], int size){
    printf("Horizontal Histogram:\n");
    for (int i = 0; i < size; i++){
        printf("Value %d: ", i + 1);
        for (int j = 0; j < nums[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}

void verticalHistogram(int nums[], int size){
    printf("\nVertical Histogram:\n");
    int max = 0;
    
    for (int i = 0; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    for (int i = max; i > 0; i--){
        for (int j = 0; j < nums[i]; j++){
            if (nums[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}