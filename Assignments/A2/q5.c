#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSupplies(char **species, char ***speciesSupplies, int numSpecies);
void UpdateSupplies(char **species, char ***speciesSupplies, int numSpecies);
void RemoveSpecies(char **species, char ***speciesSupplies, int *numSpecies);
void Display(char **species, char ***speciesSupplies, int numSpecies);

int main() {
    int numSpecies;
    printf("Enter number of species: ");
    scanf("%d", &numSpecies);

    char **species = (char **)malloc(numSpecies * sizeof(char *));
    char ***speciesSupplies = (char ***)malloc(numSpecies * sizeof(char **));

    for (int i = 0; i < numSpecies; i++) {
        char buffer[100];
        printf("Enter name of species: ");
        scanf("%99s", buffer);

        species[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(species[i], buffer);
        speciesSupplies[i] = NULL; 
    }

    addSupplies(species, speciesSupplies, numSpecies);
    Display(species, speciesSupplies, numSpecies);
    UpdateSupplies(species, speciesSupplies, numSpecies);
    Display(species, speciesSupplies, numSpecies);
    RemoveSpecies(species, speciesSupplies, &numSpecies);
    Display(species, speciesSupplies, numSpecies);

    // Free allocated memory
    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; speciesSupplies[i][j] != NULL; j++) {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
        free(species[i]);
    }
    free(species);
    free(speciesSupplies);

    return 0;
}

void addSupplies(char **species, char ***speciesSupplies, int numSpecies) {
    int numSupplies;
    for (int i = 0; i < numSpecies; i++) {
        printf("Enter number of supplies needed for %s: ", species[i]);
        scanf("%d", &numSupplies);
        speciesSupplies[i] = (char **)malloc((numSupplies + 1) * sizeof(char *));

        for (int j = 0; j < numSupplies; j++) {
            char buffer[100];
            printf("Enter supply %d for %s: ", j + 1, species[i]);
            scanf("%99s", buffer);

            speciesSupplies[i][j] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(speciesSupplies[i][j], buffer);
        }
        speciesSupplies[i][numSupplies] = NULL;
    }
}

void UpdateSupplies(char **species, char ***speciesSupplies, int numSpecies) {
    char userSpecies[100], newSupply[100], supplyToChange[100];
    int flag = 0, speciesIndex;

    printf("\nUpdating Supplies\nEnter species to change supply of: ");
    scanf("%99s", userSpecies);
    printf("Enter supply to update: ");
    scanf("%99s", supplyToChange);
    printf("Enter new supply: ");
    scanf("%99s", newSupply);

    for (int i = 0; i < numSpecies; i++) {
        if (strcmp(species[i], userSpecies) == 0) {
            speciesIndex = i;
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Invalid species name!\n");
        return;
    }

    flag = 0;
    for (int j = 0; speciesSupplies[speciesIndex][j] != NULL; j++) {
        if (strcmp(speciesSupplies[speciesIndex][j], supplyToChange) == 0) {
            strcpy(speciesSupplies[speciesIndex][j], newSupply);
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Supply updated successfully!\n");
    } else {
        printf("Supply not found!\n");
    }
}

void RemoveSpecies(char **species, char ***speciesSupplies, int *numSpecies) {
    char toRemove[100];
    int flag = 0, speciesIndex;

    printf("Enter species to remove: ");
    scanf("%99s", toRemove);

    for (int i = 0; i < *numSpecies; i++) {
        if (strcmp(species[i], toRemove) == 0) {
            flag = 1;
            speciesIndex = i;
            break;
        }
    }

    if (!flag) {
        printf("Invalid species entered!\n");
        return;
    }

    for (int j = 0; speciesSupplies[speciesIndex][j] != NULL; j++) {
        free(speciesSupplies[speciesIndex][j]);
    }
    free(speciesSupplies[speciesIndex]);
    free(species[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        species[i] = species[i + 1];
        speciesSupplies[i] = speciesSupplies[i + 1];
    }

    (*numSpecies)--;
}

void Display(char **species, char ***speciesSupplies, int numSpecies) {
    printf("\nSupplies For Each Species\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("\nSupplies for %s: ", species[i]);
        for (int j = 0; speciesSupplies[i][j] != NULL; j++) {
            printf("%s, ", speciesSupplies[i][j]);
        }
        printf("\n");
    }
}
