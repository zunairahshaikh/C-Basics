#include <stdio.h>

int main() {
    int P, T, R;
    float interest;
    
    printf("Enter principle value (must be between Rs.100-1,000,000): ");
    scanf("%d", &P);
    while (P < 100 || P >1000000) {
        printf("Invalid value.\n");
        printf("Enter principle value (must be between Rs.100-1,000,000): ");
        scanf("%d", &P);
    }
    
    printf("Enter percentage rate of interest (must be between 5-10): ");
    scanf("%d", &R);
    while (R < 5 || R >10) {
        printf("Invalid value.\n");
        printf("Enter percentage rate of interest (must be between 5-10): ");
        scanf("%d", &R);
    }
    
    printf("Enter time period (must be between 1-10 years): ");
    scanf("%d", &T);
    while (T < 1 || T >10) {
        printf("Invalid value.\n");
        printf("Enter time period (must be between 1-10 years): ");
        scanf("%d", &T);
    }
    
    interest = P*R*T/100.0;
    
    printf("Calculated interest is Rs. %.1f", interest);

    return 0;
}