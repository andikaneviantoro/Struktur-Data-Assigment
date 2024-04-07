# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Hash Table

Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengelola data dengan cepat dan efisien. Ini beroperasi dengan prinsip kunci-nilai, di mana setiap elemen data memiliki kunci yang unik yang digunakan untuk mengakses atau memanipulasinya. Hash Table (Tabel Hash) adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Ini menggunakan fungsi hash untuk mengonversi kunci menjadi indeks dalam array. Dengan cara ini, akses ke data menjadi sangat cepat karena kita dapat langsung menghitung indeks tempat data disimpan. Ini cocok untuk pencarian, penyisipan, penghapusan, dan pembaruan data dalam waktu konstan, asalkan tidak ada konflik dalam fungsi hash (collision)[1].

### Kegunaan Struktur Data Hash Table 

- Pencarian Cepat: Dapat digunakan untuk mencari data dengan cepat berdasarkan key. Ini sangat berguna dalam aplikasi seperti basis data, kamus, dan cache.
- Penyimpanan Data: Hash table dapat digunakan untuk menyimpan data dengan efisien. Data dapat diambil dan dimasukkan ke dalam tabel dengan waktu konstan, 
  asalkan tidak ada collision yang signifikan.
- Implementasi Struktur Data Lain: Hash table dapat digunakan untuk mengimplementasikan struktur data lain, seperti set dan map[1].

### Operasi dalam Struktur Data Hash Table

- Pencarian (Search)
- Penyisipan (Insertion)
- Penghapusan (Deletion)
- Update
- Collision Handling
- Resize
- Iterasi[1].

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
Efisiensi Hash Table tergantung pada efisiensi fungsi hash yang digunakan. Fungsi hash yang baik harus menghasilkan distribusi nilai hash yang merata untuk menghindari bentrokan yang berlebihan[1].


   
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


Program diatas hash table diimplementasikan menggunakan array dari pointer ke node. Setiap node mewakili satu pasangan kunci-nilai. Fungsi hash yang sederhana digunakan untuk menghasilkan indeks dari kunci. Untuk menangani tabrakan (collision), chaining digunakan, yaitu ketika beberapa pasangan kunci-nilai memiliki indeks yang sama, mereka disimpan dalam linked list yang dihubungkan melalui pointer next. Di dalam kelas Hash Table menggunakan operasi, *insert(int key, int value)*, *get(int key)*, *remove(int key)*, *traverse()*.


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


Program ini adalah implementasi sederhana dari hash table dalam bahasa pemrograman C++. Hash table digunakan untuk menyimpan pasangan data, dalam hal ini nama dan nomor telepon, dengan menggunakan fungsi hash untuk menentukan posisi penyimpanan data di dalam tabel hash. Kelas HashNode digunakan untuk merepresentasikan node individu dalam hash table. Setiap node memiliki atribut nama dan nomor telepon. Kelas HashMap adalah implementasi hash table itu sendiri. Ini menggunakan vektor sebagai array untuk menyimpan node-node. Setiap indeks dalam vektor merupakan bucket yang berisi node-node yang dihasilkan oleh fungsi hash yang sama. Kelas ini menyediakan operasi-operasi dasar seperti penyisipan (insert), pencarian berdasarkan nama (searchByName), dan penghapusan (remove). Selain itu, terdapat juga fungsi untuk mencetak isi seluruh hash table (print). Dalam fungsi main(), beberapa operasi diuji coba antara lain; Tiga pasangan nim mahasiswa disisipkan ke dalam hash table menggunakan fungsi insert(), Dilakukan pencarian nomor telepon berdasarkan nama menggunakan fungsi searchByName(), Dilakukan penghapusan data berdasarkan nama menggunakan fungsi remove(), Seluruh isi hash table dicetak menggunakan fungsi print().




## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
### a. Setiap mahasiswa memiliki NIM dan nilai.
### b. Program memiliki tampilan pilihan menu berisi poin C.
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
//2311102167
//ANDIKA NEVIANTORO
//IF-11-E


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk merepresentasikan mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    int nilai;
};

// Class untuk hash table
class HashTable {
private:
    static const int SIZE = 100; // Ukuran hash table
    vector<Mahasiswa> table[SIZE]; // Array dari vector untuk menampung data

    // Fungsi hash untuk menghasilkan indeks dari NIM
    int hashFunction(string nim) {
        int sum = 0;
        for (char c : nim) {
            sum += c;
        }
        return sum % SIZE;
    }

public:
    // Fungsi untuk menambahkan data mahasiswa
    void tambahData(string nim, string nama, int nilai) {
        Mahasiswa mhs;
        mhs.nim = nim;
        mhs.nama = nama;
        mhs.nilai = nilai;
        int index = hashFunction(nim);
        table[index].push_back(mhs);
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(string nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it).nim == nim) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariByNIM(string nim) {
        int index = hashFunction(nim);
        for (Mahasiswa mhs : table[index]) {
            if (mhs.nim == nim) {
                cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai: " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data mahasiswa tidak ditemukan" << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void cariByNilai(int minNilai, int maxNilai) {
        for (int i = 0; i < SIZE; ++i) {
            for (Mahasiswa mhs : table[i]) {
                if (mhs.nilai >= minNilai && mhs.nilai <= maxNilai) {
                    cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai: " << mhs.nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice;
    string nim;
    string nama;
    int nilai;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari data mahasiswa dengan rentang nilai (80 - 90)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                hashTable.tambahData(nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM mahasiswa yang dicari: ";
                cin >> nim;
                hashTable.cariByNIM(nim);
                break;
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 - 90:" << endl;
                hashTable.cariByNilai(80, 90);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
```

#### Output:

### Tambah Data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/a185fa99-2c0f-44d8-9752-4f40d8847742)


### Tampilan Awal
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/4bd09d48-c55b-419c-a9f6-635f423b458f)



### Hapus Data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/49a3419e-7dad-4bc2-8084-20ba5f8e3f08)


### Setelah Hapus Data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d39d4ed2-d73c-4b5f-9c2b-9cdbd0c396af)


### Mencari Data Berdasarkan Nim Mahasiswa
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/c8772a97-e321-4e40-ae21-85621c3cf84d)


### Mencari Data Mahasiswa Berdasarkan Nilai
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/27a3361d-ca39-429b-ac31-bcbd08a828f6)


Program di atas merupakan implementasi sederhana dari hash table dalam C++, yang digunakan untuk mengelola data mahasiswa. Dengan menggunakan hash function untuk menghasilkan indeks dari NIM, data mahasiswa disimpan dalam hash table. Program menyediakan beberapa operasi dasar seperti penambahan, penghapusan, dan pencarian data berdasarkan NIM atau rentang nilai, serta menampilkan seluruh data dalam bentuk tabel. Pengguna diberikan menu interaktif untuk memilih operasi yang diinginkan, dan program akan terus berjalan hingga pengguna memilih opsi untuk keluar. Dengan demikian, program ini memberikan penggunaan dasar dari struktur data hash table dalam mengelola data mahasiswa secara efisien.

## Kesimpulan
Hash table adalah struktur data yang sangat berguna dalam pemrograman komputer karena efisiensinya dalam menyimpan dan mengakses data. Dengan menggunakan fungsi hash, hash table dapat mengonversi kunci data menjadi indeks dalam array, memungkinkan akses data dengan kompleksitas waktu yang konstan dalam banyak kasus. Salah satu keuntungan penggunaan Hash Table yaitu waktu aksesnya yang cukup cepat, jika record yang dicari langsungberada pada angka hash lokasi penyimpanannya. 

## Referensi
[1] Annisa, "Struktur Data Hash Table: Pengertian, Cara Kerja dan Operasi Hash Table" FAKULTAS ILMU KOMPUTER DAN TEKNOLOGI INFORMASI, Umsu, 2023. https://fikti.umsu.ac.id/struktur-data-hash-table-pengertian-cara-kerja-dan-operasi-hash-table/

[2] "Cara Menerapkan Contoh Tabel Hash di C/C++" DigitalOcean. 2023
https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus


