#include <stdio.h>
int main()
{
	float taxRate, salary;
	printf("Enter tax rate: ");
	scanf("%f", &taxRate);
	printf("Enter salary: ");
	scanf("%f", &salary);
	salary = salary - (salary*(taxRate/100));
	printf("your remaining salary is: %.3f", salary);
}