//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
using namespace std;

// Struktur Node untuk linked list dengan atribut Nama dan NIM
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Queue dengan linked list
struct Queue {
    Node* front;
    Node* back;
    int size;

    Queue() : front(nullptr), back(nullptr), size(0) {}

    bool isFull() {
        return false; // Linked list queue is never full unless memory is exhausted
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (isEmpty()) {
                back = nullptr;
            }
        }
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            index++;
        }
        if (index == 1) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueueAntrian("Andika", "2311102167");
    queue.enqueueAntrian("Bagnaia", "2311102100");
    queue.enqueueAntrian("Marquez", "2311102193");
    queue.enqueueAntrian("Martins", "2311102135");
    queue.enqueueAntrian("Zarco", "2311102156");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
