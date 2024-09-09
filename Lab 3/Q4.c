#include <stdio.h>

int main() 
{
    int dist = 1207, fuelCostAB = 118, fuelCostBA=123;
    float fuelAvg, fuelConsumed, totalCost, totalConsumed;
    printf("Fuel average: ");
    scanf("%f", &fuelAvg);
    while (fuelAvg <0){
        printf("Invalid value. Must be greater than 0. \n");
        printf("Fuel average: ");
        scanf("%f", &fuelAvg);
    }
    
    fuelConsumed = dist/fuelAvg;
    totalCost = (fuelConsumed*fuelCostAB)+(fuelConsumed * fuelCostBA);
    totalConsumed = 2*fuelConsumed;
    
    printf("Total cost of fuel: %.2f \n",totalCost);
    printf("Total fuel consumed: %.2f litres", totalConsumed);
    return 0;
}