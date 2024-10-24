#include <stdio.h>

int main() {
    int range, isPrime;
    printf("Enter range: ");
    scanf("%d",&range);
    
    for(int i=2;i<=range;i++){
        isPrime=1;
        for(int j=2;j<i;j++){
            if(i%j==0)
                isPrime=0;
                break;
        }
        if(isPrime==1){
        printf("%d ",i);
    }
    }
    

    return 0;
}
