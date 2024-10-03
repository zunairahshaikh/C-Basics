#include <stdio.h>
int main() {
    int num, sum =0;
    printf("Enter the number: ");
    scanf("%d", &num);
    while(num!=0){
        sum+=num;
        printf("%d, %d \n", num, sum);
        printf("Enter the number (or enter 0 to terminate program): ");
        scanf("%d", &num);
    }
    return 0;
}
