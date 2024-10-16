#include <stdio.h>

int main() {
    int x,n,divisor,term;
    double sum=1.0,mul;
    
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Enter total number of terms: ");
    scanf("%d",&n);
    
    for(int i =1; i<n; i++){
        term = i*2;
        mul =(double)x;
        divisor =1;
        
        for(int j =1; j<term; j++){
            mul*=x;
            divisor*=j+1;
        }
        if(i%2==1){
            sum-=(mul/divisor);
        }
        else{
            sum +=(mul/divisor);
        }
    }
    printf("\n");
    printf("The sum = %f\n",sum);
    printf("Number of terms = %d\n",n);
    printf("Value of x = %f\n",(double)x);
    
    return 0;
}
