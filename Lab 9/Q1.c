#include <stdio.h>
#include <string.h>

void checkPal(char InString[5][20]);

int main(){
    char words[5][20];
    int i;
    for( i =0; i < 5; i++){
    	printf("Enter word %d: ", i+1);
    	scanf("%s",&words[i]);
	}
    checkPal(words);
}

void checkPal(char InString[5][20]){
	int i;
    for(i = 0; i < 5;i++){
    	char checkStr[20];
    	strcpy(checkStr, InString[i]);
        strrev(InString[i]);
        if(strcmp(InString[i],checkStr)==0)
            printf("Palindrome \n");
        else
            printf("Not a palindrome \n");
    }
}
