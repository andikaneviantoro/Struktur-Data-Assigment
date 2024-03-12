# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

Tipe data adalah suatu memori atau media pada komputer yang digunakan untuk menampung informasi atau data sementara. Tipe data berfungsi untuk mempresentasikan jenis dari sebuah nilai yang terdapat dalam program. Adapun jenis tipe data dan penjelasannya yang terdapat pada bahasa C++ :

1. Tipe data Primitif
   Tipe data primitif adalah tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel. Dalam C++, terdapat 7 tipe data yang termasuk tipe data primitif, yaitu: int, float, double, boolean, char, void dan wide_character.

2. Tipe data Abstrak
   Tipe Data Abstrak (ADT) adalah tipe (atau kelas) untuk objek yang perilakunya ditentukan oleh sekumpulan nilai dan serangkaian operasi. Definisi ADT hanya menyebutkan operasi apa yang akan dilakukan tetapi tidak menyebutkan bagaimana operasi tersebut akan dilaksanakan. Itu tidak menentukan bagaimana data akan diatur dalam memori dan algoritma apa yang akan digunakan untuk mengimplementasikan operasi. Disebut “abstrak” karena memberikan pandangan yang tidak bergantung pada implementasi.

3. Tipe data Koleksi
   Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Contoh tipe data koleksi
   a). Array
   b). Vector
   c). Map

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>

using namespace std;

int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i,e, +, -, *, /
    cin >> op;
    // it allows user to enter the operands
    cin >> num1 >> num2;
    // switch statement begins
    switch (op)
    {
    // if user center +
    case '+':
        cout << num1 + num2;
        break;
    // if user center -
    case '-':
        cout << num1 - num2;
        break;
    // if user center *
    case '*':
        cout << num1 * num2;
        break;
    // if user center /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +,-,* or /,
    // error message will be display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```

DESKRIPSI PROGRAM

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Name : %s\n", mhs1.name);
    printf("Address : %s\n", mhs1.address);
    printf("Age : %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Name : %s\n", mhs2.name);
    printf("Address : %s\n", mhs2.address);
    printf("Age : %d\n", mhs2.age);
    return 0;
}
```

DESKRIPSI PROGRAM

### 3. Tipe Data Koleksi

```C++
#include <iostream>

using namespace std;

int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // menncetak array
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua :  " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```

DESKRIPSI PROGRAM

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
#include <cmath> // Untuk fungsi sqrt (akar kuadrat)
using namespace std;

// Fungsi untuk menghitung luas balok
float hitungLuasBalok_167(float panjang, float lebar, float tinggi) {
    return 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
}

// Fungsi untuk menghitung luas kubus
float hitungLuasKubus_167(float sisi) {
    return 6 * sisi * sisi;
}

// Fungsi untuk menghitung luas tabung
float hitungLuasTabung_167(float jariJari, float tinggi) {
    return 2 * 3.14 * jariJari * (jariJari + tinggi);
}

// Fungsi untuk menghitung luas kerucut
float hitungLuasKerucut_167(float jariJari, float tinggi) {
    return 3.14 * jariJari * (jariJari + sqrt(tinggi * tinggi + jariJari * jariJari));
}

int main() {
    int pilihan;
    do {
        cout << "=================+++++++++++++=================" << endl;
        cout << "SELAMAT DATANG DI PERHITUNGAN BENTUK RUANG DIKA" << endl;
        cout << "=================+++++++++++++=================" << endl;

        cout << "Pilih bentuk ruang : " << endl;
        cout << "1. balok" << endl;
        cout << "2. kubus" << endl;
        cout << "3. tabung" << endl;
        cout << "4. kerucut" << endl;
        cout << "5. keluar" << endl;
        cout << "Masukkan Pilihan (1-5) :";
        cin >> pilihan;

        if (pilihan == 1) {
            float panjang, lebar, tinggi;
            cout << "Masukkan panjang balok : ";
            cin >> panjang;
            cout << "Masukkan lebar balok :";
            cin >> lebar;
            cout << "Masukkan tinggi balok :";
            cin >> tinggi;
            cout << "Luas balok: " << hitungLuasBalok_167(panjang, lebar, tinggi) << endl;
        } else if (pilihan == 2) {
            float sisi;
            cout << "Masukkan panjang sisi kubus: ";
            cin >> sisi;
            cout << "Luas kubus: " << hitungLuasKubus_167(sisi) << endl;
        } else if (pilihan == 3) {
            float jariJari, tinggi;
            cout << "Masukkan jari-jari tabung : ";
            cin >> jariJari;
            cout << "Masukkan tinggi tabung :";
            cin >> tinggi;
            cout << "Luas tabung: " << hitungLuasTabung_167(jariJari, tinggi) << endl;
        } else if (pilihan == 4) {
            float jariJari, tinggi;
            cout << "Masukkan jari-jari kerucut : ";
            cin >> jariJari;
            cout << "Masuskkan tinggi kerucut :";
            cin >> tinggi;
            cout << "Luas kerucut: " << hitungLuasKerucut_167(jariJari, tinggi) << endl;
        } else if (pilihan != 5) {
            cout << "Pilihan tidak tersedia, Silakan pilih kembali." << endl;
        }
    } while (pilihan != 5);

    cout << "Terimakasih Telah Menggunakan Program Dika Bangun Ruang" << endl;

    return 0;
}
```

#### Output:
![Screenshot (2858)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/19ce02ce-650d-45c3-ad89-fff344fa2ce8)

DESKRIPSI PROGRAMA

Kesimpulan Tipe Data Primitif:<br/>


### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
#include <iostream>
#include <string>
using namespace std;

// Struktur untuk merepresentasikan barang
struct Barang_167 {
    string namaBarang;
    int jumlahBarang;
};

// Kelas untuk manajemen stok barang
class StokBarang_167 {
private:
    Barang_167 *daftarBarang;
    int kapasitasBarang;
    int jumlahBarang;

public:
    // Konstruktor
    StokBarang_167(int size) {
        kapasitasBarang = size;
        daftarBarang = new Barang_167[kapasitasBarang];
        jumlahBarang = 0;
    }

    // Destruktor
    StokBarang_167() {
        delete[] daftarBarang;
    }

    // Menambah barang ke stok
    void tambahBarang_167(string nama, int jumlah) {
        if (jumlahBarang < kapasitasBarang) {
            daftarBarang[jumlahBarang].namaBarang = nama;
            daftarBarang[jumlahBarang].jumlahBarang = jumlah;
            jumlahBarang++;
            cout << "(+) Barang berhasil ditambahkan ke stok" << endl;
        } else {
            cout << "Stok penuh, tidak bisa menambah barang baru." << endl;
        }
    }

    // Menampilkan daftar barang di stok
    void tampilkanStok_167() {
        cout << "===========+++++++++===========" << endl;
        cout << "Daftar stok barang di Toko Dika:" << endl;
        cout << "===========+++++++++===========" << endl;
        for (int i = 0; i < jumlahBarang; i++) {
            cout << i+1 << ". " << daftarBarang[i].namaBarang << " : " << daftarBarang[i].jumlahBarang << " box" << endl;
        }
    }
};

int main() {
    // Membuat objek dari kelas StokBarang dengan kapasitas stok 5 barang
    StokBarang_167 stok(5);

    // Menambahkan barang ke stok
    stok.tambahBarang_167("Buku", 25);
    stok.tambahBarang_167("Pensil", 20);
    stok.tambahBarang_167("Penghapus", 15);
    stok.tambahBarang_167("Penggaris", 12);
    stok.tambahBarang_167("Pulpen", 10);

    // Menampilkan daftar barang di stok
    stok.tampilkanStok_167();

    return 0;
}
```
#### Output:
![Screenshot (2859)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/a0f12e8a-eacf-466e-a7f1-2e86a406f332)

DESKRIPSI PROGRAM

A. Fungsi dari Class<br/>
Class adalah salah satu dari konsep OOP yang digunakan untuk membungkus data abstraksi procedural sebagai deskripsi tergeneralisir atau rancangan dari sebuah object untuk mendefinisikan atau menggambarkan isi dan tingkah laku sebagai entitas dari object. Fitur class adalah fitur Object Oriented Program pada bahasa C++.

B. Fungsi dari Struct<br/>
Data struktur, atau Struct dalam pemrograman C++, adalah sekumpulan data yang dikelompokkan ke dalam sebuah “tabel” yang memiliki elemen-elemenyang saling terkait.Struct digunakan apabila data yang ingin dikelompokkan memiliki tipe data yang berbeda atau membuat struktur dari suatu record.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Fungsi untuk melakukan translasi kata
string translateKata_Dika167(const map<string, string>& kamus_167, const string& kata_167) {
    auto iter = kamus_167.find(kata_167);
    if (iter != kamus_167.end()) {
        return iter->second; // Mengembalikan kata terjemahan jika ditemukan
    } else {
        return "Kata tidak ditemukan"; // Mengembalikan pesan jika kata tidak ditemukan
    }
}

int main() {
    // Mendefinisikan map untuk menyimpan kamus Indonesia-Inggris
    map<string, string> kamus_167 = {
        {"halo", "hello"},
        {"aku", "I"},
        {"cinta", "love"},
        {"kamu", "you"},
        {"belajar", "learn"},
        {"makan", "eat"},
        {"minum", "drink"},
        {"rumah", "house"},
        {"mobil", "car"},
        {"kucing", "cat"},
        {"anjing", "dog"},
        {"burung", "bird"},
        {"buku", "book"},
        {"pensil", "pencil"},
        {"komputer", "computer"},
        {"sekolah", "school"},
        {"meja", "table"},
        {"kursi", "chair"},
        {"televisi", "television"},
        {"musik", "music"},
        {"senang", "happy"},
        {"sedih", "sad"},
        {"dia", "he/she"},
        {"kita", "we"},
        {"mereka", "they"},
        {"sekolah", "school"},
        {"rumah", "house"},
        {"burung", "bird"},
        {"mobil", "car"},
        {"motor", "motorcycle"},
        {"buku", "book"},
        {"pensil", "pencil"},
        {"komputer", "computer"},
        {"meja", "table"},
        {"kursi", "chair"},
        {"televisi", "television"},
        {"handphone", "cellphone"},
        {"buah", "fruit"},
        {"sayur", "vegetable"},
        {"air", "water"},
        {"api", "fire"},
        {"angin", "wind"},
        {"matahari", "sun"},
        {"bulan", "moon"},
        {"bintang", "star"},
        {"pohon", "tree"},
        {"hewan", "animal"},
        {"laut", "sea"},
        {"gunung", "mountain"},
        {"danau", "lake"},
        {"sungai", "river"},
        {"jalan", "road"},
        {"kota", "city"},
        {"desa", "village"},
        {"negara", "country"},
        {"selamat", "congratulations"},
        {"terima kasih", "thank you"},
        {"tolong", "please"},
        {"maaf", "sorry"},
        {"pergi", "go"},
        {"datang", "come"},
        {"makan", "eat"},
        {"minum", "drink"},
        {"berjalan", "walk"},
        {"berlari", "run"},
        {"tidur", "sleep"},
        // Tambahkan kata-kata lain di sini sesuai kebutuhan
    };

    // Meminta input dari pengguna
    string kata_167;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "TRANSLATE KATA INDONESIA - INGGRIS" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Masukkan kata (bahasa Indonesia): ";
    cin >> kata_167;

    // Menerjemahkan kata
    string terjemahan = translateKata_Dika167(kamus_167, kata_167);

    // Menampilkan hasil translasi
    cout << "Terjemahan dalam bahasa inggris: " << terjemahan << endl;

    return 0;
}
```

#### Output:
![Screenshot (2860)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6f97d39a-fa03-47de-b778-2460dc3d68eb)

DESKRIPSI PROGRAM

Perbedaan Array dengan Map
1. Indeks
    - Array harus bilangan bulat non-negatif & mulai berurutan dari 0
    - Map dapat berupa nilai berapa pun & tidak harus berurutan
2. Ukuran
    - Array harus dideklarasikan dengan ukuran yang tetap
    - Map dapat dideklarasikan dengan ukuran yang dinamis
3. Tipe Data
    - Array hanya dapat menggunakan tipe data primitif
    - Map dapat menggunakan tipe data apapun
4. Penggunaan
    - Array digunakan untuk menyimpan data yang berurutan
    - Map digunakan untuk menyimpan data yang tidak berurutan dan perlu diakses berdasarkan key


## Kesimpulan


## Referensi

