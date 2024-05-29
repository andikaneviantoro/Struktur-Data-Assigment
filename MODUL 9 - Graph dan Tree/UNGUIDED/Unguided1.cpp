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
