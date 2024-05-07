//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat per huruf menggunakan stack
string balikKalimat(string kalimat) {
    stack<char> hurufStack;
    string hasil = "";

    // Memasukkan setiap huruf ke dalam stack
    for (char c : kalimat) {
        hurufStack.push(c);
    }

    // Mengambil huruf-huruf dari stack untuk membalikkan urutannya
    while (!hurufStack.empty()) {
        hasil += hurufStack.top();
        hurufStack.pop();
    }

    return hasil;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat/ Kata: ";
    getline(cin, kalimat);

    string kalimatTerbalik = balikKalimat(kalimat);
    cout << "Hasil: " << kalimatTerbalik << endl;

    return 0;
}
