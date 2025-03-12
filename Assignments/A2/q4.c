#include <stdio.h>
#include <stdlib.h>

struct Emp {
    int *r;
    int tScore;
};

void inputEmp(int **r, int nEmp, int nPer) {
    for (int i = 0; i < nEmp; i++) {
        for (int j = 0; j < nPer; j++) {
            do {
                printf("Enter rating for Emp %d, Period %d (1-10): ", i + 1, j + 1);
                scanf("%d", &r[i][j]);
                if (r[i][j] < 1 || r[i][j] > 10) {
                    printf("Invalid rating! Enter between 1 and 10.\n");
                }
            } while (r[i][j] < 1 || r[i][j] > 10);
        }
    }
}

void displayEmp(int **r, int nEmp, int nPer) {
    for (int i = 0; i < nEmp; i++) {
        printf("\nEmp %d Ratings:\n", i + 1);
        for (int j = 0; j < nPer; j++) {
            printf("Period %d: %d\n", j + 1, r[i][j]);
        }
    }
}

int bestEmp(int **r, int nEmp, int nPer) {
    int maxAvg = 0, empIdx = -1;
    for (int i = 0; i < nEmp; i++) {
        int sum = 0;
        for (int j = 0; j < nPer; j++) {
            sum += r[i][j];
        }
        int avg = sum / nPer;
        if (avg > maxAvg) {
            maxAvg = avg;
            empIdx = i;
        }
    }
    return empIdx;
}

int bestPeriod(int **r, int nEmp, int nPer) {
    int maxAvg = 0, periodIdx = -1;
    for (int j = 0; j < nPer; j++) {
        int sum = 0;
        for (int i = 0; i < nEmp; i++) {
            sum += r[i][j];
        }
        int avg = sum / nEmp;
        if (avg > maxAvg) {
            maxAvg = avg;
            periodIdx = j;
        }
    }
    return periodIdx;
}

int worstEmp(int **r, int nEmp, int nPer) {
    int minAvg = 10, empIdx = -1;
    for (int i = 0; i < nEmp; i++) {
        int sum = 0;
        for (int j = 0; j < nPer; j++) {
            sum += r[i][j];
        }
        int avg = sum / nPer;
        if (avg < minAvg) {
            minAvg = avg;
            empIdx = i;
        }
    }
    return empIdx;
}

int main() {
    int nEmp, nPer;
    printf("Enter number of employees: ");
    scanf("%d", &nEmp);
    printf("Enter number of periods: ");
    scanf("%d", &nPer);

    int **r = (int **)malloc(nEmp * sizeof(int *));
    for (int i = 0; i < nEmp; i++) {
        r[i] = (int *)malloc(nPer * sizeof(int));
    }

    inputEmp(r, nEmp, nPer);
    displayEmp(r, nEmp, nPer);

    int empOfYear = bestEmp(r, nEmp, nPer);
    printf("\nBest Employee: Emp %d\n", empOfYear + 1);

    int highPeriod = bestPeriod(r, nEmp, nPer);
    printf("\nBest Period: Period %d\n", highPeriod + 1);

    int worstEmpIdx = worstEmp(r, nEmp, nPer);
    printf("\nWorst Employee: Emp %d\n", worstEmpIdx + 1);

    for (int i = 0; i < nEmp; i++) {
        free(r[i]);
    }
    free(r);

    return 0;
}
