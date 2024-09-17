#include <stdio.h>

int main() 
{
    int units, id;
    float charge, surcharge =0;
    
    printf("Customer ID: ");
    scanf("%d", &id);
    printf("Units consumed: ");
    scanf("%d",&units);
    
    if (units <= 199){
        charge = units*16.20;
        printf("Customer ID: %d \n", id);
        printf("Units Consumed: %d \n", units);
        printf("Amount Charges @Rs. 16.20 per unit: %.2f \n", charge);
        printf("Surcharge Amount: %.2f \n", surcharge);
        printf("Net Amount Paid by the Customer: %.2f \n", charge+surcharge);
    }
    else if (units >=200 && units < 300){
        charge = units*20.10;
        printf("Customer ID: %d \n", id);
        printf("Units Consumed: %d \n", units);
        printf("Amount Charges @Rs. 20.10 per unit: %.2f \n", charge);
        printf("Surcharge Amount: %.2f \n", surcharge);
        printf("Net Amount Paid by the Customer: %.2f \n", charge+surcharge);
    }
    else if (units >=300 && units < 500){
        charge = units*27.10;
        printf("Customer ID: %d \n", id);
        printf("Units Consumed: %d \n", units);
        printf("Amount Charges @Rs. 27.10 per unit: %.2f \n", charge);
        printf("Surcharge Amount: %.2f \n", surcharge);
        printf("Net Amount Paid by the Customer: %.2f \n", charge+surcharge);
    }
    else if (units >= 500){
        charge = units*35.90;
        if (charge > 18000){
            surcharge = charge*0.15;
        }
        printf("\n");
        printf("Customer ID: %d \n", id);
        printf("Units Consumed: %d \n", units);
        printf("Amount Charges @Rs. 35.90 per unit: %.2f \n", charge);
        printf("Surcharge Amount: %.2f \n", surcharge);
        printf("Net Amount Paid by the Customer: %.2f \n", charge+surcharge);
    }
}