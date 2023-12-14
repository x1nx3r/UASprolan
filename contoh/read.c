#include <stdio.h>
#include <stdlib.h>

struct Pasien {
    char nama[50];
    char umur[4];
    char jenisKelamin[24];
    char tingkatPenyakit[24];
};

void readPeopleFromFile(const char *filename, struct Pasien **people, int *count) {
    FILE *filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        perror("Error opening the file for reading");
        return;
    }

    // Determine the number of lines in the file
    int numberOfLines = 0;
    char buffer[1024]; // Adjust the buffer size as needed

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        numberOfLines++;
    }

    // Allocate memory for the array of struct Pasien based on the number of lines
    *people = (struct Pasien *)malloc(numberOfLines * sizeof(struct Pasien));

    if (*people == NULL) {
        perror("Error allocating memory");
        fclose(filePointer);
        return;
    }

    // Move the file pointer back to the beginning of the file
    fseek(filePointer, 0, SEEK_SET);

    // Read the contents of the file into the dynamically allocated array
    for (int i = 0; i < numberOfLines; i++) {
        int result = fscanf(filePointer, "Nama: %[^,], Umur: %[^,], Jenis Kelamin: %[^,], Tingkat Penyakit: %s\n",
                            (*people)[i].nama, (*people)[i].umur, (*people)[i].jenisKelamin, (*people)[i].tingkatPenyakit);

        if (result != 4) {
            perror("Error reading from the file");
            fclose(filePointer);
            free(*people);
            *people = NULL; // Set the pointer to NULL to indicate failure
            return;
        }

        // Consume the newline character
        fgetc(filePointer);
    }

    // Set the count variable
    *count = numberOfLines;

    fclose(filePointer);
}

int main() {
    const char *filename = "people.txt";
    struct Pasien *people;
    int count;

    readPeopleFromFile(filename, &people, &count);

    if (people != NULL) {
        // Now, 'people' contains the data from the file
        // 'count' contains the number of lines

        // Example: Print the data
        for (int i = 0; i < count; i++) {
            printf("Name: %s, Age: %s, Gender: %s, Disease Level: %s\n",
                   people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);
        }

        // Free the dynamically allocated memory when done
        free(people);
    }

    return 0;
}
