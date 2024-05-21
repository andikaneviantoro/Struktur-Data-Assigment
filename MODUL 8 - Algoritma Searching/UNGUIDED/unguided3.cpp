//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
using namespace std;

// Fungsi untuk menghitung berapa kali angka 4 muncul dalam array
int countOccurrences(int data[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int occurrences = countOccurrences(data, n, target);

    cout << "Jumlah angka 4 dalam data adalah: " << occurrences << endl;

    return 0;
}
