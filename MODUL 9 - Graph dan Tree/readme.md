# <h1 align="center">Laporan Praktikum Modul 9 - Graph dan Tree</h1>
<p align="center">Andika Neviantoro - 2311102167</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Graph
Graf adalah sebuah kumpulan node (simpul) dalam bidang dua dimensi yang terhubung oleh sejumlah garis (sisi). Konsep ini digunakan untuk merepresentasikan obyek-obyek diskrit dan hubungannya. Dalam konteks ilmu komputer, graf menjadi fondasi dari berbagai aplikasi, salah satunya adalah dalam struktur data graf.[1]

#### Terdapat dua representasi umum dari struktur data graf yang dapat diimplementasikan:

1. *Adjacency List*:
Setiap simpul direpresentasikan sebagai struktur data yang berisi daftar semua simpul yang terhubung dengannya.

2. *Adjacency Matrix*:
 Merupakan matriks di mana baris dan kolom mewakili simpul-simpul, dan entri dalam matriks menunjukkan keberadaan sisi antara dua simpul.[1]

#### Kegunaan Struktur Data Graf

1. *Merepresentasikan Aliran Komputasi*:
Graf digunakan untuk menggambarkan aliran proses atau komputasi dalam sebuah sistem.

2. *Pemodelan Grafis*:
Dalam bidang pemrograman grafis, struktur data graf digunakan untuk membuat pemodelan objek dan interaksi di antara mereka.

3. *Alokasi Sumber Daya pada Sistem Operasi*:
 Dalam sistem operasi, graf digunakan untuk alokasi sumber daya seperti memori, prosesor, dan lainnya.

4. *Rute Terpendek pada Peta Interaktif*:
Contohnya adalah penggunaan graf pada Google Maps untuk menemukan rute terpendek antara dua lokasi.

5. *Representasi State-Transition dalam Sistem*:
Dalam sistem yang melibatkan perubahan state, graf digunakan untuk merepresentasikan state dan transisi di antara mereka.

6. *Pemecahan Teka-Teki dan Permasalahan yang Memiliki Satu Solusi*:
Seperti pemecahan labirin, graf dapat digunakan untuk memodelkan permasalahan dengan satu solusi yang unik.

7. *Aplikasi Peer to Peer (P2P) dalam Jaringan Komputer*:
 Graf digunakan dalam aplikasi P2P untuk mengatur koneksi dan pertukaran data antar node.[1]


### Tree
Kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layakya struktur sebuah pohon. Struktur pohon adalah suatu cara
merepresentasikan suatu struktur hirarki (one-to-many) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan nodenode dari atas ke bawah. Suatu struktur data yang tidak linier yang menggambarkan hubungan yang hirarkis (one-to-many) dan tidak linier antara elemen-elemennya.[2]

#### Istilah dalam Tree
- Predecesor
-  Successor
-  Ancestor
-  Descendant
-  Parent
- Child
- Sibling
- Subtree
- Size
- Height
- Root
- Leaf
- Degree.[2]

#### Jenis-Jenis Tree
- FULL BINARY TREE
  Semua node, kecuali leaf pasti memiliki 2 anak dan tiap subpohon memiliki
  panjang path yang sama.
- COMPLETE BINARY TREE
  Tree yang mirip dengan full binary tree, tapi tiap subtree boleh memiliki panjang
  path yang berbeda dan tiap node (kecuali leaf) memiliki 2 anak.
- SKEWED BINARY TREE
  Binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu anak.[2]




## Guided 

### Guided 1

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "Tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};

void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]

                     << ")";
            }
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/fd9efcf1-3a2a-40dd-a809-cebc48a841a3)



Program ini mendefinisikan sebuah graf berarah menggunakan array `simpul` untuk nama-nama kota dan matriks `busur` untuk menyimpan jarak antar kota. Fungsi `tampilGraph` menampilkan graf tersebut dengan mencetak setiap kota beserta kota-kota lain yang terhubung langsung dengannya dan jarak antar kota tersebut. Fungsi `main` memanggil `tampilGraph` untuk menampilkan graf ke layar. Program ini memvisualisasikan hubungan dan jarak antar kota dengan output berupa daftar kota dan koneksinya.

### Guided 2

```C++
#include <iostream>
using namespace std;
// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};
// pointer global
Pohon *root;
// Inisialisasi
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " <<

                data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&

                node->parent->right == node)

                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node

                     && node->parent->left == node)

                cout << "Sibling : " << node->parent->right->data <<

                    endl;

            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" <<

                    endl;

            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
}
```

#### Output :
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/4559905d-689a-40bb-afe3-d9f259e27ff2)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/c67e1a3d-89f3-4cc0-bbc6-66f9bdd4c165)




Program C++ di atas mengimplementasikan sebuah pohon biner yang menyediakan berbagai operasi pada pohon, seperti penambahan node, pengubahan data, pencarian, dan traversal. Program ini menggunakan struktur `Pohon` untuk merepresentasikan node, dengan setiap node memiliki data dan pointer ke anak kiri, anak kanan, dan orang tua. Fungsi `init` menginisialisasi pohon, dan `isEmpty` memeriksa apakah pohon kosong. 
Fungsi `newPohon` membuat node baru, sedangkan `buatNode`, `insertLeft`, dan `insertRight` menambahkan node ke pohon. Fungsi `update` mengubah data node, `retrieve` menampilkan data node, dan `find` memberikan informasi lengkap tentang node termasuk orang tua, sibling, dan anak-anaknya.
Program ini juga menyediakan fungsi untuk traversal pohon: `preOrder`, `inOrder`, dan `postOrder`. Selain itu, terdapat fungsi untuk menghapus node (`deleteTree` dan `deleteSub`) serta membersihkan seluruh pohon (`clear`). Fungsi `size` menghitung jumlah node dalam pohon, `height` menghitung tinggi pohon, dan `characteristic` menampilkan karakteristik pohon seperti ukuran dan tinggi.
Pada `main`, pohon dibangun dengan menambahkan beberapa node, memperbarui beberapa data node, dan menampilkan informasi serta karakteristik pohon. Traversal pohon dilakukan dan pohon dimodifikasi dengan menghapus subtree sebelum menampilkan traversal dan karakteristik pohon yang baru. Program ini mendemonstrasikan bagaimana mengelola dan memanipulasi pohon biner secara komprehensif.


## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah simpul: ";
    cin >> n;
    cin.ignore(); // Untuk mengabaikan karakter newline setelah membaca jumlah simpul

    vector<string> kota_167(n);
    unordered_map<string, unordered_map<string, int>> jarak;

    // Input nama kota
    for (int i = 0; i < n; ++i) {
        cout << "Masukkan nama simpul " << i + 1 << ": ";
        getline(cin, kota_167[i]);
    }

    // Input jarak antara kota
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                int d;
                cout << "Masukkan jarak dari " << kota_167[i] << " ke " << kota_167[j] << ": ";
                cin >> d;
                jarak[kota_167[i]][kota_167[j]] = d;
            }
        }
    }

    // Tampilkan jarak dari setiap kota ke kota lainnya
    for (int i = 0; i < n; ++i) {
        cout << "Jarak dari simpul " << kota_167[i] << " ke simpul lain:" << endl;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cout << kota_167[j] << ": " << jarak[kota_167[i]][kota_167[j]] << endl;
            }
        }
    }

    return 0;
}
```

#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/2d11a62b-d32b-4b25-8c7c-eb2b34cb8b0d)



Program C++ di atas membuat sebuah graf yang merepresentasikan jarak antar kota berdasarkan input pengguna. Pertama, program meminta pengguna untuk memasukkan jumlah simpul (kota) dan kemudian nama-nama kota tersebut. Nama-nama kota disimpan dalam sebuah vektor `kota_167`. Selanjutnya, program meminta pengguna untuk memasukkan jarak antara setiap pasangan kota dan menyimpannya dalam sebuah struktur data `unordered_map` dua dimensi `jarak`.
Setelah semua data dimasukkan, program menampilkan jarak dari setiap kota ke kota lainnya. Untuk setiap kota, program mencetak nama kota tujuan beserta jaraknya, kecuali jika kota tujuan adalah kota yang sama dengan kota asal. Program ini menggunakan fungsi `cin` dan `getline` untuk mengambil input dari pengguna dan menampilkan hasilnya menggunakan `cout`.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Struktur untuk node tree
struct Node {
    string name_167;
    vector<Node*> children;
};

// Fungsi untuk mencari node berdasarkan nama
Node* findNode(Node* root, const string& name) {
    if (root == nullptr) return nullptr;
    if (root->name_167 == name) return root;
    for (Node* child : root->children) {
        Node* result = findNode(child, name);
        if (result != nullptr) return result;
    }
    return nullptr;
}

// Fungsi untuk menambahkan child pada node
void addChild(Node* root, const string& parentName, const string& childName) {
    Node* parentNode = findNode(root, parentName);
    if (parentNode != nullptr) {
        Node* newChild = new Node{childName, {}};
        parentNode->children.push_back(newChild);
    } else {
        cout << "Parent node tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan semua child dari node
void showChildren(Node* root, const string& name) {
    Node* node = findNode(root, name);
    if (node != nullptr) {
        cout << "Children dari " << name << ": ";
        for (Node* child : node->children) {
            cout << child->name_167 << " ";
        }
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

// Fungsi rekursif untuk menampilkan semua descendant dari node
void showDescendants(Node* node) {
    if (node == nullptr) return;
    for (Node* child : node->children) {
        cout << child->name_167 << " ";
        showDescendants(child);
    }
}

// Fungsi untuk menampilkan semua descendant dari node
void showAllDescendants(Node* root, const string& name) {
    Node* node = findNode(root, name);
    if (node != nullptr) {
        cout << "Descendants dari " << name << ": ";
        showDescendants(node);
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

int main() {
    Node* root = new Node{"Root", {}};

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambahkan node" << endl;
        cout << "2. Tampilkan children dari node" << endl;
        cout << "3. Tampilkan descendants dari node" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // Untuk mengabaikan karakter newline setelah input pilihan

        if (choice == 1) {
            string parentName, childName;
            cout << "Masukkan nama parent: ";
            getline(cin, parentName);
            cout << "Masukkan nama child: ";
            getline(cin, childName);
            addChild(root, parentName, childName);
        } else if (choice == 2) {
            string name;
            cout << "Masukkan nama node: ";
            getline(cin, name);
            showChildren(root, name);
        } else if (choice == 3) {
            string name;
            cout << "Masukkan nama node: ";
            getline(cin, name);
            showAllDescendants(root, name);
        } else if (choice != 4) {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
```
#### Output:
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/52af42e9-b21d-4190-8870-227e8c8e173b)



Program ini adalah implementasi sederhana dari pohon (tree) yang memungkinkan pengguna untuk menambahkan node, menampilkan anak-anak dari sebuah node, dan menampilkan semua keturunan dari sebuah node. Program ini memiliki struktur data `Node` yang berisi nama node dan vektor pointer ke anak-anaknya.
Pertama, program membuat sebuah node root dengan nama "Root". Kemudian, program menampilkan menu yang berisi opsi untuk menambahkan node, menampilkan anak-anak dari sebuah node, menampilkan semua keturunan dari sebuah node, dan keluar dari program. Setiap opsi menu meminta pengguna memasukkan nama node yang relevan.
Fungsi `addChild` menambahkan node baru sebagai anak dari node yang ditentukan. Fungsi `showChildren` menampilkan anak-anak dari node tertentu, sedangkan `showAllDescendants` menampilkan semua keturunan dari node yang ditentukan. Fungsi-fungsi ini menggunakan pencarian rekursif dengan bantuan fungsi `findNode` untuk mencari node berdasarkan nama.
Program ini berjalan dalam loop hingga pengguna memilih opsi untuk keluar, sehingga memungkinkan pengguna untuk melakukan berbagai operasi pada pohon dengan cara yang sederhana dan mudah dipahami.



## Kesimpulan
Graf adalah struktur data yang terdiri dari simpul-simpul yang terhubung oleh sisi-sisi. Representasi umum graf meliputi *adjacency list* dan *adjacency matrix*, yang masing-masing memiliki kegunaannya dalam berbagai aplikasi seperti pemodelan aliran komputasi, pemrograman grafis, alokasi sumber daya pada sistem operasi, rute terpendek pada peta interaktif, dan lainnya.
Sementara itu, tree adalah struktur data yang menggambarkan hubungan hirarkis antara elemen-elemennya, seperti dalam sebuah pohon. Tree memiliki banyak istilah yang digunakan untuk menggambarkan hubungan antar nodenya, seperti parent, child, sibling, dan lainnya. Terdapat juga beberapa jenis tree seperti full binary tree, complete binary tree, dan skewed binary tree, masing-masing dengan karakteristiknya sendiri.
Dari penjelasan tersebut, dapat disimpulkan bahwa graf dan tree merupakan struktur data yang penting dalam pemrograman komputer karena kemampuannya dalam merepresentasikan hubungan dan struktur data secara efisien, yang digunakan dalam berbagai aplikasi dan solusi permasalahan.


## Referensi
[1] Kosmos, P. "Pengertian Struktur Data Graf: Manfaatnya dalam Dunia Komputer",D3 Rekayasa Perangkat Lunak Aplikasi Fakultas Ilmu Terapan, Universitas Telkom 2023.

[2] "Tree (Pohon)", Jurusan Teknik Elektro Fakultas Teknik Universitas Negeri Malang.


