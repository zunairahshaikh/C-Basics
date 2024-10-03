int main() {
    char letter;
    for(letter =65; letter<71; letter++){
        if(letter ==65 || letter == 70){
            printf("%c %c %c %c %c %c\n", letter, letter+1,letter+2, letter+3, letter+4, letter+5);
        }
        else{
           printf("%c         %c \n", letter, letter+4); 
        }
    }
         return 0;
}
