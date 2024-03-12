#include <iostream>
#include <cmath> // Untuk fungsi sqrt (akar kuadrat)
using namespace std;

// Fungsi untuk menghitung luas balok
float hitungLuasBalok_167(float panjang, float lebar, float tinggi) {
    return 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
}

// Fungsi untuk menghitung luas kubus
float hitungLuasKubus_167(float sisi) {
    return 6 * sisi * sisi;
}

// Fungsi untuk menghitung luas tabung
float hitungLuasTabung_167(float jariJari, float tinggi) {
    return 2 * 3.14 * jariJari * (jariJari + tinggi);
}

// Fungsi untuk menghitung luas kerucut
float hitungLuasKerucut_167(float jariJari, float tinggi) {
    return 3.14 * jariJari * (jariJari + sqrt(tinggi * tinggi + jariJari * jariJari));
}

int main() {
    int pilihan;
    do {
        cout << "=================+++++++++++++=================" << endl;
        cout << "SELAMAT DATANG DI PERHITUNGAN BENTUK RUANG DIKA" << endl;
        cout << "=================+++++++++++++=================" << endl;

        cout << "Pilih bentuk ruang : " << endl;
        cout << "1. balok" << endl;
        cout << "2. kubus" << endl;
        cout << "3. tabung" << endl;
        cout << "4. kerucut" << endl;
        cout << "5. keluar" << endl;
        cout << "Masukkan Pilihan (1-5) :";
        cin >> pilihan;

        if (pilihan == 1) {
            float panjang, lebar, tinggi;
            cout << "Masukkan panjang balok : ";
            cin >> panjang;
            cout << "Masukkan lebar balok :";
            cin >> lebar;
            cout << "Masukkan tinggi balok :";
            cin >> tinggi;
            cout << "Luas balok: " << hitungLuasBalok_167(panjang, lebar, tinggi) << endl;
        } else if (pilihan == 2) {
            float sisi;
            cout << "Masukkan panjang sisi kubus: ";
            cin >> sisi;
            cout << "Luas kubus: " << hitungLuasKubus_167(sisi) << endl;
        } else if (pilihan == 3) {
            float jariJari, tinggi;
            cout << "Masukkan jari-jari tabung : ";
            cin >> jariJari;
            cout << "Masukkan tinggi tabung :";
            cin >> tinggi;
            cout << "Luas tabung: " << hitungLuasTabung_167(jariJari, tinggi) << endl;
        } else if (pilihan == 4) {
            float jariJari, tinggi;
            cout << "Masukkan jari-jari kerucut : ";
            cin >> jariJari;
            cout << "Masuskkan tinggi kerucut :";
            cin >> tinggi;
            cout << "Luas kerucut: " << hitungLuasKerucut_167(jariJari, tinggi) << endl;
        } else if (pilihan != 5) {
            cout << "Pilihan tidak tersedia, Silakan pilih kembali." << endl;
        }
    } while (pilihan != 5);

    cout << "Terimakasih Telah Menggunakan Program Dika Bangun Ruang" << endl;

    return 0;
}
