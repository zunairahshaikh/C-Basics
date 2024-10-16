#include <stdio.h>

int main() {
    int n; 
    double sum=1.0;
    
    printf("Enter total number of terms: ");
    scanf("%d",&n);
    
    printf("1 \n");
    for(int i=2; i<=n;i++){
        printf("1/%d \n",i);
        sum+=1.0/(double)i;
    }
    printf("Sum = %f",sum);

    return 0;
}
