#include <iostream>
#include <iomanip> // Untuk menggunakan setprecision
using namespace std;

int main() {
    int n;
    cout << "Masukkan panjang array: ";
    cin >> n;

    // Mengalokasikan memori untuk array
    int *arr = new int[n];

    // Meminta pengguna memasukkan elemen array
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cout << "Angka ke-" << (i+1) << ": ";
        cin >> arr[i];
    }

    int menu_167;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Mencari nilai maksimum\n";
        cout << "2. Mencari nilai minimum\n";
        cout << "3. Mencari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih operasi (1-4): ";
        cin >> menu_167;

        switch (menu_167) {
            case 1: {
                // Mencari nilai maksimum
                int maks = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > maks) {
                        maks = arr[i];
                    }
                }
                cout << "Nilai maksimum: " << maks << endl;
                break;
            }
            case 2: {
                // Mencari nilai minimum
                int min = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                cout << "Nilai minimum: " << min << endl;
                break;
            }
            case 3: {
                // Menghitung nilai rata-rata
                double sum = 0.0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                double rata_rata = sum / n;
                cout << "Nilai rata-rata: " << fixed << setprecision(2) << rata_rata << endl;
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan program ini\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi yaa\n";
        }
    } while (menu_167 != 4);

    // Menghapus memori yang dialokasikan untuk array
    delete[] arr;

    return 0;
}
