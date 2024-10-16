#include <stdio.h>

int main() {
    int Acount=0, Ecount=0, Icount=0, Ucount=0, Ocount=0;
    char InString[100];
    
    printf("Enter your string: ");
    fgets(InString, sizeof(InString), stdin);
    
    for (int i = 0; InString[i] != '\0'; i++){
        char currChar = InString[i];
        switch(currChar){
            case 'a': case 'A':
                Acount++;
                break;
            
            case 'e': case 'E':
                Ecount++;
                break;
            
            case 'i': case'I':
                Icount++;
                break;
            
            case 'u': case 'U':
                Ucount++;
                break;
                
            case 'o': case 'O':
                Ocount++;
                break;
        }
    }
    
    printf("a=%d, e=%d, i=%d, o=%d, u=%d", Acount, Ecount, Icount, Ocount,Ucount);

    return 0;
}
