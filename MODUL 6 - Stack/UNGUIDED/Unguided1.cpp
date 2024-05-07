//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk menghapus karakter non-alfabet dari kalimat
string hapusKarakterNonAlfabet(string str) {
    string hasil = "";
    for (char c : str) {
        if (isalpha(c)) {
            hasil += tolower(c);
        }
    }
    return hasil;
}

// Fungsi untuk memeriksa apakah sebuah kalimat merupakan palindrom atau tidak
bool Palindrom(string str) {
    stack<char> tumpukanKarakter;
    int panjang = str.length();

    // Menyisipkan setengah karakter pertama ke dalam stack
    for (int i = 0; i < panjang / 2; i++) {
        tumpukanKarakter.push(str[i]);
    }

    // Memeriksa karakter setengah kedua dengan karakter yang disisipkan dalam stack
    for (int i = panjang / 2 + (panjang % 2); i < panjang; i++) {
        if (str[i] != tumpukanKarakter.top()) {
            return false;
        }
        tumpukanKarakter.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Menghapus karakter non-alfabet dari kalimat
    string kalimatBersih = hapusKarakterNonAlfabet(kalimat);

    if (Palindrom(kalimatBersih)) {
        cout << "Kalimat tersebut adalah PALINDROM." << endl;
    } else {
        cout << "Kalimat tersebut BUKAN PALINDROM." << endl;
    }

    return 0;
}
