# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian Stack
Stack atau dalam Bahasa Indonesia diartikan tumpukan, adalah struktur data linier yang mengikuti prinsip Last In First Out (LIFO). Artinya elemen yang terakhir disisipkan akan menjadi elemen pertama yang keluar.[1]

### Jenis - jenis Stack
1. Register stack
Register stack merupakan stack yang hanya mampu menampung data dalam jumlah yang kecil. Kedalaman maksimum pada register stack cenderung dibatasi karena ukuran unit memorinya sangat kecil dibandingkan dengan memory stack.

2. Memory stack
Pada stack jenis ini, kedalaman dari stack cukup fleksibel dan mampu menangani dalam dalam skala yang lebih besar dibandingkan jenis sebelumnya.[1]

### Fungsi dan Kegunaan Stack
fungsi dan kegunaan struktur data stack adalah sebagai berikut:

- Struktur data stack digunakan dalam evaluasi dan konversi ekspresi aritmatika. Proses ini banyak dipakai untuk program kompiler.
- Stack digunakan dalam pemrograman rekursi.
- Digunakan untuk pemeriksaan tanda kurung.
- Stack digunakan dalam manajemen memori.
- Dipakai untuk memproses pemanggilan sebuah fungsi.[1]

### Operasi pada Stack
Untuk melakukan manipulasi pada tumpukan, ada operasi tertentu :

- push() untuk memasukkan elemen ke dalam tumpukan
- pop() untuk menghapus elemen dari tumpukan
- top() Mengembalikan elemen teratas tumpukan.
- isEmpty() mengembalikan nilai benar jika tumpukan kosong jika tidak salah.
- isFull() mengembalikan nilai benar jika tumpukan penuh, jika tidak maka akan salah.[2]


   
## Guided 

### Guided 1

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull(){
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku (string data) {
    if (isFull ()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak da data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = " ";
        top --;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << "adalah" << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku (int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi dta yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = " ";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout <<  arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " <<isFull() << endl;
    cout << "Apakah data stack kosong? " <<isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "'\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}

```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/3bce94f7-d4c5-47cb-b86a-c08875594b6a)

Program di atas memiliki beberapa fungsi dasar untuk memanipulasi stack, antara lain pushArrayBuku untuk menambahkan elemen ke dalam stack, popArrayBuku untuk menghapus elemen dari stack, peekArrayBuku untuk melihat elemen pada posisi tertentu, countStack untuk menghitung jumlah elemen dalam stack, changeArrayBuku untuk mengubah elemen pada posisi tertentu, dan destroyArrayBuku untuk menghapus semua elemen dalam stack. Program juga memiliki fungsi cetakArrayBuku untuk mencetak semua elemen dalam stack. Pada bagian main(), beberapa operasi dasar stack dilakukan, seperti menambahkan, menghapus, mengubah, dan mencetak elemen dalam stack. Selain itu, program juga menampilkan informasi apakah stack penuh atau kosong.



## Unguided 

### Unguided 1
### Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk menghapus karakter non-alfabet dari kalimat
string hapusKarakterNonAlfabet(string str) {
    string hasil = "";
    for (char c : str) {
        if (isalpha(c)) {
            hasil += tolower(c);
        }
    }
    return hasil;
}

// Fungsi untuk memeriksa apakah sebuah kalimat merupakan palindrom atau tidak
bool Palindrom(string str) {
    stack<char> tumpukanKarakter;
    int panjang = str.length();

    // Menyisipkan setengah karakter pertama ke dalam stack
    for (int i = 0; i < panjang / 2; i++) {
        tumpukanKarakter.push(str[i]);
    }

    // Memeriksa karakter setengah kedua dengan karakter yang disisipkan dalam stack
    for (int i = panjang / 2 + (panjang % 2); i < panjang; i++) {
        if (str[i] != tumpukanKarakter.top()) {
            return false;
        }
        tumpukanKarakter.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Menghapus karakter non-alfabet dari kalimat
    string kalimatBersih = hapusKarakterNonAlfabet(kalimat);

    if (Palindrom(kalimatBersih)) {
        cout << "Kalimat tersebut adalah PALINDROM." << endl;
    } else {
        cout << "Kalimat tersebut BUKAN PALINDROM." << endl;
    }

    return 0;
}

```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6374bcf1-ec63-4556-a2f1-7ec94e8ed835)

Program di atas adalah yang digunakan untuk memeriksa apakah sebuah kalimat merupakan palindrom atau tidak. Sebuah kalimat dikatakan palindrom jika kalimat tersebut dapat dibaca sama baik dari depan maupun dari belakang. Program menggunakan beberapa fungsi, yaitu hapusKarakterNonAlfabet untuk menghapus karakter non-alfabet dari kalimat dan mengubah seluruh karakter menjadi huruf kecil, serta Palindrom untuk memeriksa apakah kalimat yang telah dibersihkan tersebut merupakan palindrom atau tidak. Untuk melakukan pengecekan palindrom, program menggunakan struktur data stack. Pada bagian main(), pengguna diminta untuk memasukkan sebuah kalimat, kemudian kalimat tersebut dibersihkan dari karakter non-alfabet dan diubah menjadi huruf kecil. Selanjutnya, program memeriksa apakah kalimat tersebut merupakan palindrom atau bukan, dan menampilkan hasilnya ke layar.



## Unguided 2
### Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <string>

using namespace std;

string arrayData[50];
int maksimal = 50, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayData(string kalimat) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }
    else {
        arrayData[top] = kalimat;
        top++;
    }
}

void popArrayData() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else {
        arrayData[top - 1] = "";
        top--;
    }
}


void reverseKalimat(string kalimat) {
    for (char &c : kalimat) {
        pushArrayData(string(1, c)); // Memasukkan setiap karakter ke dalam stack
    }

    string reversedString = "";
    while (!isEmpty()) {
        reversedString += arrayData[top - 1]; // Mengambil karakter dari stack untuk membentuk kalimat terbalik
        popArrayData();
    }

    cout << "Hasil\t: " << reversedString << endl;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);

    cout << "Kalimat\t: " << kalimat << endl;
    reverseKalimat(kalimat);

    return 0;
}
```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/9329e0c5-9119-4d7a-8cb5-6c3cf5a17f71)

Program ini menggunakan struktur data stack untuk membalikkan sebuah kalimat yang dimasukkan oleh pengguna. Dengan memanfaatkan array sebagai stack, program menyediakan fungsi `pushArrayData()` untuk memasukkan karakter-karakter kalimat ke dalam stack, `popArrayData()` untuk menghapus karakter teratas dari stack, dan `reverseKalimat()` untuk membalikkan urutan karakter dengan menggunakan stack. Setelah meminta input kalimat dari pengguna, program mencetak kalimat tersebut dan hasil pembalikan kalimatnya.

## Kesimpulan
Dapat disimpulkan bahwa stack merupakan struktur data linier yang mengikuti prinsip Last In First Out (LIFO), di mana elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan. Stack dapat diimplementasikan menggunakan array atau linked list, dan memiliki operasi dasar seperti push, pop, isEmpty, isFull, dan peek. Kegunaan stack sangat luas, mulai dari evaluasi dan konversi ekspresi aritmatika, manajemen memori, hingga pemrograman rekursi. Meskipun memiliki kelebihan seperti manajemen data yang efisien dan kontrol atas memori, stack juga memiliki beberapa kelemahan seperti ukuran memori terbatas dan risiko stack overflow. Oleh karena itu, penggunaan stack harus dipertimbangkan dengan baik sesuai dengan kebutuhan dan karakteristik program yang dibuat.

## Referensi
[1] "Struktur Data Stack : Pengertian, Karakteristik, dan Kegunaan", Trivusi, 2022
     https://www.trivusi.web.id/2022/07/struktur-data-stack.html

[2] "Apa itu tumpukan? tutorial Lengkap", geeksforgeeks, 2024
    https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/



