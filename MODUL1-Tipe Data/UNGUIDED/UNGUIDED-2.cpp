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
