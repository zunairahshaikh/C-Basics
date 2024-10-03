#include <stdio.h>

int main() {
    int usernum, lastdig,sum =0, check;
    printf("Enter the number you want to check: ");
    scanf("%d",&usernum);
    check = usernum;
    do{
        lastdig = check%10;
        sum+=lastdig*lastdig*lastdig;
        check/=10;
    }
    while(check!=0);
    if(sum == usernum)
        {printf("Number is an armstrong");}
    else
     {printf("Number is not an armstrong");}
}
