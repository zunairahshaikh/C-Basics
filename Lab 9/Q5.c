/*Create a function that reverses a given string and returns the reversed string. Use this function in the main program to display the reversed string entered by the user.*/ 

#include <stdio.h>
#include <string.h>

void reversedStr(char str[100]);
int main(){
    char userInput[100];
    printf("Enter your string:");
    scanf("%s", &userInput);
    reversedStr(userInput);
}

void reversedStr(char str[100]){
    int length=strlen(str);
    char reversed[100];
    for(int i=0;i<length;i++){
        reversed[i]=str[length-1-i];
    }
    reversed[length]='\0';
    printf("Reversed string is %s",reversed);
}
