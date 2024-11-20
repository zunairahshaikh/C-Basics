/*Design a structure to store information about travel packages, including package name,
destination, duration, cost, and number of seats available. Write a program that allows
users to book a travel package and display available packages*/

#include <stdio.h>

typedef struct {
    char package_name[100];
    char destination[100];
    int duration_weeks;
    float cost;
    int available_seats;
} travel_package;

void display_packages(travel_package packages[], int size);
void book_package(travel_package packages[], int size);

int main() {
    int n = 3;
    travel_package packages[3] = {
        {"Mountain Getaway", "Nepal", 2, 1500.0, 10},
        {"Skiing Adventure", "Finland", 3, 2500.0, 5},
        {"Wildlife Safari", "Kenya", 1, 2000.0, 8}
    };

    int choice;

    while (1) {
        printf("\nTravel Package Booking System\n");
        printf("1. View Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_packages(packages, n);
                break;
            case 2:
                book_package(packages, n);
                break;
            case 3:
                printf("Thank you for using the Travel Package Booking System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void display_packages(travel_package packages[], int size) {
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < size; i++) {
        printf("Package %d:\n", i + 1);
        printf("  Name: %s\n", packages[i].package_name);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d weeks\n", packages[i].duration_weeks);
        printf("  Cost: $%.2f\n", packages[i].cost);
        printf("  Available Seats: %d\n", packages[i].available_seats);
        printf("\n");
    }
}

void book_package(travel_package packages[], int size) {
    int package_choice, seats_to_book;

    display_packages(packages, size);

    printf("Enter the package number you want to book: ");
    scanf("%d", &package_choice);

    if (package_choice < 1 || package_choice > size) {
        printf("Invalid package number. Please try again.\n");
        return;
    }

    printf("Enter the number of seats to book: ");
    scanf("%d", &seats_to_book);

    if (seats_to_book > packages[package_choice - 1].available_seats) {
        printf("Not enough seats available. Only %d seats left.\n",
               packages[package_choice - 1].available_seats);
    } else {
        packages[package_choice - 1].available_seats -= seats_to_book;
        printf("Successfully booked %d seat(s) for the '%s' package.\n",
               seats_to_book, packages[package_choice - 1].package_name);
    }
}
