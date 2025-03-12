#include <stdio.h>

typedef struct 
{
    int day;
    int month;
    int year;
}Date;

typedef struct
{
    int employeeCode;
    char employeename[20];
    Date dateOfJoining;
}Employee;

void add_data(Employee arr[4]);
void calcTenure();

int main(){
    Employee empArr[4];
    add_data(empArr);
    printf("*****Employee Data:*****\n");
    for(int i = 0; i < 4; i++){
        printf("Employee %d:", i+1);
        printf("Code: %d\n", empArr[i].employeeCode);
        printf("Name: %s\n", empArr[i].employeename);
        printf("Date of Joining: %02d/%02d/%d\n", empArr[i].dateOfJoining.day, empArr[i].dateOfJoining.month, empArr[i].dateOfJoining.year);
        printf("\n");
    }
    calcTenure;
}

void add_data(Employee arr[4]){
    for(int i = 0; i < 4; i++){
        printf("Enter Employee Code for Employee %d: ", i+1);
        scanf("%d", &arr[i].employeeCode);

        printf("Enter Name for Employee %d: ",i+1);
        scanf(" %[^\n]", arr[i].employeename);

        printf("Enter Date of Joining (DD MM YYYY): ");
        scanf("%d %d %d", &arr[i].dateOfJoining.day, &arr[i].dateOfJoining.month, &arr[i].dateOfJoining.year);

        printf("\n");
    }
}

void calcTenure(Employee arr[4]){
    Date today;
    int oldCount = 0;
    printf("Enter today's date (DD MM YYYY): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    for(int i = 0; i < 4; i++){
        int totYears = 0, totMonths = 0, totDays = 0;

        totYears = today.year - arr[i].dateOfJoining.year;
        totMonths = today.month - arr[i].dateOfJoining.month;
        totDays = today.day - arr[i].dateOfJoining.day;


        // if (totDays < 0) {
        //     totMonths -= 1;
        //     totDays += daysInMonth((today.month == 1) ? 12 : today.month - 1, (today.month == 1) ? today.year - 1 : today.year);
        // }

        if (totMonths < 0) {
            totYears -= 1;
            totMonths += 12;
        }

        if(arr[i].dateOfJoining.year - today.year >= 3){
            oldCount++;
            printf("Employee %d:", i+1);
            printf("Code: %d\n", arr[i].employeeCode);
            printf("Name: %s\n", arr[i].employeename);
            printf("Date of Joining: %02d/%02d/%d\n", arr[i].dateOfJoining.day, arr[i].dateOfJoining.month, arr[i].dateOfJoining.year);
            printf("\n"); 
        }
    }

    printf("The number of employees who have a tenure of more than three years: %d", oldCount);
}
