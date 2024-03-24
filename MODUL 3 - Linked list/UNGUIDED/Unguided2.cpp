//ANDIKA NEVIANTORO
//2311102167


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
    daftarProduk.tambahData("Wardah", 50000);
    daftarProduk.tambahData("Hanasui", 30000);

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