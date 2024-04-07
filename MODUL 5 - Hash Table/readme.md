# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Hash Table

Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengelola data dengan cepat dan efisien. Ini beroperasi dengan prinsip kunci-nilai, di mana setiap elemen data memiliki kunci yang unik yang digunakan untuk mengakses atau memanipulasinya. Hash Table (Tabel Hash) adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Ini menggunakan fungsi hash untuk mengonversi kunci menjadi indeks dalam array. Dengan cara ini, akses ke data menjadi sangat cepat karena kita dapat langsung menghitung indeks tempat data disimpan. Ini cocok untuk pencarian, penyisipan, penghapusan, dan pembaruan data dalam waktu konstan, asalkan tidak ada konflik dalam fungsi hash (collision).

### Kegunaan Struktur Data Hash Table 

- Pencarian Cepat: Dapat digunakan untuk mencari data dengan cepat berdasarkan key. Ini sangat berguna dalam aplikasi seperti basis data, kamus, dan cache.
- Penyimpanan Data: Hash table dapat digunakan untuk menyimpan data dengan efisien. Data dapat diambil dan dimasukkan ke dalam tabel dengan waktu konstan, 
  asalkan tidak ada collision yang signifikan.
- Implementasi Struktur Data Lain: Hash table dapat digunakan untuk mengimplementasikan struktur data lain, seperti set dan map.

### Operasi dalam Struktur Data Hash Table

- Pencarian (Search)
- Penyisipan (Insertion)
- Penghapusan (Deletion)
- Update
- Collision Handling
- Resize
- Iterasi

### Cara kerja Struktur Data Hash Table

1. *Inisialisasi*,
Hash Table awalnya dibuat dengan ukuran tertentu, yang biasanya merupakan bilangan prima. Ukuran ini dapat disesuaikan sesuai kebutuhan.

2. *Fungsi Hash*,
Hash Table menggunakan fungsi hash untuk memetakan nilai yang diberikan dengan kunci tertentu ke indeks dalam array. Fungsi hash ini harus menghasilkan nilai yang unik untuk setiap kunci yang berbeda, sehingga elemen-elemen dapat disimpan dengan benar.

3. *Pemetaan Nilai*,
Ketika sebuah elemen baru ditambahkan ke Hash Table, fungsi hash digunakan untuk menentukan indeks tempat elemen tersebut akan disimpan dalam array. Ini memungkinkan akses cepat ke elemen berdasarkan kunci.

4. *Penanganan Bentrokan*,
Dalam beberapa kasus, dua kunci yang berbeda dapat menghasilkan nilai hash yang sama. Ini disebut bentrokan. Hash Table harus memiliki mekanisme untuk menangani bentrokan ini. Beberapa metode yang umum digunakan adalah chaining (menggunakan linked list untuk menyimpan elemen dengan nilai hash yang sama) dan linear probing (mencari slot kosong berikutnya dalam array jika terjadi bentrokan).

5. *Operasi Utama*,
Operasi utama yang digunakan dalam Hash Table adalah pencarian (untuk mencari elemen berdasarkan kunci), penambahan (untuk menambahkan elemen baru), dan penghapusan (untuk menghapus elemen). Fungsi hash digunakan dalam operasi ini untuk menentukan indeks elemen yang akan diakses atau dimodifikasi.

6. *Efisiensi*,
Efisiensi Hash Table tergantung pada efisiensi fungsi hash yang digunakan. Fungsi hash yang baik harus menghasilkan distribusi nilai hash yang merata untuk menghindari bentrokan yang berlebihan.


   
## Guided 

### Guided 1

```C++
#include <iostream>;+

using namespace std;

const int MAX_SIZE = 10;

// fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// class hash table
class HashTable
{
private:
    Node **table;

public:
    // konstruktor
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }

    // destruktor
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];

            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] table;
    }

    // insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }

            current = current->next;
        }

        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }

            current = current->next;
        }

        return -1;
    }

    // deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    // traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];

            while (current != nullptr)
            {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    return 0;
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/cf12215c-1b95-42ec-9211-763029dac6f4)


Program diatas 


### Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode
{
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Hash function
    int hashFunc(string key)
    {
        int hash_val = 0;

        for (char c : key)
        {
            hash_val += c;
        }

        return hash_val % TABLE_SIZE;
    }

    // Insertion
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }

        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Deletion
    void remove(string name)
    {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Searching
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }

        return "";
    }

    // Transversing
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";

            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;

    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/3a2999a3-9636-414a-8727-4cdc5cdb79ff)


Program ini 


## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
### a. Setiap mahasiswa memiliki NIM dan nilai.
### b. Program memiliki tampilan pilihan menu berisi poin C.
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class LinkedListCircular {
private:
    Mahasiswa* head;

public:
    LinkedListCircular() {
        head = nullptr;
    }

    // Menambahkan mahasiswa di depan
    void tambahDepan(string nama, string nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nama = nama;
        newMahasiswa->nim = nim;

        if (head == nullptr) {
            head = newMahasiswa;
            newMahasiswa->next = head;
        } else {
            Mahasiswa* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newMahasiswa->next = head;
            last->next = newMahasiswa;
            head = newMahasiswa;
        }
        cout << "Mahasiswa berhasil ditambahkan di depan." << endl;
    }

    // Menambahkan mahasiswa di belakang
    void tambahBelakang(string nama, string nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nama = nama;
        newMahasiswa->nim = nim;

        if (head == nullptr) {
            head = newMahasiswa;
            newMahasiswa->next = head;
        } else {
            Mahasiswa* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newMahasiswa;
            newMahasiswa->next = head;
        }
        cout << "Mahasiswa berhasil ditambahkan di belakang." << endl;
    }

    // Menambahkan mahasiswa di tengah
    void tambahTengah(string nama, string nim, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nama = nama;
        newMahasiswa->nim = nim;

        if (head == nullptr) {
            head = newMahasiswa;
            newMahasiswa->next = head;
            cout << "Mahasiswa berhasil ditambahkan di tengah." << endl;
            return;
        }

        Mahasiswa* temp = head;
        int count = 1;
        while (count < posisi - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count < posisi - 1) {
            cout << "Posisi terlalu besar." << endl;
            return;
        }

        newMahasiswa->next = temp->next;
        temp->next = newMahasiswa;
        cout << "Mahasiswa berhasil ditambahkan di tengah." << endl;
    }

    // Ubah data mahasiswa di depan
    void ubahDepan(string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        head->nama = nama;
        head->nim = nim;
        cout << "Data mahasiswa di depan berhasil diubah." << endl;
    }

    // Ubah data mahasiswa di belakang
    void ubahBelakang(string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data mahasiswa di belakang berhasil diubah." << endl;
    }

    // Ubah data mahasiswa di tengah
    void ubahTengah(string nama, string nim, int posisi) {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        Mahasiswa* temp = head;
        int count = 1;
        while (count < posisi && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count != posisi) {
            cout << "Posisi terlalu besar." << endl;
            return;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data mahasiswa di posisi " << posisi << " berhasil diubah." << endl;
    }

    // Hapus data mahasiswa di depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Mahasiswa* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Mahasiswa* del = head;
            head = head->next;
            temp->next = head;
            delete del;
        }
        cout << "Data mahasiswa di depan berhasil dihapus." << endl;
    }

    // Hapus data mahasiswa di belakang
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Mahasiswa* temp = head;
            Mahasiswa* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "Data mahasiswa di belakang berhasil dihapus." << endl;
    }

    // Hapus data mahasiswa di tengah
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }
        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;
        int count = 1;
        while (count < posisi && temp->next != head) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count != posisi) {
            cout << "Posisi terlalu besar." << endl;
            return;
        }
        if (temp == head) {
            hapusDepan();
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Data mahasiswa di posisi " << posisi << " berhasil dihapus." << endl;
    }

    // Hapus semua data mahasiswa
    void hapusList() {
        if (head == nullptr) {
            cout << "Linked List Kosong" << endl;
            return;
        }
        Mahasiswa* current = head;
        Mahasiswa* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
        cout << "Semua data mahasiswa berhasil dihapus." << endl;
    }

    // Menampilkan daftar mahasiswa
    void tampilkan() {
        if (head == nullptr) {
            cout << "Linked List Kosong." << endl;
            return;
        }
        Mahasiswa* temp = head;
        do {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    LinkedListCircular list;
    int choice;
    string nama, nim;
    int posisi;

    do {
        cout << "------------------------------";
        cout << "\nLIST DATA DAN NIM MAHASISWA\n";
        cout << "------------------------------\n";
        cout << "Menu :\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih Operasi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                list.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                list.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                list.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                list.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                list.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                list.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                list.hapusDepan();
                break;
            case 8:
                list.hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                list.hapusTengah(posisi);
                break;
            case 10:
                list.hapusList();
                break;
            case 11:
                list.tampilkan();
                break;
            case 0:
                cout << "Terima kasih:)" << endl;
                break;
            default:
                cout << "Maaf, pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
```

#### Output:

#### Tampilan Awal
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6d3b92b9-bb7b-4fde-8322-e17139096249)

#### Tampilan Operasi Tambah
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/dfe4b3ab-dd19-408e-afbc-b9a58bc0ac2c)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/a4f479de-873a-4ab5-a542-d6c3cb70ee74)

#### Tampilan Operasi Hapus
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/5d40645e-e289-4775-b2ef-bf376bc4551d)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/f0ab0956-3108-444e-926d-893633a7af85)


#### Tampilan Operasi Ubah
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/1d2b3cfe-58d2-488a-b9db-56f57bfdf89e)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6ef5c896-d475-4977-887c-02732c443ae2)

#### Tampilan Operasi Tampil Data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/fa1d5a11-ab37-419c-8702-9264b42c07f8)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/f41344b7-715a-48ea-9fce-2154944b2f32)

### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/e1ba13bd-807c-48a2-8c67-2d04d2e89b60)

#### b) Hapus data Denis
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/fc7c07e9-672b-43b3-87d4-f0029cf80fc2)

#### c) Tambahkan data berikut di awal: Owi 2330000
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/9113b6b0-d9b6-4f86-b803-022039c2ba21)

#### d) Tambahkan data berikut di akhir: David 2330010
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/927de6a2-58d2-4256-9470-5d21aed00375)

#### e) Ubah data Udin menjadi data berikut: Idin 23300045
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d69f6314-6ac1-4171-82c4-04ca1e22fc18)

#### f) Ubah data terkahir menjadi berikut: Lucy 23300101
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/4addcf01-8776-4d26-9cbb-703a5e45c8af)

#### g) Hapus data awal
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/0f96b024-2afc-4ea3-a1d7-05bc102ca49d)

#### h) Ubah data awal menjadi berikut: Bagas 2330002
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d909d038-07ff-4685-8682-b2cd6bee1076)

#### i) Hapus data akhir
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/2f9bdb8c-b8c5-43c5-a42d-18a782bf4d16)

#### j) Tampilkan seluruh data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/da02a681-fc94-4846-bdbf-ca2a3ca1fc3d)

Program di atas merupakan implementasi dari linked list circular. Kelas *LinkedListCircular* memiliki beberapa fungsi untuk operasi-operasi dasar pada linked list, seperti menambah, mengubah, dan menghapus data mahasiswa, serta menampilkan seluruh data mahasiswa. Setiap operasi tersebut dapat dilakukan di depan, di belakang, atau di tengah linked list.
Di dalam *main()*, program menyediakan menu untuk pengguna agar dapat memilih operasi yang ingin dilakukan, seperti menambah, mengubah, atau menghapus data mahasiswa, serta menampilkan seluruh data mahasiswa. Pengguna dapat memilih menu sesuai kebutuhan, dan program akan menjalankan operasi yang dipilih. Selama program berjalan, data mahasiswa disimpan dalam linked list circular, yang artinya elemen terakhir terhubung kembali ke elemen pertama, membentuk lingkaran. Hal ini memungkinkan untuk melakukan traversing dari awal ke akhir linked list secara terus menerus.

## Kesimpulan
Linked list circular melingkar adalah varian dari struktur data linked list yang memiliki sifat khusus di mana elemen terakhir terhubung kembali ke elemen pertama, membentuk sebuah lingkaran. Hal ini berbeda dengan linked list biasa yang memiliki elemen terakhir yang menunjuk ke NULL. Linked list circular memiliki keunggulan utama yaitu kemampuannya untuk melakukan traversing dari awal ke akhir linked list secara terus menerus tanpa harus kembali ke elemen pertama. Hal ini memungkinkan pengolahan data yang lebih efisien dalam beberapa kasus penggunaan, terutama ketika diperlukan akses berulang terhadap seluruh elemen dalam linked list. Linked list circular juga memiliki kemiripan dengan linked list ganda (double linked list) dalam hal sifat melingkar. Namun, linked list circular hanya memiliki satu pointer next untuk setiap elemen, sementara linked list ganda memiliki dua pointer (next dan prev) yang menghubungkan setiap elemen dengan elemen sebelum dan sesudahnya. Meskipun demikian, linked list circular juga memiliki kelemahan, seperti kompleksitas dalam penanganan kasus khusus, seperti menemukan elemen terakhir atau melakukan operasi pada elemen terakhir. Selain itu, kesalahan dalam implementasi operasi tambah dan hapus elemen dapat mengakibatkan terjadinya looping tak terbatas. Dengan demikian, penggunaan linked list circular melingkar harus dipertimbangkan dengan cermat sesuai dengan kebutuhan aplikasi dan karakteristik data yang diolah. Kelebihan dan kelemahan dari struktur data ini perlu dipahami dengan baik agar dapat memanfaatkannya secara efektif dalam pengembangan perangkat lunak.

## Referensi
[1] "Pengantar Daftar Tertaut Melingkar" GeeksforGeeks, 2023.
https://www.geeksforgeeks.org/circular-linked-list/

[2] "Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya" Trivusi. 2022
https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html


