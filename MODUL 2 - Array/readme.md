# <h1 align="center">Laporan Praktikum Modul 2 - Tipe Data</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data
lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. Berikut ini
adalah beberapa jenis array :

1) Array Satu Dimensi
   
Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data
dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap
elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan
untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada
jumlah elemen dikurangi satu.

2) Array Dua Dimensi
   
Array dua dimensi adalah variable yang terdiri dari kumpulan array
satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom.
Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks
baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris,
sementara indeks kolom menunjukkan posisi elemen dalam kolom.

3) Array Multidimensi
   
Array multidimensi memiliki kesamaan dengan array satu dimensi dan
dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini
digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau
array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array
empat dimensi, array lima dimensi, dan seterusnya.

## Guided 

### 1. Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
        }
    }
    cout << endl;
}
// Output Array
for (int x = 0; x < 2; x++)
{
    for (int y = 0; y < 3; y++)
    {
        for (int z = 0; z < 3; z++)
        {
            cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
        }
    }
}
cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

#### Output :
![Screenshot (2869)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d9e8d6d0-b9ca-4f4a-bee7-ee5bec4f5a2d)


Program yang mendemonstrasikan penggunaan array tiga dimensi. Array tiga dimensi tersebut digunakan untuk menyimpan data dalam sebuah struktur kubus, di mana terdapat tiga dimensi: baris, kolom, dan kedalaman. Pada awal program, array arr dengan ukuran 2x3x3 dideklarasikan untuk menampung data. Selanjutnya, program meminta pengguna untuk memasukkan nilai-nilai ke dalam array tersebut dengan menggunakan nested loop. Setelah semua nilai dimasukkan, program kemudian mencetak nilai-nilai tersebut ke layar. Tahap terakhir adalah mencetak tampilan array dalam bentuk kubus, dengan setiap lapisan atau kedalaman array ditampilkan secara terpisah. Program ini berguna untuk memahami konsep dan penggunaan array tiga dimensi dalam pemrograman C++.

### 2. Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan Panjang Array :";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
{


    cout << "Array ke-" << (i) << ": ";
    cin >> array[i];
}
maks = array[0];
for (i = 0; i < a; i++)
{
    if (array[i] > maks)
    {
        maks = array[i];
        lokasi = i;
    }
}
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke" << lokasi << endl;
}
```

#### Output :
![Screenshot (2870)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d992aba8-2e14-4c0e-86d5-cf383cef2491)


Program di atas bertujuan untuk mencari nilai maksimum dari sejumlah bilangan yang dimasukkan pengguna ke dalam sebuah array. Pertama, program akan meminta pengguna untuk memasukkan panjang array dan kemudian meminta pengguna untuk memasukkan angka-angka tersebut satu per satu. Setelah semua angka dimasukkan, program akan mencari nilai maksimum dari array tersebut dengan melakukan iterasi melalui setiap elemen array. Nilai maksimum dan lokasinya dalam array akan ditampilkan sebagai output akhir dari program.


## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> array(n);

    cout << "Masukkan " << n << " angka: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << "Data Array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    cout << "Nomor Genap: ";
    bool genap = false;
    for (int i = 0; i < n; ++i) {
        if (array[i] % 2 == 0) {
            if (genap) cout << ", ";
            cout << array[i];
            genap = true;
        }
    }
    cout << endl;

    cout << "Nomor Ganjil: ";
    bool ganjil = false;
    for (int i = 0; i < n; ++i) {
        if (array[i] % 2 != 0) {
            if (ganjil) cout << ", ";
            cout << array[i];
            ganjil = true;
        }
    }
    cout << endl;

    return 0;
}

```

#### Output:
![Screenshot (2871)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/28c356c4-f8bb-430b-b8b8-589c472ba570)


Program C++ diatas meminta pengguna untuk memasukkan jumlah elemen dalam sebuah array, kemudian meminta pengguna untuk memasukkan nilai-nilai dari elemen-elemen tersebut. Setelah itu, program menampilkan data array yang dimasukkan oleh pengguna, serta memisahkan antara nilai-nilai genap dan ganjil dari array tersebut. Program menggunakan vektor untuk menyimpan data array dinamis dan menggunakan loop untuk memeriksa setiap elemen array apakah genap atau ganjil, kemudian menampilkan hasilnya secara terpisah.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main()
{
    int sizeX, sizeY, sizeZ;

    // Input ukuran array dari pengguna
    cout << "Masukkan ukuran array pertama: " ;
    cin >> sizeX;
    cout << "Masukkan ukuran array kedua: " ;
    cin >> sizeY; 
    cout << "Masukkan ukuran array ketiga: " ;
    cin >> sizeZ;

    // Deklarasi array sesuai dengan input pengguna
    int arr[sizeX][sizeY][sizeZ];

    // Input elemen array
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int z = 0; z < sizeZ; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
    }
    cout << endl;

    // Output elemen array
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int z = 0; z < sizeZ; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int z = 0; z < sizeZ; z++)
            {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot (2872)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/b5e12e9b-494b-42d6-97ab-598fd0f177de)


Program di atas adalah program C++ yang memungkinkan pengguna untuk memasukkan ukuran tiga dimensi dari sebuah array dan kemudian memasukkan elemen-elemen array tersebut. Program ini kemudian mencetak elemen-elemen array tersebut ke layar dalam tiga tahap: pertama, mencetak koordinat dan nilai setiap elemen array dalam format yang terstruktur, kedua, mencetak nilai dari setiap elemen array dalam format yang lebih ringkas, dan ketiga, mencetak nilai array dalam bentuk tampilan matriks tiga dimensi. Program ini memanfaatkan konsep penggunaan array multi-dimensi dalam bahasa pemrograman C++ serta mengilustrasikan penggunaan perulangan bersarang untuk mengakses dan memanipulasi setiap elemen array sesuai dengan dimensi yang telah ditentukan oleh pengguna.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
#include <iomanip> // Untuk menggunakan setprecision
using namespace std;

int main() {
    int n;
    cout << "Masukkan panjang array: ";
    cin >> n;

    // Mengalokasikan memori untuk array
    int *arr = new int[n];

    // Meminta pengguna memasukkan elemen array
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cout << "Angka ke-" << (i+1) << ": ";
        cin >> arr[i];
    }

    int menu_167;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Mencari nilai maksimum\n";
        cout << "2. Mencari nilai minimum\n";
        cout << "3. Mencari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih operasi (1-4): ";
        cin >> menu_167;

        switch (menu_167) {
            case 1: {
                // Mencari nilai maksimum
                int maks = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > maks) {
                        maks = arr[i];
                    }
                }
                cout << "Nilai maksimum: " << maks << endl;
                break;
            }
            case 2: {
                // Mencari nilai minimum
                int min = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                cout << "Nilai minimum: " << min << endl;
                break;
            }
            case 3: {
                // Menghitung nilai rata-rata
                double sum = 0.0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                double rata_rata = sum / n;
                cout << "Nilai rata-rata: " << fixed << setprecision(2) << rata_rata << endl;
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan program ini\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi yaa\n";
        }
    } while (menu_167 != 4);

    // Menghapus memori yang dialokasikan untuk array
    delete[] arr;

    return 0;
}

```

#### Output:
![Screenshot (2871)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/1ff3a227-cd78-437d-94fd-b74a369bf300)


Program di atas adalah sebuah program C++ yang meminta pengguna untuk memasukkan panjang sebuah array, kemudian meminta pengguna untuk memasukkan elemen-elemen array tersebut. Setelah itu, program menampilkan sebuah menu yang memungkinkan pengguna untuk melakukan beberapa operasi pada array yang telah dimasukkan, yaitu mencari nilai maksimum, mencari nilai minimum, mencari nilai rata-rata, atau keluar dari program. 
Setiap operasi diimplementasikan menggunakan switch case di mana untuk mencari nilai maksimum, minimum, dan rata-rata, program melakukan iterasi melalui array sesuai dengan operasi yang dipilih. Setelah pengguna memilih operasi, hasilnya ditampilkan. Program akan terus meminta pengguna memilih operasi hingga mereka memilih untuk keluar. Setelah keluar dari loop, program akan menghapus memori yang dialokasikan untuk array dan kemudian berakhir.


## Kesimpulan
Array adalah struktur data yang digunakan untuk menyimpan sekumpulan elemen dengan tipe data yang sama. Setiap elemen dalam array dapat diakses menggunakan indeks numerik, dan array memungkinkan pengolahan data secara efisien, seperti pengulangan dan pengurutan. Array juga memungkinkan pengelompokan data yang terkait menjadi satu kesatuan, memudahkan pengelolaan dan manipulasi data dalam program. Dengan pemahaman yang baik tentang konsep dan penggunaannya, programmer dapat mengoptimalkan penggunaan array untuk menyelesaikan berbagai macam masalah pemrograman.

## Referensi
[1] Suratna, Agus. "Tutorial C++: #10 Dasar Array pada C++", 2021.

[2] AS, Ravikiran. "Panduan Mudah untuk Memahami Array C++" Penerbit Simplilearn, 2023.

