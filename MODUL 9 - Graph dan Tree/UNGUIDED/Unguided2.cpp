//ANDIKA NEVIANTORO
//2311102167

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Struktur untuk node tree
struct Node {
    string name_167;
    vector<Node*> children;
};

// Fungsi untuk mencari node berdasarkan nama
Node* findNode(Node* root, const string& name) {
    if (root == nullptr) return nullptr;
    if (root->name_167 == name) return root;
    for (Node* child : root->children) {
        Node* result = findNode(child, name);
        if (result != nullptr) return result;
    }
    return nullptr;
}

// Fungsi untuk menambahkan child pada node
void addChild(Node* root, const string& parentName, const string& childName) {
    Node* parentNode = findNode(root, parentName);
    if (parentNode != nullptr) {
        Node* newChild = new Node{childName, {}};
        parentNode->children.push_back(newChild);
    } else {
        cout << "Parent node tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan semua child dari node
void showChildren(Node* root, const string& name) {
    Node* node = findNode(root, name);
    if (node != nullptr) {
        cout << "Children dari " << name << ": ";
        for (Node* child : node->children) {
            cout << child->name_167 << " ";
        }
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

// Fungsi rekursif untuk menampilkan semua descendant dari node
void showDescendants(Node* node) {
    if (node == nullptr) return;
    for (Node* child : node->children) {
        cout << child->name_167 << " ";
        showDescendants(child);
    }
}

// Fungsi untuk menampilkan semua descendant dari node
void showAllDescendants(Node* root, const string& name) {
    Node* node = findNode(root, name);
    if (node != nullptr) {
        cout << "Descendants dari " << name << ": ";
        showDescendants(node);
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

int main() {
    Node* root = new Node{"Root", {}};

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambahkan node" << endl;
        cout << "2. Tampilkan children dari node" << endl;
        cout << "3. Tampilkan descendants dari node" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // Untuk mengabaikan karakter newline setelah input pilihan

        if (choice == 1) {
            string parentName, childName;
            cout << "Masukkan nama parent: ";
            getline(cin, parentName);
            cout << "Masukkan nama child: ";
            getline(cin, childName);
            addChild(root, parentName, childName);
        } else if (choice == 2) {
            string name;
            cout << "Masukkan nama node: ";
            getline(cin, name);
            showChildren(root, name);
        } else if (choice == 3) {
            string name;
            cout << "Masukkan nama node: ";
            getline(cin, name);
            showAllDescendants(root, name);
        } else if (choice != 4) {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
