//HeapSort 가 돌아가지 않는 코드
//나머지는 잘 돌아간다

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
    bool isFull();
    bool isEmpty();
    void createH(int);
    void insertH(int);
    int deleteH();
    void printH();
    void search(int);
    int heapLevel();
    void MakeHeap(int);
    void HeapSort(int);
    void adjust(int, int);
};

bool Heap::isFull() {
    if (idx == MaxSize) return true;
    else return false;
}
bool Heap::isEmpty() {
    if (idx == 0) return true;
    else return false;
}
void Heap::createH(int item) {
    int i = ++idx;
    heap[i] = item;
}
void Heap::insertH(int item) {
    int i;
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
    for (int i = 1; i < idx + 1; i++)cout << heap[i] << " ";
    cout << endl;
}
void Heap::search(int item) {
    int n;
    if (isEmpty()) cout << "Heap is Empty !" << endl;
    else {
        n = 1;
        while (n != idx + 1 && heap[n] != item) ++n;
        if (n != idx + 1) cout << item << " is Found" << endl;
        else cout << "Not Found" << endl;
    }
}
int Heap::heapLevel() {
    return int(log2(idx) + 1);
}
void Heap::MakeHeap( int n) {
    for (int i = n / 2; i > 0; i--) adjust( i, n);
}
void Heap::HeapSort( int n) {
    int temp;
    for (int i = n - 1; i > 0; i--) {
        temp = heap[i];
        heap[i] = heap[i + 1];
        heap[i + 1] = temp;
        adjust(1, i);
        cout << "Sorting : ";
        printH();
    }
}
void Heap::adjust(int i, int n) {
    int child, j;
    child = 2 * i;
    int temp = heap[i];

    while (n >= child) {
        if ((n >= child) && (heap[child] < heap[child + 1])) child += 1;
        if (temp > heap[child]) break;
        j = child / 2;
        heap[j] = heap[child];
        child = 2 * child;
     }
    j = child / 2;
    heap[j] = temp;
}

int main() {
    int sizeH = 10;
    int num, choice;

    Heap arrH(sizeH);
    arrH.createH(26);
    arrH.createH(5);
    arrH.createH(77);
    arrH.createH(1);
    arrH.createH(61);
    arrH.createH(11);
    arrH.createH(59);
    arrH.createH(15);
    arrH.createH(48);
    arrH.createH(19);

    while (true) {
        cout << "MENU : 1)InsertH 2)DeleteH 3)searchH 4)PrintH 5)HeapLevel 6)HeapSort 7)MakeHeap 8)Quit" << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter to Insert : ";
            cin >> num;
            arrH.insertH(num);
            cout << "Heap list : ";
            arrH.printH();
            break;
        case 2:
            arrH.deleteH();
            cout << "Heap list : ";
            arrH.printH();
            break;
        case 3:
            cout << "Enter to Search : ";
            cin >> num;
            arrH.search(num);
            break;
        case 4:
            cout << "Heap list : ";
            arrH.printH();
            break;
        case 5:
            cout << "Heap Level is : ";
            cout << arrH.heapLevel() << endl;
            break;
        case 6:
            arrH.HeapSort(sizeH);
            cout << "Heap Sort : ";
            arrH.printH();
            break;
        case 7:
            arrH.MakeHeap(sizeH);
            cout << "Make Heap : ";
            arrH.printH();
            break;
        case 8:
            return 0;
        }
    }
}