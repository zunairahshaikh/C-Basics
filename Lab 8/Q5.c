#include <stdio.h>
int main() {
    //triangle
    for(int i=0;i<4;i++){
        for(int j=4;j>i;j--){
            printf(" ");
        }
        for(int k=0;k<i;k++){
            printf("* ");
        }
        printf("\n");
    }
    //upsidedown traingle
    for(int i=0;i<4;i++){
        for(int j=i;j>0;j--){
            printf(" ");
        }
        for(int k=4;k>i;k--){
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}
