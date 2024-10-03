#include <stdio.h>
int main(){
    
    for(int i = 0; i <9; i++){
        if(i==0 || i==8){
            printf("* * * * *");
        }
        else if(i==2 || i==6){
            printf("  *   *  ");
        }
        else if(i==4){
            printf("    *    ");
        }
        else
        {printf("\n");}
    }
}
