#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

struct Pasien {
    char nama[50];
    char umur[4];
    char jenisKelamin[24];
    char tingkatPenyakit[24];
};

int compareByNama(const struct Pasien *a, const struct Pasien *b);
int compareByUmur(const struct Pasien *a, const struct Pasien *b);
int compareByJenisPenyakit(const struct Pasien *a, const struct Pasien *b);

void selectionSort(struct Pasien identitas[], int size, int (*compare)(const struct Pasien *, const struct Pasien *));

void appendPeopleToFile(const char *filename, struct Pasien *people, int count);
void readPeopleFromFile(const char *filename, struct Pasien *people, int count);

int binarySearch(const struct Pasien people[], int size, const char key[]);

void hello();

#endif  // FUNCTIONS_H
