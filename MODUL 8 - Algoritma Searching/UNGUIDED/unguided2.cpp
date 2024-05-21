//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <cctype> // Untuk fungsi isalpha dan tolower
using namespace std;

// Fungsi untuk mengecek apakah suatu karakter merupakan huruf vokal
bool isVowel(char c) {
    c = tolower(c); // Ubah huruf menjadi huruf kecil untuk mempermudah pengecekan
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVowels(string kalimat) {
    int count = 0;
    for (char c : kalimat) {
        if (isalpha(c) && isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = countVowels(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;

    return 0;
}
