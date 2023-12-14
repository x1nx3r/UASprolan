# Functions Documentation

## Struct Pasien

Represents patient data with the following fields:

- `nama` (Name): 50 characters
- `umur` (Age): 4 characters
- `jenisKelamin` (Gender): 24 characters
- `tingkatPenyakit` (Disease Level): 24 characters

## `compareByNama`

```c
int compareByNama(const struct Pasien *a, const struct Pasien *b);
```

Digunakan untuk komparasi berdasarkan nama. Fungsi ini digunakan sebagai argumen terakhir pada fungsi selectionSort dan binarySearch.

- `Pasien *a` : Pointer ke elemen a struct pasien
- `Pasien *b` : Pointer ke elemen b struct pasien

Fungsi ini melakukan compare dua string dengan strcmp() dan memberikan nilai return integer. jika return positif maka string pertama lebih besar daripada string kedua dan sebaliknya.

## `compareByUmur`

```c
int compareByUmur(const struct Pasien *a, const struct Pasien *b);
```

Digunakan untuk komparasi berdasarkan umur. Fungsi ini digunakan sebagai argumen terakhir pada fungsi selectionSort dan binarySearch.

- `Pasien *a` : Pointer ke elemen a struct pasien
- `Pasien *b` : Pointer ke elemen b struct pasien

Fungsi ini melakukan compare dua string dengan strcmp() dan memberikan nilai return integer. jika return positif maka string pertama lebih besar daripada string kedua dan sebaliknya.

## `compareByJenisPenyakit`

```c
int compareByJenisPenyakit(const struct Pasien *a, const struct Pasien *b);
```

Digunakan untuk komparasi berdasarkan Jenis Penyakit. Fungsi ini digunakan sebagai argumen terakhir pada fungsi selectionSort dan binarySearch.

- `Pasien *a` : Pointer ke elemen a struct pasien
- `Pasien *b` : Pointer ke elemen b struct pasien

Fungsi ini melakukan compare dua string dengan strcmp() dan memberikan nilai return integer. jika return positif maka string pertama lebih besar daripada string kedua dan sebaliknya.

## `selectionSort`

```c
void selectionSort(struct Pasien identitas[], int size, int (*compare)(const struct Pasien *, const struct Pasien *));
```

Implementasi sorting dengan metode selection sort

- `identitas[]` : array of struct Pasien yang ingin disorting
- `size` : ukuran array yang disorting
- `*compare` : pointer ke fungsi compare berdasarkan apa (merujuk ke 3 fungsi diatas)

## `appendPeopleToFile`

```c
void appendPeopleToFile(const char *filename, struct Pasien *people, int count);
```

Write array of struct ke file

- `*filename` : nama file yang akan di write
- `*people` : pointer ke array struct Pasien yang ingin di write
- `count` : berapa banyak anggota array yang ingin di write ke file

## `readPeopleFromFile`

```c
void readPeopleFromFile(const char *filename, struct Pasien *people, int count);
```

Read array of struct dari file (Parsing)

- `*filename` : nama file yang akan di read
- `*people` : pointer ke array struct Pasien yang ingin dimasukkan data dari file
- `count` : berapa banyak anggota array dari file yang ingin di read

## `binarySearch`

```c
int binarySearch(const struct Pasien people[], int size, const char key[]);
```

Implementasi searching nama dengan metode binary search

- `identitas[]` : array of struct Pasien yang ingin di search
- `size` : ukuran array yang di search
- `key[]` : kata yang dicari

## `hello`

```c
void hello();
```

Fungsi testing untuk memastikan functions.c dicompile dengan benar.
