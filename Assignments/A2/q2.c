#include <stdio.h>
#include <string.h>

#define BALLS 12

struct Player {
    int ballScores[BALLS];
    char playerName[100];
    int totalScore;
};

int validateScore(int score) {
    if (score >= 0 && score <= 6) {
        return score;
    }
    return -1;
}

void playGame(struct Player *player) {
    for (int i = 0; i < BALLS; i++) {
        int score;
        printf("%s, enter score for ball %d (0-6): ", player->playerName, i + 1);
        scanf("%d", &score);
        
        int validScore = validateScore(score);
        if (validScore != -1) {
            player->ballScores[i] = validScore;
        } else {
            player->ballScores[i] = 0;
            printf("Invalid score! Ball marked as 0.\n");
        }
    }
}

void calculateTotalScore(struct Player *player) {
    player->totalScore = 0;
    for (int i = 0; i < BALLS; i++) {
        player->totalScore += player->ballScores[i];
    }
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with a total score of %d!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("%s wins with a total score of %d!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both players scored %d.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("\n%s's Performance:\n", player1.playerName);
    int player1Total = 0;
    for (int i = 0; i < BALLS; i++) {
        printf("Ball %d: %d runs\n", i + 1, player1.ballScores[i]);
        player1Total += player1.ballScores[i];
    }
    printf("Total score: %d\n", player1Total);
    printf("Average score: %.2f\n", player1Total / (float)BALLS);

    printf("\n%s's Performance:\n", player2.playerName);
    int player2Total = 0;
    for (int i = 0; i < BALLS; i++) {
        printf("Ball %d: %d runs\n", i + 1, player2.ballScores[i]);
        player2Total += player2.ballScores[i];
    }
    printf("Total score: %d\n", player2Total);
    printf("Average score: %.2f\n", player2Total / (float)BALLS);
}

int main() {
    struct Player player1, player2;

    printf("Enter name for Player 1: ");
    scanf(" %[^\n]s", player1.playerName);
    printf("Enter name for Player 2: ");
    scanf(" %[^\n]s", player2.playerName);

    printf("\n%s's turn:\n", player1.playerName);
    playGame(&player1);
    printf("\n%s's turn:\n", player2.playerName);
    playGame(&player2);

    calculateTotalScore(&player1);
    calculateTotalScore(&player2);

    displayMatchScoreboard(player1, player2);

    findWinner(player1, player2);

    return 0;
}
