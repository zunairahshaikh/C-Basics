#include <stdio.h>

int main() {
    int arr[3][3];
  
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        int row_smallest = arr[i][0];
        int col = 0;

        for (int j = 1; j < 3; j++) {  // // finding the smallest element in the current row
            if (arr[i][j] < row_smallest) {
                row_smallest = arr[i][j];
                col = j; 
            }
        }

        // checking if the smallest element is the largest in its column
        int is_saddle_point = 1;
        for (int k = 0; k < 3; k++) {
            if (arr[k][col] > row_smallest) {
                is_saddle_point = 0;
                break;
            }
        }

        if (is_saddle_point==1) {
            printf("Saddle points in the matrix are: %d at position (%d, %d)\n", row_smallest, i, col);
        }
    }

    return 0;
}
