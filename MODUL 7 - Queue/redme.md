# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian Queue




   
## Guided 

### Guided 1

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[maksimalQueue]; // Antrian teller

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { // Pengecekan antriannya kosong atau tidak
    return back == 0;
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data;
        back++;
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; // Clear the last element
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/37c4d6f1-c92d-4627-ae87-4b2a8191561d)


Program di atas mengimplementasikan antrian (queue) menggunakan array statis dengan ukuran maksimal lima elemen (`maksimalQueue`). Program ini memiliki beberapa fungsi untuk mengelola antrian: `isFull()` mengecek apakah antrian penuh dengan membandingkan variabel `back` dengan `maksimalQueue`; `isEmpty()` mengecek apakah antrian kosong dengan memeriksa apakah `back` bernilai nol; `enqueueAntrian(string data)` menambahkan elemen baru (`data`) ke antrian, menampilkan pesan jika antrian penuh, atau menambahkan elemen pada posisi `back` dan meningkatkan nilai `back`; `dequeueAntrian()` menghapus elemen pertama dari antrian, menampilkan pesan jika antrian kosong, atau menggeser semua elemen satu posisi ke depan dan menurunkan nilai `back`; `countQueue()` mengembalikan jumlah elemen dalam antrian; `clearQueue()` mengosongkan antrian dengan menghapus semua elemen dan mengatur ulang nilai `back` dan `front` ke nol; dan `viewQueue()` menampilkan semua elemen dalam antrian, menunjukkan posisi yang kosong jika ada. Fungsi `main()` menguji fungsi-fungsi ini dengan menambahkan dua elemen ke antrian ("Andi" dan "Maya"), menampilkan antrian, menghitung jumlah elemen, menghapus satu elemen, dan mengosongkan antrian, serta menampilkan kondisi antrian setelah setiap operasi untuk menunjukkan perubahan yang terjadi.


## Unguided 

### Unguided 1
### Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
using namespace std;

// Struktur Node untuk linked list
struct Node {
    string data;
    Node* next;
};

// Queue dengan linked list
struct Queue {
    Node* front;
    Node* back;
    int size;

    Queue() : front(nullptr), back(nullptr), size(0) {}

    bool isFull() {
        return false; // Linked list queue is never full unless memory is exhausted
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (isEmpty()) {
                back = nullptr;
            }
        }
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            current = current->next;
            index++;
        }
        if (index == 1) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/bb73af2a-309d-4ea8-84f5-802e67f93dcb)


Program yang diberikan adalah implementasi struktur data antrian (queue) menggunakan linked list. Dalam struktur ini, setiap elemen dalam antrian direpresentasikan oleh struktur `Node`, yang menyimpan data serta pointer ke elemen berikutnya. Sedangkan struktur `Queue` merepresentasikan antrian secara keseluruhan, dengan pointer ke elemen depan (`front`) dan belakang (`back`) antrian, serta variabel `size` untuk menyimpan jumlah elemen dalam antrian.
Fungsi `enqueueAntrian(string data)` bertanggung jawab menambahkan elemen baru ke belakang antrian. Jika antrian kosong, elemen baru tersebut menjadi elemen depan dan belakang antrian. Jika tidak, elemen baru ditambahkan di belakang dan pointer belakang diubah ke elemen baru. Fungsi `dequeueAntrian()` digunakan untuk menghapus elemen dari depan antrian. Jika antrian kosong, akan ditampilkan pesan bahwa antrian kosong. Jika tidak, elemen depan dihapus dan pointer depan diubah ke elemen berikutnya. Fungsi `countQueue()` mengembalikan jumlah elemen dalam antrian, sementara `clearQueue()` digunakan untuk menghapus semua elemen dalam antrian. Terakhir, fungsi `viewQueue()` menampilkan seluruh elemen dalam antrian.
Dalam fungsi `main()`, program menguji fungsi-fungsi tersebut dengan membuat antrian, menambahkan beberapa elemen ke dalamnya, menghapus beberapa elemen, dan menampilkan jumlah elemen dalam antrian setelah setiap operasi. Dengan demikian, program memberikan pemahaman yang jelas tentang bagaimana struktur data antrian dapat diimplementasikan menggunakan linked list.


## Unguided 2
### Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
using namespace std;

// Struktur Node untuk linked list dengan atribut Nama dan NIM
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Queue dengan linked list
struct Queue {
    Node* front;
    Node* back;
    int size;

    Queue() : front(nullptr), back(nullptr), size(0) {}

    bool isFull() {
        return false; // Linked list queue is never full unless memory is exhausted
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (isEmpty()) {
                back = nullptr;
            }
        }
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            index++;
        }
        if (index == 1) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueueAntrian("Andika", "2311102167");
    queue.enqueueAntrian("Bagnaia", "2311102100");
    queue.enqueueAntrian("Marquez", "2311102193");
    queue.enqueueAntrian("Martins", "2311102135");
    queue.enqueueAntrian("Zarco", "2311102156");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/fcfbd9ad-77ef-4654-9392-ce4d87cbe007)


Program ini implementasi dari struktur data antrian menggunakan linked list. Dalam program tersebut, struktur data antrian direpresentasikan melalui dua komponen utama: `Node`, yang memuat informasi nama dan NIM mahasiswa serta pointer ke node berikutnya, dan `Queue`, yang merepresentasikan antrian secara keseluruhan dengan pointer ke elemen depan (`front`) dan belakang (`back`) serta variabel `size` untuk menyimpan jumlah elemen. Fungsi-fungsi dalam struktur `Queue` seperti `enqueueAntrian`, `dequeueAntrian`, `countQueue`, `clearQueue`, dan `viewQueue` memberikan kemampuan untuk menambah, menghapus, menghitung, membersihkan, serta menampilkan elemen-elemen dalam antrian. Dengan penggunaan fungsi-fungsi tersebut, program mampu mengelola daftar mahasiswa dengan efisien. Dalam `main()`, program menguji fungsionalitasnya dengan menambah, menghapus, dan menampilkan daftar mahasiswa dalam antrian, memberikan pemahaman yang jelas tentang penggunaan struktur data antrian dengan linked list dalam konteks daftar mahasiswa.

## Kesimpulan
Dapat disimpulkan bahwa 

## Referensi
[1] "Struktur Data Stack : Pengertian, Karakteristik, dan Kegunaan", Trivusi, 2022
     https://www.trivusi.web.id/2022/07/struktur-data-stack.html

[2] "Apa itu tumpukan? tutorial Lengkap", geeksforgeeks, 2024
    https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/




