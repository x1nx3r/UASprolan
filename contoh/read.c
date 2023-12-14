#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    // Create an array of structs
    struct Person people[3];

    // Declare a FILE pointer
    FILE *filePointer;

    // Open the file for reading
    filePointer = fopen("people.txt", "r");

    // Check if the file is successfully opened
    if (filePointer == NULL) {
        perror("Error opening the file");
        return 1; // Exit with an error code
    }

    // Read each struct from the file
    for (int i = 0; i < 3; i++) {
        // Temporary variables to check return value
        int age;
        char tempName[50];

        // Check the return value of fscanf
        if (fscanf(filePointer, "Name: %49[^,], Age: %d", tempName, &age) != 2) {
            perror("Error reading from the file");
            fclose(filePointer);
            return 1; // Exit with an error code
        }

        // Consume the newline character
        fgetc(filePointer);

        // Copy the temporary variables to the struct
        strcpy(people[i].name, tempName);
        people[i].age = age;
    }

    // Close the file
    fclose(filePointer);

    // Now, 'people' array is populated with data from the file

    // You can use the array as needed

    // For example, print the data
    for (int i = 0; i < 3; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }

    return 0; // Exit without an error
}
