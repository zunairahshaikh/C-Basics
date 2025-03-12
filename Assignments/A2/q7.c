#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Content {
    char title[100];
    float rating;
    int runtime;
    char format[50];
};

struct UserProfile {
    double *engagementScores;
    double **devicePreferences;
};

void inputContent(struct Content *content) {
    printf("Enter content title: ");
    scanf(" %[^\n]s", content->title);
    printf("Enter rating (0 to 5): ");
    scanf("%f", &content->rating);
    printf("Enter runtime (in minutes): ");
    scanf("%d", &content->runtime);
    printf("Enter format (e.g., 1080p, 4k, etc.): ");
    scanf(" %[^\n]s", content->format);
}

void inputUserProfile(struct UserProfile *user, int numCategories, int numDevices) {
    user->engagementScores = malloc(numCategories * sizeof(double));
    if (user->engagementScores == NULL) {
        printf("Memory allocation failed for engagement scores.\n");
        exit(1);
    }
    for (int i = 0; i < numCategories; i++) {
        printf("Enter engagement score for category %d: ", i + 1);
        scanf("%lf", &user->engagementScores[i]);
    }
    user->devicePreferences = malloc(numDevices * sizeof(double *));
    if (user->devicePreferences == NULL) {
        printf("Memory allocation failed for device preferences.\n");
        free(user->engagementScores);
        exit(1);
    }
    for (int i = 0; i < numDevices; i++) {
        user->devicePreferences[i] = malloc(3 * sizeof(double));
        if (user->devicePreferences[i] == NULL) {
            printf("Memory allocation failed for device preferences row.\n");
            free(user->engagementScores);
            for (int j = 0; j < i; j++) {
                free(user->devicePreferences[j]);
            }
            free(user->devicePreferences);
            exit(1);
        }
        printf("Enter preferences for device %d (Resolution, Bandwidth, Playback Position): ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &user->devicePreferences[i][j]);
        }
    }
}

void inputMatrix(double ***matrix, int rows, int cols, const char *promptFormat) {
    *matrix = malloc(rows * sizeof(double *));
    if (*matrix == NULL) {
        printf("Memory allocation failed for matrix.\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = malloc(cols * sizeof(double));
        if ((*matrix)[i] == NULL) {
            printf("Memory allocation failed for matrix row.\n");
            for (int j = 0; j < i; j++) {
                free((*matrix)[j]);
            }
            free(*matrix);
            exit(1);
        }
        for (int j = 0; j < cols; j++) {
            printf(promptFormat, i + 1, j + 1);
            scanf("%lf", &(*matrix)[i][j]);
        }
    }
}

void displayContent(struct Content *content) {
    printf("Content: %s\n", content->title);
    printf("Rating: %.2f, Runtime: %d mins, Format: %s\n", content->rating, content->runtime, content->format);
}

void displayUserProfile(struct UserProfile *user, int numCategories, int numDevices) {
    printf("User Engagement Scores:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d: %.2f\n", i + 1, user->engagementScores[i]);
    }
    printf("Device Preferences:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("Device %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", user->devicePreferences[i][j]);
        }
        printf("\n");
    }
}

void displayMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void cleanupUserProfile(struct UserProfile *user, int numDevices) {
    free(user->engagementScores);
    for (int i = 0; i < numDevices; i++) {
        free(user->devicePreferences[i]);
    }
    free(user->devicePreferences);
}

void cleanupMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int numUsers = 3, numCategories = 3, numDevices = 2;
    double **engagementMatrix, **deviceMatrix;
    struct UserProfile users[numUsers];
    struct Content content[numCategories];

    inputMatrix(&engagementMatrix, numUsers, numCategories, "Enter engagement score for user %d, category %d: ");
    inputMatrix(&deviceMatrix, numUsers, numDevices, "Enter device preference for user %d, device %d: ");

    for (int i = 0; i < numCategories; i++) {
        inputContent(&content[i]);
    }

    for (int i = 0; i < numUsers; i++) {
        printf("Enter user %d profile:\n", i + 1);
        inputUserProfile(&users[i], numCategories, numDevices);
    }

    printf("\n--- Content Information ---\n");
    for (int i = 0; i < numCategories; i++) {
        displayContent(&content[i]);
    }

    printf("\n--- User Profiles ---\n");
    for (int i = 0; i < numUsers; i++) {
        displayUserProfile(&users[i], numCategories, numDevices);
    }

    printf("\n--- Engagement Matrix ---\n");
    displayMatrix(engagementMatrix, numUsers, numCategories);

    printf("\n--- Device Matrix ---\n");
    displayMatrix(deviceMatrix, numUsers, numDevices);

    cleanupMatrix(engagementMatrix, numUsers);
    cleanupMatrix(deviceMatrix, numUsers);
    for (int i = 0; i < numUsers; i++) {
        cleanupUserProfile(&users[i], numDevices);
    }

    return 0;
}