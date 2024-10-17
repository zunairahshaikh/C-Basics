#include <stdio.h>

int main() {
int divisors[100], num,dcount=0, dsum=0;

printf("Enter your number: ");
scanf("%d", &num);

for(int i=1; i<=num/2;i++){ //i here is incrementing numbers till a divisor is found
    if(num%i==0){
        divisors[dcount]=i; //dcount points at position in divisors array to store the found
        dcount++;           //divisor at, then increment dcount to next pos
        dsum+=i;
    }
    
}
printf("Divisors: ");
for(int j=0;j<dcount; j++){
    printf("%d ", divisors[j]);
}
printf("\n");
if(dsum == num)
    printf("Perfect number 😎");
else if(dsum> num)
    printf("Abundant number 🤔");
else if(dsum < num)
    printf("Deficient number 😢");

    return 0;
}
