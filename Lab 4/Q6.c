#include <stdio.h>

int main() 
{
    float bill, newBill, saved;
    
    printf("Enter shopping bill: ");
    scanf("%f", &bill);
    
    if (bill < 500.00){
        printf("You're not eligible for a discount");
    }
    else{
        if (bill < 2000.00){
            saved = bill*0.05;
            newBill = bill - saved;
        }
        else if (bill >= 2000.00 && bill <4000.00){
            saved = bill*0.1;
            newBill = bill - saved;
        }
        else if (bill >= 4000.00 && bill < 6000.00){
            saved = 0.2*bill;
            newBill = bill - saved;
        }
        else{
            saved = bill*0.35;
            newBill = bill - saved;
        }
        printf("Total: %.2f \n", bill);
        printf("Amount saved: %.2f \n", saved);
        printf("Total after discount: %.2f", newBill);
    }
}