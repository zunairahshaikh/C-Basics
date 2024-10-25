#include <stdio.h>
int main() {
    //triangle
    for(int i=0;i<5;i++){
        for(int j=5;j>i;j--){
            printf(" ");
        }
        for(int k=0;k<i;k++){
            printf("* ");
        }
        printf("\n");
    }
    //upsidedown traingle
    for(int i=0;i<5;i++){
        for(int j=i;j>0;j--){
            printf(" ");
        }
        for(int k=5;k>i;k--){
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}
