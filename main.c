#include <stdio.h>
#include "functions.c"
#include "menu.c"
#include <string.h>

int main(){
    struct Pasien people[90];
    const char *filename = "people.txt";
    int numberOfLines = countLines(filename);

    initializePeople(people, 90);
    readPeopleFromFile(filename, people, numberOfLines);
    
    int choice;
    while(1==1){
        main_menu();
        scanf("Masukkan pilihan",choice);
        switch (choice){
        case 1:
            scanf("");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    return 0;
}