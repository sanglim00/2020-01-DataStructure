#include <iostream>

using namespace std;

const int MaxSize = 7;

class Node {
    int data;
    Node* link;
    friend class Htable;
};
class Htable {
private:
    Node* hashTable[MaxSize];
public:
    Htable() {
        for (int i = 0; i < MaxSize; i++) hashTable[i] = NULL;
    }
    bool FindKey(int);
    void InsertKey(int);
    void DeleteKey(int);
    int hashing(int);
    void PrintTable();
};
bool Htable::FindKey(int key) {

    int index = hashing(key);
    Node* p = hashTable[index];

    if (p == NULL) return false;

    while (p != NULL && p->data != key)
        p = p->link;
    if (p == hashTable[index]) return true;
    return false;

}
void Htable::InsertKey(int key) {
    int index = hashing(key);
    bool check = FindKey(key);
    if (check == true) return;

    Node* q = new Node();
    Node* p;
    q->data = key;
    if (hashTable[index] == NULL) {
        hashTable[index] = q;
    }
    else {
        p = hashTable[index];
        while (p->link != NULL) p = p->link;
        p->link = q;
    }

}
void Htable::DeleteKey(int key) {
    int check = FindKey(key);
    if (check == false) cout << "Key not found\n";
    else {
        int index = hashing(key);
        if (hashTable[index]->data == key) {
            Node* q = hashTable[index];
            hashTable[index] = hashTable[index]->link;
            delete q;
        }
    }
}
int Htable::hashing(int key) {
    return key % MaxSize;
}

void Htable::PrintTable() {
    Node* p = new Node();
    for (int i = 0; i < MaxSize; i++) {
        cout << "LinkT[" << i << "] : ";
        if (hashTable[i] != NULL) p = hashTable[i];
        while (p != NULL) {
            cout << p->data ;
            if (p->link != NULL)cout << " -> ";
            p = p->link;
        }
        cout << "\n";
    }
    cout << endl;
}

int main() {
    char choice;
    int num;
    Htable HASH;

    while (true) {
        cout << "1) Find 2) Insert 3) Delete 4) Quit\t( f, i, d, q )\nChoice : ";
        cin >> choice;
        switch (choice) {
        case 'f':
            cout << "Enter number to Find : ";
            cin >> num;
            if (HASH.FindKey(num)) cout << "Key is Found\n";
            else cout << "Key Not Found\n";
            break;
        case 'i':
            cout << "Enter number to Insert : ";
            cin >> num;
            HASH.InsertKey(num);
            break;
        case 'd':
            cout << "Enter number to Delete : ";
            cin >> num;
            HASH.DeleteKey(num);
            break;
        case 'q':
            return 0;
        }
        HASH.PrintTable();
        cout << endl;
    }
}
