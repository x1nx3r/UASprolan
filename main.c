#include <stdio.h>
#include "functions.c"
#include <stdlib.h>
#include "menu.c"
#include <string.h>

int main(){
    int arraySize = 90; // size array yang digunakan untuk menyimpan data pasien
    struct Pasien people[arraySize]; // inisialisasi array of struct pasien
    const char *filename = "people.txt"; // pointer ke nama file yang digunakan untuk menyimpan array nantinya
    int numberOfLines = countLines(filename); // jumlah baris yang ada di file

    initializePeople(people, 90); // mengisi array people dengan data kosong agar bisa diindex
    readPeopleFromFile(filename, people, numberOfLines); // melakukan parsing terhadap people.txt
    
    int choice; // choice digunakan untuk menentukan pilihan menu
    while(1==1){ // loop while agar program berjalan dalam loop
        numberOfLines = countLines(filename);
        main_menu(); // fungsi display main menu
        printf("Masukkan pilihan anda :");
        scanf("%d", &choice);
        printf("\n");
        switch (choice){ // switch case statement untuk meng handle pilihan menu
        case 1: // menambahkan data
            addPasien(people, 90, &numberOfLines);
            appendPeopleToFile(filename, people, numberOfLines - 1, 1);  // write ke file hanya data yang ditambahkan
            break;
        case 2:
            for (int i=1; i<numberOfLines;i++){
                printf("%d. Nama: %s, Umur: %s, Jenis Kelamin: %s, Tingkat Penyakit: %s\n", i, people[i].nama, people[i].umur, people[i].jenisKelamin, people[i].tingkatPenyakit);
            } // iterasi print semua anggota array people
            break;
        case 3:
            selectionSort(people, numberOfLines, compareByNama); // sorting dengan 
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
            printf("Berikan pilihan sesuai nilai menu");
            break;
        }
    }
    return 0;}