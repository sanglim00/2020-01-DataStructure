//////////////////////////////////////////////////////////////
//HomeWork : HW2
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : Hw2 Infix-to-Postfix conversion & Evaluation
//Algorithm :
//
//
// Variable :
//
//
/////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Stack {
private:
    int* stack;
    int top;
    const int size;
public:
    Stack(int size);
    void push(int val);
    char pop();
    bool isEmpty();
    bool isFull();
    int stacktop();
    int get_top();
    void displayStack();
};

Stack stack(100);
char Earray[100] = {};

Stack::Stack(int size) :size(size) {
    stack = new int[size];
    top = -1;
}

void Stack::push(int val) {
    if (isFull())
        cout << "Stack is Full" << endl;
    else {
        ++top;
        stack[top] = val;
    }
}
char Stack::pop() {
    if (!isEmpty())
        return stack[top--];
}
bool Stack::isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}
bool Stack::isFull() {
    if (top == size - 1)
        return true;
    else
        return false;
}
int Stack::stacktop() {
    return stack[top];
}
int Stack::get_top() {
    return top;
}
void Stack::displayStack() {
    int sp = top;
    if (isEmpty())
        cout << "Stack is Empty" << endl;
    else {
        sp = top;
        while (sp != -1) {
            cout << stack[sp];
            --sp;
        }cout << endl;
    }
}

void postfix(char* buffer, int len) {
    int num = 0;
    for (int i = 0; i < len; i++) {
        if( buffer[i] == '(')
            stack.push(buffer[i]);
        else if (buffer[i] == '+' || buffer[i] == '-') {
                while (stack.get_top() >= 0 && stack.stacktop() != '(') {
                Earray[num++] = stack.pop();
                 }
            stack.push(buffer[i]);
        }
        else if (buffer[i] == '*' || buffer[i] == '/') {
                while (stack.get_top() >= 0 && stack.stacktop() != '(' && stack.stacktop() != '-' && stack.stacktop() != '+') {
                Earray[num++] = stack.pop();
                 }
            stack.push(buffer[i]);
        }
        else if (buffer[i] == ')') {
            while (stack.stacktop() != '(') {
                Earray[num++] = stack.pop();
             }
             stack.pop();
        }
        else
            Earray[num++] = buffer[i];
    }
    while (!stack.isEmpty()) {
        Earray[num++] = stack.pop();
     }
}


int main() {
    int len;

    char buffer[10];

    ifstream infile("hw2.txt");

    while (infile.getline(buffer, 80)) {
        len = strlen(buffer);
        cout << "Enter data ( infix form ) : " << buffer << endl;
        cout << "Conversion ( postfix form ) : ";
        postfix(buffer, len);
        int i = 0;
        while (Earray[i] != '\0') cout << Earray[i++];
        cout << endl;
    }
}
