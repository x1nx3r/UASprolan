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

Compares two patients based on their names.

## `compareByUmur`

```c
int compareByUmur(const struct Pasien *a, const struct Pasien *b);
```

Compares two patients based on their ages.

## `compareByJenisPenyakit`

```c
int compareByJenisPenyakit(const struct Pasien *a, const struct Pasien *b);
```

Compares two patients based on the level of their diseases.

## `selectionSort`

```c
void selectionSort(struct Pasien identitas[], int size, int (*compare)(const struct Pasien *, const struct Pasien *));
```

Sorts an array of patients using the selection sort algorithm. The sorting criteria are defined by the comparison function provided.

## `appendPeopleToFile`

```c
void appendPeopleToFile(const char *filename, struct Pasien *people, int count);
```

Appends an array of patients to a file, formatted with their name, age, gender, and disease level.

## `readPeopleToFile`

```c
void readPeopleFromFile(const char *filename, struct Pasien *people, int count);
```

Reads an array of patients from a file, assuming the file is formatted with name, age, gender, and disease level information.

## `binarySearch`

```c
int binarySearch(const struct Pasien people[], int size, const char key[]);
```

Performs a binary search for a patient in an array based on their name.

## `hello`

```c
void hello();
```

A simple function that prints "Hello World" to the console.
