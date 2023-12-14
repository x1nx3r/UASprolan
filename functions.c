#include<stdio.h>
#include<string.h>

struct Pasien {
    char nama[50];
    char umur[4];
    char jenisKelamin[24];
    char tingkatPenyakit[24];
};

int compareByNama(const struct Pasien *a, const struct Pasien *b) {
    return strcmp(a->nama, b->nama);
}

int compareByUmur(const struct Pasien *a, const struct Pasien *b) {
    return strcmp(a->umur, b->umur);
}

int compareByJenisPenyakit(const struct Pasien *a, const struct Pasien *b) {
    return strcmp(a->tingkatPenyakit, b->tingkatPenyakit);
}

void selectionSort(struct Pasien identitas[], int size, int (*compare)(const struct Pasien *, const struct Pasien *)) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (compare(&identitas[j], &identitas[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swap the elements if necessary
            struct Pasien temp = identitas[i];
            identitas[i] = identitas[minIndex];
            identitas[minIndex] = temp;
        }
    }
}

// Function to append an array of Person structs to a file
void appendPeopleToFile(const char *filename, struct Pasien *people, int count) {
    FILE *filePointer = fopen(filename, "a");

    if (filePointer == NULL) {
        perror("Error opening the file for appending");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(filePointer, "Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);
    }

    fclose(filePointer);
}

// Function to read an array of Person structs from a file
void readPeopleFromFile(const char *filename, struct Pasien *people, int count) {
    FILE *filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        perror("Error opening the file for reading");
        return;
    }

    for (int i = 0; i < count; i++) {
        int result = fscanf(filePointer, "Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);

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