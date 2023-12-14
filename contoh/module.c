#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

// Function to append an array of Person structs to a file
void appendPeopleToFile(const char *filename, struct Person *people, int count) {
    FILE *filePointer = fopen(filename, "a");

    if (filePointer == NULL) {
        perror("Error opening the file for appending");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(filePointer, "Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    fclose(filePointer);
}

// Function to read an array of Person structs from a file
void readPeopleFromFile(const char *filename, struct Person *people, int count) {
    FILE *filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        perror("Error opening the file for reading");
        return;
    }

    for (int i = 0; i < count; i++) {
        int result = fscanf(filePointer, "Name: %49[^,], Age: %d", people[i].name, &people[i].age);

        if (result != 2) {
            perror("Error reading from the file");
            fclose(filePointer);
            return;
        }

        // Consume the newline character
        fgetc(filePointer);
    }

    fclose(filePointer);
}

int main() {
    struct Person people[3] = {
        {"John", 25},
        {"Alice", 30},
        {"Bob", 22}
    };

    // Write to the file
    writePeopleToFile("people.txt", people, 3);
    printf("Data written to the file successfully.\n");

    // Read from the file
    readPeopleFromFile("people.txt", people, 3);

    // Now, 'people' array is populated with data from the file

    // You can use the array as needed

    // For example, print the data
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    return 0;
}
