//Q. Write a C program to multiply two matrices of size 3x3 and display the result matrix. Also subtract the resultant matrix from Matrix A as well.

#include <stdio.h>
int main() {
   int matrixA[3][3];
   int matrixB[3][3];
   int resultMatrix[3][3] = {0};
   
    printf("Enter the elements of the 3x3 matrix A \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    printf("Enter the elements of the 3x3 matrix B \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

   for(int row = 0; row < 3; row++){
    for (int col = 0; col < 3; col++) {
        for(int i = 0; i<3; i++){
            resultMatrix[row][col] += matrixA[row][i] * matrixB[i][col]; //i written to go down
        }
    }
   }

   printf("Resultant Matrix: \n");
   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
             printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
   }
    return 0;
}
