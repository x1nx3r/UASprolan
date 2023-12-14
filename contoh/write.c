#include <stdio.h>

// Define a simple struct
struct Person {
    char name[50];
    int age;
};

int main() {
    // Create an array of structs
    struct Person people[3] = {
        {"John", 25},
        {"Alice", 30},
        {"Bob", 22}
    };

    // Declare a FILE pointer
    FILE *filePointer;

    // Open the file for writing (creates a new file or overwrites an existing one)
    filePointer = fopen("people.txt", "w");

    // Check if the file is successfully opened
    if (filePointer == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Write each struct to the file
    for (int i = 0; i < 3; i++) {
        fprintf(filePointer, "Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    // Close the file
    fclose(filePointer);

    printf("Data written to the file successfully.\n");

    return 0; // Exit without an error
}
