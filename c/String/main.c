#include <stdio.h>
#include "string.h"
#include <conio.h>

void showMenu();
int choice, start, end;

int main() {

    //run the method
    void showMenu();
    getch();
    return 0;
}

void showMenu() {
    string x;
    while(1) {
        printf("\n\n\t\t\tWelcome to \"mystring.h\" Demo Program");
        printf("\n\t\t\t Press 1 to find the length of the string");
        printf("\n\t\t\t Press 2 to extract part of a string");
        printf("\n\t\t\t Press 3 to exit the demo");
        printf("\n\t\t Make your choice: \t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\t\t Enter Any string ");
            fflush(stdin);
            gets( &(*x));
            printf("%d", strlen(x));
            break;
        
        default:
            break;
        }
    }
}