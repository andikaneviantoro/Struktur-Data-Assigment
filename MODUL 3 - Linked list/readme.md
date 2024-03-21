# <h1 align="center">Laporan Praktikum Modul 3 - Linked list</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

Linked list adalah strukur data linier berbentuk rantai simpul di mana setiap simpul menyimpan 2 item, yaitu nilai data dan pointer ke simpul elemen berikutnya. Berbeda dengan array, elemen linked list tidak ditempatkan dalam alamat memori yang berdekatan melainkan elemen ditautkan menggunakan pointer. Simpul pertama dari linked list disebut sebagai head atau simpul kepala. Apabila linked list berisi elemen kosong, maka nilai pointer dari head menunjuk ke NULL. Begitu juga untuk pointer berikutnya dari simpul terakhir atau simpul ekor akan menunjuk ke NULL.

1. Single Linked List
   single Linked list adalah linked list unidirectional. Jadi, kita hanya dapat melintasinya dalam satu arah, yaitu dari simpul kepala ke simpul ekor. Dalam       
   operasi Single Linked List, umumnya dilakukan operasi penambahan dan penghapusan simpul pada awal atau akhir daftar, serta pencarian dan pengambilan nilai pada    simpul tertentu dalam daftar. Karena struktur data ini hanya memerlukan satu pointer untuk setiap simpul, maka Single Linked List umumnya lebih efisien dalam      penggunaan memori dibandingkan dengan jenis Linked List lainnya, seperti Double Linked List dan Circular Linked List. Single linked list yang kedua adalah         circular linked list. Perbedaan circular linked list dan non circular linked adalah penunjuk next pada node terakhir pada circular linked list akan selalu         merujuk ke node pertama.

2. Double Linked list
   Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu     pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev, Double Linked List memungkinkan untuk melakukan operasi penghapusan dan penambahan    pada simpul mana saja secara efisien. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer 
   next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya.

   
## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

#### Output :
![Screenshot (2875)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/5076a5d0-08ab-43ad-ae08-e848c7c82507)


Program di atas adalah implementasi dari sebuah single linked list. Program ini terdiri dari beberapa fungsi dasar yang mencakup operasi-operasi seperti penambahan elemen di depan, di belakang, di tengah, penghapusan elemen di depan, di belakang, di tengah, serta pengubahan nilai elemen di depan, di belakang, dan di tengah. Selain itu, terdapat juga fungsi untuk menghitung jumlah elemen dalam list dan untuk membersihkan seluruh isi list.
Fungsi utama main() digunakan untuk menguji fungsi-fungsi yang telah dibuat dengan contoh penggunaan operasi-operasi dasar pada linked list, seperti penambahan, penghapusan, dan pengubahan elemen, serta menampilkan isi linked list setiap kali setelah dilakukan operasi tersebut.

### 2. Double Linked List

```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

#### Output :
![Screenshot (2876)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/ff73c813-a5b0-4cd3-b367-71174ff0c3f6)


Program di atas adalah implementasi double linked list. Kelas Node mendefinisikan struktur simpul dengan tiga anggota: data, prev, dan next. Kelas DoublyLinkedList menyediakan fungsi-fungsi dasar seperti penambahan data ke depan, penghapusan data dari depan, pengubahan data, penghapusan seluruh isi, dan penampilan isi linked list.
Program juga menyediakan antarmuka pengguna melalui fungsi main(), dimana pengguna dapat memilih operasi yang ingin dilakukan seperti penambahan, penghapusan, pengubahan, membersihkan, atau menampilkan isi linked list.


## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
####    a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
####    b. Hapus data Akechi
####    c. Tambahkan data berikut diantara John dan Jane : Futaba 18
####    d. Tambahkan data berikut diawal : Igor 20
####    e. Ubah data Michael menjadi : Reyn 18
####    f. Tampilkan seluruh data

```C++
#include <iostream>
#include <string>

using namespace std;

// Struktur Node
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Kelas Linked List
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menyisipkan data di akhir daftar
    void sisipkan(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Fungsi untuk menampilkan semua data dalam daftar
    void tampilkan() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void hapusNode(string nama) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Jika node head sendiri menyimpan nama yang akan dihapus
        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }

        // Mencari node yang akan dihapus
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }

        // Jika nama tidak ada dalam daftar
        if (temp == nullptr) {
            return;
        }

        // Memutuskan hubungan node dari linked list
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk menyisipkan node setelah node tertentu
    void sisipkanSetelah(string namaSebelum, string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelum) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << namaSebelum << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menyisipkan node di awal daftar
    void sisipkanDiAwal(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk mengubah data berdasarkan nama
    void ubah(string nama, string namaBaru, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << nama << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        temp->nama = namaBaru;
        temp->usia = usiaBaru;
    }
};

int main() {
    LinkedList daftar;

    // Memasukkan data
    daftar.sisipkan("Andika", 17);
    daftar.sisipkan("John", 19);
    daftar.sisipkan("Jane", 20);
    daftar.sisipkan("Michael", 18);
    daftar.sisipkan("Yusuke", 19);
    daftar.sisipkan("Akechi", 20);
    daftar.sisipkan("Hoshino", 18);
    daftar.sisipkan("Karin", 18);

    char pilihan;
    string nama, namaBaru;
    int usia, usiaBaru;

    do {
        cout << "Menu:" << endl;
        cout << "a. Tampilkan semua data" << endl;
        cout << "b. Hapus data Akechi" << endl;
        cout << "c. Tambahkan data di antara John dan Jane" << endl;
        cout << "d. Tambahkan data di awal" << endl;
        cout << "e. Ubah data Michael" << endl;
        cout << "f. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 'a':
                cout << "Data mahasiswa:" << endl;
                daftar.tampilkan();
                break;
            case 'b':
                daftar.hapusNode("Akechi");
                cout << "Data Akechi telah dihapus." << endl;
                break;
            case 'c':
                cout << "Masukkan nama dan usia yang ingin ditambahkan (Contoh: Futaba 18): ";
                cin >> nama >> usia;
                daftar.sisipkanSetelah("John", nama, usia);
                break;
            case 'd':
                cout << "Masukkan nama dan usia yang ingin ditambahkan di awal (Contoh: Igor 20): ";
                cin >> nama >> usia;
                daftar.sisipkanDiAwal(nama, usia);
                break;
            case 'e':
                cout << "Masukkan nama dan usia baru untuk Michael (Contoh: Reyn 18): ";
                cin >> namaBaru >> usiaBaru;
                daftar.ubah("Michael", namaBaru, usiaBaru);
                break;
            case 'f':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        // Menampilkan data setelah setiap operasi
        cout << "Data mahasiswa:" << endl;
        daftar.tampilkan();
        cout << endl;

    } while (pilihan != 'f');

    return 0;
}
```

#### Output:
a. ![Screenshot (2877)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/31e6c386-2c84-4228-aafb-3756d916713c)

b. ![Screenshot (2878)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/5f46cc90-74f9-4154-8472-32743d68ae0e)

c. ![Screenshot (2879)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/59557b89-9d00-4aee-95b1-e8460325048e)

d. ![Screenshot (2880)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/181c4bb4-4f1d-4a05-97d0-eba2093a73a0)

e. ![Screenshot (2881)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/b1ec0907-5351-464d-9651-f570460572cf)

f. ![Screenshot (2882)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/e3013f3a-645c-4eed-94c4-d3d31f24272b)


Program ini memungkinkan pengguna untuk melakukan beberapa operasi, termasuk menambahkan, menghapus, dan mengubah data mahasiswa, serta menampilkan seluruh data yang telah dimasukkan.
Implementasi dilakukan melalui kelas LinkedList, yang menyediakan fungsi-fungsi dasar untuk operasi-operasi pada linked list seperti menyisipkan data di akhir daftar, menampilkan semua data, menghapus data berdasarkan nama, menyisipkan data setelah node tertentu, menyisipkan data di awal daftar, dan mengubah data berdasarkan nama.
Fungsi main() berfungsi sebagai antarmuka pengguna, dimana pengguna dapat memilih opsi dari menu yang disediakan untuk melakukan operasi tertentu seperti menampilkan data, menghapus data, menambahkan data di antara node tertentu, menambahkan data di awal daftar, mengubah data, atau keluar dari program. Setelah setiap operasi, program akan menampilkan data mahasiswa yang telah dikelola.


### 2. Soal mengenai Double Linked List Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
### Nama Produk Harga
### Originote 60.000
### Somethinc 150.000
### Skintific 100.000
### Wardah 50.000
### Hanasui 30.000

### Case:
### 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
### 2. Hapus produk wardah
### 3. Update produk Hanasui menjadi Cleora dengan harga 55.000
### 4. Tampilkan menu seperti dibawah ini

### Toko Skincare Purwokerto
### 1. Tambah Data
### 2. Hapus Data
### 3. Update Data
### 4. Tambah Data Urutan Tertentu
### 5. Hapus Data Urutan Tertentu
### 6. Hapus Seluruh Data
### 7. Tampilkan Data
### 8. Exit
### Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

### Nama Produk Harga
### Originote 60.000
### Somethinc 150.000
### Azarine 65.000
### Skintific 100.000
### Cleora 55.000

```C++
#include <iostream>
using namespace std;

struct Node {
    string namaProduk;
    double harga;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void tambahData(string nama, double harga) {
        Node* newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current == head && current == tail) {
                    head = tail = NULL;
                } else if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void updateData(string nama, string newName, double newHarga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                current->namaProduk = newName;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void tambahDataUrutanTertentu(string nama, double harga, string setelah) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == setelah) {
                Node* newNode = new Node;
                newNode->namaProduk = nama;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk setelahnya tidak ditemukan!" << endl;
    }

    void hapusDataUrutanTertentu(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void hapusSeluruhData() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
    }

    void tampilkanData() {
        Node* current = head;
        cout << "----------------------" << endl;
        cout << "Nama Produk  ||\t Harga " << endl;
        cout << "----------------------" << endl;
        while (current != NULL) {
            cout << current->namaProduk << "\t" << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList daftarProduk;
    daftarProduk.tambahData("Originote", 60000);
    daftarProduk.tambahData("Somethinc", 150000);
    daftarProduk.tambahData("Skintific", 100000);
    daftarProduk.tambahData("Wardah   ", 50000);
    daftarProduk.tambahData("Hanasui  ", 30000);

    int pilihan;
    string nama, newName, setelah;
    double harga, newHarga;

    do {
        cout << "--------------------------------" << endl;
        cout << " || Toko Skincare Purwokerto || " << endl;
        cout << "--------------------------------" << endl;

        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                daftarProduk.tambahData(nama, harga);
                daftarProduk.tampilkanData();
                break;
            case 2:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                daftarProduk.hapusData(nama);
                daftarProduk.tampilkanData();
                break;
            case 3:
                cout << "Nama Produk yang akan diupdate: ";
                cin >> nama;
                cout << "Nama Baru: ";
                cin >> newName;
                cout << "Harga Baru: ";
                cin >> newHarga;
                daftarProduk.updateData(nama, newName, newHarga);
                daftarProduk.tampilkanData();
                break;
            case 4:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                cout << "Setelah Produk: ";
                cin >> setelah;
                daftarProduk.tambahDataUrutanTertentu(nama, harga, setelah);
                daftarProduk.tampilkanData();
                break;
            case 5:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                daftarProduk.hapusDataUrutanTertentu(nama);
                daftarProduk.tampilkanData();
                break;
            case 6:
                daftarProduk.hapusSeluruhData();
                cout << "Seluruh data telah dihapus." << endl;
                break;
            case 7:
                daftarProduk.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}
```
#### Output:

##### Tampilan Awal:
![Screenshot (2883)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/11b666b9-efc8-4f86-8f4f-f05547b74504)

##### 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific:
![Screenshot (2884)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/ff83c036-c54e-4a96-8bd1-28f9fe178e47)

##### 2. Hapus produk wardah:
![Screenshot (2885)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6ca7b8ae-158f-4c54-ad70-6479e915b724)

##### 3, Update produk Hanasui menjadi Cleora dengan harga 55.000
![Screenshot (2886)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/12f63963-5767-4e45-a11d-8b256b9fa60e)

##### 4. Tampilan Akhir Menu
![Screenshot (2887)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/982b7355-9d56-4da5-bf43-65d5ab29c6e8)


Program C++ di atas adalah aplikasi manajemen data produk yang menggunakan struktur data linked list. Program ini memungkinkan pengguna untuk menambah, menghapus, mengupdate, serta menampilkan data produk. Pengguna dapat memilih operasi yang diinginkan melalui menu yang disediakan. Setiap operasi yang dilakukan akan segera memperbarui tampilan data produk. Program akan berjalan hingga pengguna memilih untuk keluar.


## Kesimpulan
Metode linked list pada adalah sebuah teknik yang efektif untuk menyimpan dan mengelola data secara dinamis. Dengan menggunakan linked list, kita dapat dengan mudah menambah, menghapus, mengupdate, serta mengakses data tanpa perlu memori statis yang telah dialokasikan sebelumnya. Kelebihan utama dari penggunaan linked list adalah kemampuannya untuk menangani data dengan ukuran yang tidak pasti atau berubah-ubah, serta memungkinkan penyisipan atau penghapusan elemen dengan cepat. Namun, penggunaan linked list juga memiliki beberapa kelemahan, seperti penggunaan memori yang lebih besar untuk menyimpan pointer tambahan dan kompleksitas akses elemen yang tidak secepat array. Meskipun demikian, linked list tetap menjadi pilihan yang populer dalam implementasi struktur data dinamis di C++ karena fleksibilitas dan kemampuannya dalam menangani situasi di mana jumlah elemen tidak diketahui secara pasti.

## Referensi
[1] "Struktur Data Linked List : Pengertian, Karakteristik, dan Jenis - jenisnya" Trivusi, 2022.

[2] Ulum, M. Bahrul. "Modul Struktur Data - Linked List" Universitas Esa Unggu, 2018.
