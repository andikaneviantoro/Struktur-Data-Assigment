# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Searching
Pencarian (searching) merupakan proses yang fundamental dalam pengolahandata. Proses pencarian adalah menemukan nilai (data) tertentu di dalam sekumpulan data yang bertipe sama (baik bertipe dasar atau bertipe bentukan).[1]

### Sequential Search
Sequential Search adalah teknik pencarian data yang cepat. Metode Pencarian Sekuensial membandingkan setiap bagian data satu per satu sampai data ditempatkan dalam kumpulan data yang telah ditetapkan sebelumnya, pada titik mana pencarian dihentikan. Penelitian ini bertujuan untuk mengembangkan sistem informasi yang memanfaatkan sistem yang ada dengan memanfaatkan metode Sequential Search, pemrograman PHP, dan server Mysql. Metode komputerisasi program ini dapat digunakan untuk mengelola atau meningkatkan kinerja staf secara efektif.[2]

### Binary Search
Binary search merupakan salah satualgoritma yang relatif efisien, sehingga membuat algoritma tersebut menjadi algoritma pencarian yang populer dan sering digunakan. Andaikan ingin mencari posisi sebuah nama dari seluruh nama yang ada di dunia yang telah dicatat dan diurutkan, Binary Search dapat menyelesaikannya dengan maksimal sebanyak 35 iterasi. Binary Search memiliki waktu searching yang lebih cepat untuk data yang besar, terbukti dengan metode dan jumlah iterasi yang dilakukan oleh algoritma Binary Search tersebut. Hal ini membuat algoritma Binary Search memiliki kelebihan seperti kecilnya beban komputasi yang digunakan saat menjalankan algoritma pencarian.[3]


## Guided 

### Guided 1

```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    
    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    } 
    
    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    
    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    
    return 0;
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/1161cc7d-0f43-4ece-9c63-d6eb5fe4cd3c)


Program ini menunjukkan cara kerja algoritma Sequential Search untuk mencari nilai tertentu dalam sebuah array. Algoritma ini bekerja dengan cara mengulangi setiap elemen array dan membandingkannya dengan nilai yang dicari. Jika nilai yang dicari ditemukan, program akan berhenti dan menampilkan informasi tentang indeks elemen tersebut.

### Guided 2

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (dataArray[j] < dataArray[min]) {
                min = j;
            }
        } 
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
} 

void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected to 6 to match array bounds
    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari) {
            b_flag = true;
        } else if (dataArray[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if (b_flag) {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    } 
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    cout << "\nData diurutkan: ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    } 
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/298c064b-7563-4780-8326-13ea57676269)


Program ini menunjukkan cara kerja algoritma Binary Search untuk mencari nilai tertentu dalam sebuah array yang telah diurutkan menggunakan algoritma Selection Sort. Algoritma Binary Search lebih efisien daripada algoritma Sequential Search karena hanya membutuhkan waktu rata-rata O(log n) untuk menyelesaikan pencarian, di mana n adalah jumlah elemen dalam array.


## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk mengubah huruf besar menjadi huruf kecil
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Fungsi binary search untuk mencari huruf dalam string
int binarySearch(string kalimat, char cari) {
    int low = 0;
    int high = kalimat.length() - 1;
    
    // Ubah huruf pencarian menjadi huruf kecil jika huruf besar
    cari = toLower(cari);
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        char current = toLower(kalimat[mid]);
        
        if (current == cari) {
            return mid; // Huruf ditemukan
        } else if (current < cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1; // Huruf tidak ditemukan
}

int main() {
    string kalimat;
    char cari;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin Anda cari: ";
    cin >> cari;

    int index = binarySearch(kalimat, cari);

    if (index != -1) {
        cout << "Huruf '" << cari << "' ditemukan pada indeks ke-" << index << endl;
    } else {
        cout << "Huruf '" << cari << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/e0c60a82-bbed-4422-bf74-ac5428ddd61c)


Program ini menunjukkan cara kerja algoritma Binary Search untuk mencari huruf tertentu dalam sebuah kalimat. Algoritma ini lebih efisien daripada algoritma pencarian linier karena hanya membutuhkan waktu rata-rata O(log n) untuk menyelesaikan pencarian, di mana n adalah panjang kalimat.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <cctype> // Untuk fungsi isalpha dan tolower
using namespace std;

// Fungsi untuk mengecek apakah suatu karakter merupakan huruf vokal
bool isVowel(char c) {
    c = tolower(c); // Ubah huruf menjadi huruf kecil untuk mempermudah pengecekan
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVowels(string kalimat) {
    int count = 0;
    for (char c : kalimat) {
        if (isalpha(c) && isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = countVowels(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/c0ded716-1beb-478f-8378-6f80bde23472)


Program ini menunjukkan cara kerja algoritma untuk menghitung jumlah huruf vokal dalam sebuah kalimat. Algoritma ini menggunakan fungsi isVowel() untuk mengecek apakah suatu karakter merupakan huruf vokal dan fungsi countVowels() untuk menghitung jumlah total huruf vokal dalam kalimat.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
using namespace std;

// Fungsi untuk menghitung berapa kali angka 4 muncul dalam array
int countOccurrences(int data[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int occurrences = countOccurrences(data, n, target);

    cout << "Jumlah angka 4 dalam data adalah: " << occurrences << endl;

    return 0;
}
```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/21f19b5e-95bf-4591-8fff-d382fa385e11)


Program ini menunjukkan cara kerja algoritma untuk menghitung berapa kali angka 4 muncul dalam sebuah array. Algoritma ini menggunakan fungsi countOccurrences() yang mengiterasi setiap elemen array dan membandingkannya dengan angka 4. Fungsi ini kemudian mengembalikan nilai yang menunjukkan jumlah kemunculan angka 4 dalam array.


## Kesimpulan
Sequential Search bekerja dengan cara membandingkan setiap elemen data secara berurutan hingga data yang dicari ditemukan. Algoritma ini cocok digunakan untuk data yang tidak terurut atau jumlah datanya kecil.
Binary Search bekerja dengan cara membagi data menjadi dua bagian secara berulang dan mencari data yang dicari di bagian yang sesuai. Algoritma ini lebih efisien daripada Sequential Search untuk data yang sudah terurut dan memiliki banyak elemen.
Pemilihan algoritma searching yang tepat tergantung pada jenis data, urutan data, dan jumlah data. Sequential Search lebih mudah diimplementasikan dan tidak memerlukan data yang terurut, sedangkan Binary Search lebih efisien untuk data yang sudah terurut dan memiliki banyak elemen.
Pemahaman tentang algoritma searching ini penting untuk menyelesaikan masalah pencarian data dengan lebih efisien dan tepat.


## Referensi
[1] Munir, R. "1. Pencarian", Institut Teknologi Bandung, 2023.

[2] Febryanto, A. "Penerapan Algoritma Sequential Search untuk Mencari Data Siswa Pada Sekolah Menengah Kejuruan Negeri 3 Bengkalis", Jurnal Unilac, 2022.

[3] Tobing, F. "ANALISIS PERBANDINGAN PENGGUNAAN METODE BINARY SEARCH
DENGAN REGULAR SEARCH EXPRESSION", Jurnal Manajemen Informatika & Komputerisasi Akutansi, 2020.


