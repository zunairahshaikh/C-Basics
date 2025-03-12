#include <stdio.h>
#include <ctype.h>

//global stuff
char grid[5][5]={
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
int Xpos = 4;
int Ypos = 4;

//prtotypes
void printGrid();
void movePlayer(char move);

int main(){
    char userMove;
    
    printf("*** Adventure Game ***\n");
    printf("Moves: \nA: left, D: right, W: up, S: down, Q: quit \n");
    printf("\n");
    
    do{
        printGrid();
        printf("Enter your move: ");
        scanf("%c", &userMove);
        
        userMove = toupper(userMove);
        
        while(userMove!='A'&& userMove!='W'&& userMove!='S'&& userMove!='D'&& userMove!='Q'){
            printf("Invalid input. \n\n");
            printf("Enter your move: ");
            scanf("%c", &userMove);
            userMove = toupper(userMove);
            }
        
        movePlayer(userMove);
    }
    while(userMove != 'Q');
    printf("Goodbye!");
    
    return 0;
}

//func defs
void printGrid(){
    printf("Cuurent Grid: \n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void movePlayer(char move){
    int new_x = Xpos;
    int new_y = Ypos;
    
    if (move == 'W')
        new_x--; 
    else if (move == 'S')
        new_x++; 
    else if (move == 'A')
        new_y--; 
    else if (move == 'D')
        new_y++;
        
    if (new_x < 0 || new_x >= 5 || new_y < 0 || new_y >= 5) {
        printf("Whoops can't move there!\n\n");
        return;
    }

    if (grid[new_x][new_y] == 'X') {
        printf("Stop! Obstacle ahead.\n\n");
        return;
    }
    if (grid[new_x][new_y] == 'I') {
        printf("Item collected!\n\n");
        grid[new_x][new_y] = ' ';
    }

    grid[Xpos][Ypos] = ' ';
    Xpos = new_x;
    Ypos = new_y;
    grid[Xpos][Ypos] = 'P';
}