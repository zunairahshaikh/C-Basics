#include <stdio.h>
#include <ctype.h>

int main() {
    char InString[100], startChar, endChar;
    int len =0, isPalindrome = 1;
    
    printf("Enter your word: ");
    scanf("%s", InString);
    
   //calc length
   while(InString[len]!='\0'){ //while not string terminator, keep counting characters
       len++;
   }
   
   for(int i=0; i<=len/2;i++){
       startChar=tolower(InString[i]);
       endChar=tolower(InString[len -i -1]);
       if(startChar != endChar){
           isPalindrome =0;
           break;
       }
   }
    if(isPalindrome ==0)
        printf("Not a palindrome :(");
    else
        printf("Is a plaindrome =)");


    return 0;
}
