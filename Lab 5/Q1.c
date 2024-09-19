#include <stdio.h>

int main() {
   int cal, fat, calInFat;
   float percCal;
   printf("Enter grams of fat and total calories in the food: \n");
    scanf("%d %d", &fat, &cal);
   while (cal<0 || fat <0){
       printf("Enter grams of fat and total calories in the food: \n");
       scanf("%d %d", &fat, &cal);
   }
   calInFat = fat*9;
   if (calInFat > cal){
       printf("Error! Incorrect value for grams of fat or total calories");
   }
   else{
       percCal = calInFat/cal;
   printf("Precentage of calories from fat is %.2f", percCal);
   }
}