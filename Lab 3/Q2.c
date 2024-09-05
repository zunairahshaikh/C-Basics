#include <stdio.h>
int main()
{
	int num1, num2, temp;
	printf("Enter 2 numbers: ");
	scanf("%d" "%d", &num1,&num2);
	temp = num1;
	num1 = num2;
	num2 = temp;
	printf("%d""%d", num1, num2);
}