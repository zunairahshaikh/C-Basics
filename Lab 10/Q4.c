/* Q4 Define a Book structure with fields like title, author, publication_year, and price. Create
an array of books and write functions to:
1. Display all books in the library
2. Search for a book by title
3. List book by a specific author*/

#include <stdio.h>
#include <string.h>

struct book{
    char title[50];
    char author[50];
    int publication_year;
    float price;
};
myBooks[3] = {
        {"Pride and Prejudice", "Austen", 1813, 25.50},
        {"Mansfield Park", "Austen", 1814, 30.10},
        {"Jane Eyre", "Bronte", 1847, 31.00}
    };

void displayBooks();
void searchBook(char title[]);
void listByAuthor(char author[]);
int main() {
    
    displayBooks();
    searchBook("Jane Eyre");
    listByAuthor("Austen");

    return 0;
}

void displayBooks(){
    for(int i = 0; i < 3; i++){
        printf("Book %d: \n", i+1);
        printf("Title: %s \nAuthor: %s \nPublication Year: %d \nPrice: %.2f \n", myBooks[i].title, myBooks[i].author, myBooks[i].publication_year, myBooks[i].price);
        printf("\n");
    }
}

void searchBook(char title[]){
    for(int i = 0; i < 3; i++){
        if(strcmp(myBooks[i].title, title)==0){
            printf("Book Details: \n");
            printf("Title: %s \nAuthor: %s \nPublication Year: %d \nPrice: %.2f \n", myBooks[i].title, myBooks[i].author, myBooks[i].publication_year, myBooks[i].price);
            printf("\n");
        }
    }
}

void listByAuthor(char author[]){
    for(int i = 0; i < 3; i++){
        if(strcmp(myBooks[i].author, author)==0){
            printf("Book Details: \n");
            printf("Title: %s \nAuthor: %s \nPublication Year: %d \nPrice: %.2f \n", myBooks[i].title, myBooks[i].author, myBooks[i].publication_year, myBooks[i].price);
            printf("\n");
        }
    }
}
