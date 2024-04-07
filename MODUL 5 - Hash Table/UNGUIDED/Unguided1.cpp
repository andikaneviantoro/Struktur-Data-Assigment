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