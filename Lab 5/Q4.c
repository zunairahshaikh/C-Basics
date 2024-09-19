#include <stdio.h>

int main() {
   int pH;
   printf("enyter pH: ");
   scanf("%d", &pH);
   if(pH >7){
       (pH < 12)? printf("Alkaline") : printf("Very alkaline");
   }
   else{
       if (pH == 7){
           printf("Neutral");
       }
       else{
           pH> 2? printf("acidic"): printf("very acidic");
       }
   }
}