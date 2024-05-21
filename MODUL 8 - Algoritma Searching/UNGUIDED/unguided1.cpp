//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk mengubah huruf besar menjadi huruf kecil
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Fungsi binary search untuk mencari huruf dalam string
int binarySearch(string kalimat, char cari) {
    int low = 0;
    int high = kalimat.length() - 1;
    
    // Ubah huruf pencarian menjadi huruf kecil jika huruf besar
    cari = toLower(cari);
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        char current = toLower(kalimat[mid]);
        
        if (current == cari) {
            return mid; // Huruf ditemukan
        } else if (current < cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1; // Huruf tidak ditemukan
}

int main() {
    string kalimat;
    char cari;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin Anda cari: ";
    cin >> cari;

    int index = binarySearch(kalimat, cari);

    if (index != -1) {
        cout << "Huruf '" << cari << "' ditemukan pada indeks ke-" << index << endl;
    } else {
        cout << "Huruf '" << cari << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
