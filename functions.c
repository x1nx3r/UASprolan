#include <stdio.h>
#include <string.h>

// Struktur untuk merepresentasikan data seorang pasien
struct Pasien {
    char nama[50];
    char umur[4];
    char jenisKelamin[24];
    char tingkatPenyakit[24];
};

// Fungsi untuk membandingkan dua pasien berdasarkan nama
int compareByNama(const struct Pasien *a, const struct Pasien *b) {
    return strcmp(a->nama, b->nama);
}

// Fungsi untuk membandingkan dua pasien berdasarkan umur
int compareByUmur(const struct Pasien *a, const struct Pasien *b) {
    return strcmp(a->umur, b->umur);
}

// Fungsi untuk membandingkan dua pasien berdasarkan jenis penyakit
int compareByJenisPenyakit(const struct Pasien *a, const struct Pasien *b) {
    return strcmp(a->tingkatPenyakit, b->tingkatPenyakit);
}


int countLines(const char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");

    // Check if the file is successfully opened
    if (file == NULL) {
        perror("Error opening the file");
        return -1; // Return -1 to indicate an error
    }

    int lineCount = 0;
    char buffer[1024]; // Adjust the buffer size as needed

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lineCount++;
    }

    // Close the file
    fclose(file);

    return lineCount;
}

// Fungsi untuk melakukan pengurutan (selection sort) pada array pasien
void selectionSort(struct Pasien identitas[], int size, int (*compare)(const struct Pasien *, const struct Pasien *)) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (compare(&identitas[j], &identitas[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Tukar elemen jika diperlukan
            struct Pasien temp = identitas[i];
            identitas[i] = identitas[minIndex];
            identitas[minIndex] = temp;
        }
    }
}

// Fungsi untuk menambahkan array pasien ke dalam file
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

// Fungsi untuk membaca array pasien dari file
void readPeopleFromFile(const char *filename, struct Pasien *people, int count) {
    FILE *filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        perror("Error opening the file for reading");
        return;
    }

    for (int i = 0; i < count; i++) {
        int result = fscanf(filePointer, "Nama: %[^,], Umur: %[^,], Jenis Kelamin: %[^,], Tingkat Penyakit: %s",
                            people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);

        if (result != 4) {
            perror("Error reading from the file");
            fclose(filePointer);
            return;
        }

        // Consume the newline character, if any
        int newline = fgetc(filePointer);
        if (newline != '\n' && newline != EOF) {
            ungetc(newline, filePointer); // Put the character back if it's not a newline or EOF
        }
    }

    fclose(filePointer);
}

// Fungsi untuk melakukan pencarian biner pada array pasien berdasarkan nama
int binarySearch(const struct Pasien people[], int size, const char key[]) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int cmp = strcmp(people[mid].nama, key);

        if (cmp == 0) return mid;  // Elemen ditemukan
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;  // Elemen tidak ditemukan
}

void initializePeople(struct Pasien people[], int size) {
    // Initialize the array with empty values
    for (int i = 0; i < size; i++) {
        strcpy(people[i].nama, "");  // Empty string indicates an empty element
    }
}

int findEmptyElement(struct Pasien people[], int size) {
    // Find the first element with an empty nama field
    for (int i = 0; i < size; i++) {
        if (strcmp(people[i].nama, "") == 0) {
            return i;  // Return the index of the empty element
        }
    }

    return -1;  // Return -1 if no empty element is found
}

// Fungsi sederhana untuk mencetak "Hello World"
void hello() {
    printf("Hello World");
}
