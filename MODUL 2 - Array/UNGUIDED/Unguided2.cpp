#include <iostream>
using namespace std;

int main()
{
    int sizeX, sizeY, sizeZ;

    // Input ukuran array dari pengguna
    cout << "Masukkan ukuran array pertama: " ;
    cin >> sizeX;
    cout << "Masukkan ukuran array kedua: " ;
    cin >> sizeY; 
    cout << "Masukkan ukuran array ketiga: " ;
    cin >> sizeZ;

    // Deklarasi array sesuai dengan input pengguna
    int arr[sizeX][sizeY][sizeZ];

    // Input elemen array
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int z = 0; z < sizeZ; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
    }
    cout << endl;

    // Output elemen array
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int z = 0; z < sizeZ; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int z = 0; z < sizeZ; z++)
            {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}