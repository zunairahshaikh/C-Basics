/*Q2 Generate a pattern of odd/even numbers in a multi-dimension array of [2][n][2] where the first
2 is the different arrays for even and odd. The N is the amount of array quantity in each
odd/even array and the 2 are the two even/odd values in each of them, add them in decreasing
order starting from a user-specified number using nested loops. */

#include <stdio.h>

int main()
{
    int n;
    int start;

    printf("Enter the number of pairs (n): ");
    scanf("%d", &n);
    printf("Enter the starting number: ");
    scanf("%d", &start);

    int arr[2][n][2];
    int even_count = 0;
    int odd_count = 0;
    int num = start;

    while (even_count < n || odd_count < n)
    {
        if (num % 2 == 0)
        {
            if (even_count < n)
            {
                arr[0][even_count][0] = num;
                arr[0][even_count][1] = num - 2;
                even_count++;
            }
        }
        else
        {
            if (odd_count < n)
            {
                arr[1][odd_count][0] = num;
                arr[1][odd_count][1] = num - 2;
                odd_count++;
            }
        }
        num--;
    }

    printf("Even Numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d, %d]\n", arr[0][i][0], arr[0][i][1]);
    }

    printf("Odd Numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d, %d]\n", arr[1][i][0], arr[1][i][1]);
    }

    return 0;
}
