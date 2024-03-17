#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> array(n);

    cout << "Masukkan " << n << " angka: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << "Data Array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    cout << "Nomor Genap: ";
    bool genap = false;
    for (int i = 0; i < n; ++i) {
        if (array[i] % 2 == 0) {
            if (genap) cout << ", ";
            cout << array[i];
            genap = true;
        }
    }
    cout << endl;

    cout << "Nomor Ganjil: ";
    bool ganjil = false;
    for (int i = 0; i < n; ++i) {
        if (array[i] % 2 != 0) {
            if (ganjil) cout << ", ";
            cout << array[i];
            ganjil = true;
        }
    }
    cout << endl;

    return 0;
}
