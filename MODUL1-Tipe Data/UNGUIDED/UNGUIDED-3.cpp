#include <iostream>
#include <map>
#include <string>

using namespace std;

// Fungsi untuk melakukan translasi kata
string translateKata_Dika167(const map<string, string>& kamus_167, const string& kata_167) {
    auto iter = kamus_167.find(kata_167);
    if (iter != kamus_167.end()) {
        return iter->second; // Mengembalikan kata terjemahan jika ditemukan
    } else {
        return "Kata tidak ditemukan"; // Mengembalikan pesan jika kata tidak ditemukan
    }
}

int main() {
    // Mendefinisikan map untuk menyimpan kamus Indonesia-Inggris
    map<string, string> kamus_167 = {
        {"halo", "hello"},
        {"aku", "I"},
        {"cinta", "love"},
        {"kamu", "you"},
        {"belajar", "learn"},
        {"makan", "eat"},
        {"minum", "drink"},
        {"rumah", "house"},
        {"mobil", "car"},
        {"kucing", "cat"},
        {"anjing", "dog"},
        {"burung", "bird"},
        {"buku", "book"},
        {"pensil", "pencil"},
        {"komputer", "computer"},
        {"sekolah", "school"},
        {"meja", "table"},
        {"kursi", "chair"},
        {"televisi", "television"},
        {"musik", "music"},
        {"senang", "happy"},
        {"sedih", "sad"},
        {"dia", "he/she"},
        {"kita", "we"},
        {"mereka", "they"},
        {"sekolah", "school"},
        {"rumah", "house"},
        {"burung", "bird"},
        {"mobil", "car"},
        {"motor", "motorcycle"},
        {"buku", "book"},
        {"pensil", "pencil"},
        {"komputer", "computer"},
        {"meja", "table"},
        {"kursi", "chair"},
        {"televisi", "television"},
        {"handphone", "cellphone"},
        {"buah", "fruit"},
        {"sayur", "vegetable"},
        {"air", "water"},
        {"api", "fire"},
        {"angin", "wind"},
        {"matahari", "sun"},
        {"bulan", "moon"},
        {"bintang", "star"},
        {"pohon", "tree"},
        {"hewan", "animal"},
        {"laut", "sea"},
        {"gunung", "mountain"},
        {"danau", "lake"},
        {"sungai", "river"},
        {"jalan", "road"},
        {"kota", "city"},
        {"desa", "village"},
        {"negara", "country"},
        {"selamat", "congratulations"},
        {"terima kasih", "thank you"},
        {"tolong", "please"},
        {"maaf", "sorry"},
        {"pergi", "go"},
        {"datang", "come"},
        {"makan", "eat"},
        {"minum", "drink"},
        {"berjalan", "walk"},
        {"berlari", "run"},
        {"tidur", "sleep"},
        // Tambahkan kata-kata lain di sini sesuai kebutuhan
    };

    // Meminta input dari pengguna
    string kata_167;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "TRANSLATE KATA INDONESIA - INGGRIS" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Masukkan kata (bahasa Indonesia): ";
    cin >> kata_167;

    // Menerjemahkan kata
    string terjemahan = translateKata_Dika167(kamus_167, kata_167);

    // Menampilkan hasil translasi
    cout << "Terjemahan dalam bahasa inggris: " << terjemahan << endl;

    return 0;
}
