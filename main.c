#include <stdio.h>
#include "functions.c"
#include "menu.c"
#include <string.h>

int main(){
    int arraySize = 90;
    struct Pasien people[arraySize];
    const char *filename = "people.txt";
    int numberOfLines = countLines(filename);

    initializePeople(people, 90); // mengisi array people dengan data kosong agar bisa diindex
    readPeopleFromFile(filename, people, numberOfLines); // melakukan parsing terhadap people.txt
    
    int choice;
    while(1==1){
        numberOfLines = countLines(filename);
        main_menu();
        printf("Masukkan pilihan anda :");
        scanf("%d", &choice);
        printf("\n");
        switch (choice){
        case 1: // menambahkan data
            addPasien(people, 90, &numberOfLines);
            appendPeopleToFile(filename, people, numberOfLines - 1, 1);  // Append only the last added element
            break;
        case 2:
            for (int i=1; i<numberOfLines;i++){
                printf("%d. Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", i, people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);
            }
            break;
        case 3:
            selectionSort(people, numberOfLines, compareByNama);
            for (int i=1; i<numberOfLines;i++){
                printf("%d. Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", i, people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);
            }
            break;
        case 4:
            selectionSort(people, numberOfLines, compareByUmur);
            for (int i=1; i<numberOfLines;i++){
                printf("%d. Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", i, people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);
            }
            break;
        case 5:
            char query[50];
            printf("Masukkan nama dari pasien yang ingin dicari :");
            scanf(" %[^\n]", query);
            int result = binarySearch(people, numberOfLines, query);
            if (result>=0){
                printf("Data pasien ditemukan di index ke : %d\n", result);
                printf("Dengan rincian data lengkap pasien :\n");
                printf("Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", people[result].nama, people[result].umur, people[result].jenisKelamin, people[result].tingkatPenyakit);
            } else {
                printf("Data tidak ditemukan\n");
            }
            break;
        default:
            break;
        }
    }
    return 0;}