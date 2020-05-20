#include <iostream>

using namespace std;

class Heap {
private:
    int* heap;
    int idx;
    int MaxSize;

public:
    Heap(int size) {
        MaxSize = size;
        idx = 0;
        heap = new int[MaxSize + 1];
    }
    void createHeap();
    bool isFull();
    bool isEmpty();
    void insertH(int);
    int deleteH();
    void printH();
    void search(int);
    int heapLevel();
};
void Heap::createHeap() { 
    idx = 0;
}
bool Heap::isFull() {
    if (idx == MaxSize) return true;
    else return false;
}
bool Heap::isEmpty() {
    if (idx == 0) return true;
    else return false;
}
void Heap::insertH(int item) {
    int i;
    if (isFull()) {
        cout << "Heap is Full !" << endl;
        return;
    }
    i = ++idx;
    while (i != 1 && item > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}
int Heap::deleteH() {
    int parent, child;
    int item, temp;

    item = heap[1];
    temp = heap[idx--];
    parent = 1;
    child = 2;

    while (child <= idx) {
        if (child < idx && heap[child] < heap[child + 1]) child++;
        if (temp >= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child = child * 2;
    }
    heap[parent] = temp;
    return item;
}
void Heap::printH() {
    cout << "Heap list : ";
    for (int i = 1; i < idx + 1; i++)cout << heap[i] << " ";
    cout << endl;
}
void Heap::search(int item) {
    int n;
    if (isEmpty()) cout << "Heap is Empty !" << endl;
    else {
        n = 1;
        while (n != idx + 1 && heap[n] != item) ++n;
        if (n != idx + 1) cout << "is Found" << endl;
        else cout << "Not Found" << endl;
    }
}
int Heap::heapLevel() {
    return idx / 2;
}

int main() {
    int sizeH;
    int num, choice;
    cout << "Enter Heap Size : ";
    cin >> sizeH;

    Heap arrH(sizeH);

    while (true) {
        cout << "MENU : 1)InsertH 2)DeleteH 3)searchH 4)isEmpty 5)isFull 6)HeapLevel 7)PrintH 8)Quit" << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter to Insert : ";
            cin >> num;
            arrH.insertH(num);
            arrH.printH();
            break;
        case 2:
            arrH.deleteH();
            arrH.printH();
            break;
        case 3:
            cout << "Enter to Search : ";
            cin >> num;
            arrH.search(num);
            break;
        case 4:
            if (arrH.isEmpty()) cout << "Heap is Empty !" << endl;
            else cout << "Heap is not Empty !" << endl;
            break;
        case 5:
            if (arrH.isFull()) cout << "Heap is Full !" << endl;
            else cout << "Heap is not Full !" << endl;
            break;
        case 6:
            cout << "Heap Level is : ";
            cout << arrH.heapLevel() << endl;
            break;
        case 7:
            arrH.printH();
            break;
        case 8:
            return 0;
        }
    }
}