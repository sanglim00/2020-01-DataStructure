#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;
public:
    List() { head = NULL; }
    void insertNode(int);
    void deleteNode(int);
    void searchList(int);
    void print();
    void printLast();
    void printNth(int);
};

void List::insertNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    Node* p = NULL, * q = NULL;

    if (head == 0) head = temp;
    else if (temp->data < head->data) {
        temp->next = head;
        head = temp;
    }
    else {
        p = head;
        while ((p != 0) && (p->data < temp->data)) {
            q = p;
            p = p->next;
        }
        if (p != 0) {
            temp->next = p;
            q->next = temp;
        }
        else q->next = temp;
    }
}
void List::deleteNode(int num) {
    Node* p = NULL, * q = NULL;
    if (head->data == num) {
        p = head;
        head = head->next;
        delete p;
    }
    else {
        p = head;
        while (p != NULL && p->data != num) {
            q = p;
            p = p->next;
        }if (p != NULL) {
            q->next = p->next;
            delete p;
        }
        else cout << "not Found" << endl;
    }
}

void List::searchList(int num) {
    Node* p;
    if (head != 0) {
        p = head;
        while (p != 0 && p->data != num)
            p = p->next;
        if (p) cout << p->data << " is found. " << endl;
        else cout << num << " Not Found." << endl;
    }
    else cout << "List Empty" << endl;
}
void List::print() {
    Node* p = NULL;

    if (head == NULL) cout << "List Empty. " << endl;
    else p = head;
    cout << "List : ";
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void List::printLast() {
    Node* p = NULL;

    if (head == 0)  cout << "List Empty" << endl;
    else {
        p = head;
        while (p != NULL) {
            p = p->next;
            if (p->next == NULL) cout << p->data << endl;
        }
    }
}

void List::printNth(int N) {
    Node* p = NULL;
    Node* p2 = NULL;

    if (head == NULL) cout << "List Empty" << endl;
    else {
        p = head;
        p2 = head;
        int count = 0;
        while (p != NULL) {
            p = p->next;
            count++;
         }
        for (int i = 1; i <= count; i++) {
            if (N != i) p2 = p2->next;
            else if (N == i) cout << N << "th Node is : " << p2->data << endl;
        }
        if (N > count) cout << "Out of boundary\n";
    }
}

int main() {
    List lst;

    int choice, n;
    cout << "1.insert  2.delete 3.search 4.print 5.PrintLast 6.PrintNth 7.Quit\n";
    while (true) {
        cout << "Choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Input a Number : ";
            cin >> n;
            lst.insertNode(n);
            break;
        case 2:
            cout << "Input a Number : ";
            cin >> n;
            lst.deleteNode(n);
            break;
        case 3:
            cout << "Input a Number : ";
            cin >> n;
            lst.searchList(n);
            break;
        case 4:
            lst.print();
            break;
        case 5:
            lst.printLast();
            break;
        case 6:
            cout << "Input a Number : ";
            cin >> n;
            lst.printNth(n);
            break;
        case 7:
            return 0;
            break;
        }
    }
}