/*********************************************
 HomeWork : HW2
 Name : Nam Sang Lim
 ID : 20191584
 Program Description : Hw2 Infix-to-Postfix conversion & Evaluation
Algorithm : hw2.txt 파일에서 수식데이터를 가져와 infix를 postfix로 바꿔준다.
                    바꿔준 postfix를 출력한 후 이를 다시 eval로 계산하여 최종 계산한 결과값을 출력한다.
 Variable : 
 Stack stack : infix를 postfix로 바꿔줄때 사용하는 스택으로 연산자 우선순위를 정해서 buffer[i] 값을 push와 pop을 반복한다.
                       반복한 값들을 Earray에 차곡차곡 담아 main함수에서 순서대로 출력한다.
                       연산자 우선순위 : *, / > +, - > ( 
                       ( 가 나오면 무조건 push 해준다.
                       +,- 가 나오면 top이 0 이상이고 ( 가 아니면 스택 top값을 Earray에 pop하고 buffer[i]를 push해준다.
                       *, / 가 나오면 top이 0 이상이고 (, +, - 가 아니면 스택 top값을  Earray에 pop하고 buffer[i]를 push해준다.
                       )가 나오면 스택에서 ( 를 만날 때까지 계속 Earray 에 pop 한다. 
                       숫자는 바로 Earray에 넣어준다.
Stack Estack : postfix를 계산해주기 위해 만든 스택이다. char형 정수를 int로 받기위해 CharToInt함수를 거처 온 결과값을
                       switch 문으로 계산하여 연산자가 나왔을 때 두 수를 계산해서 스택에 push해주기를 반복한다
                       최종적으로 스택에 남은 값이 결과이다. 이를 pop해서 return 해준다.
 Earray : infix를 postfix로 바꾸는 과정에서 순서대로 값을 담는 배열
 len : buffer속 요소의 길이 만큼 포문을 돌리기 위해서 선언한 int 형 변수이다.
 num : Earray의 인덱스를 결정하는 변수
**********************************************/
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
    Stack stack(100);
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '(')
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

int CharToInt(char buffer) {
    if (buffer == '+')
        return 1;
    else if (buffer == '-')
        return 2;
    else if (buffer == '*')
        return 3;
    else if (buffer == '/')
        return 4;
    else
        return 0;
}

int eval(char* Earray) {

    Stack stack(100);

    int i = 0;
    int op1, op2;
    while (Earray[i] != '\0') {
        switch (CharToInt(Earray[i])) {
        case 1:
        case 2:
        case 3:
        case 4:
            op2 = stack.pop() - '0';
            op1 = stack.pop() - '0';
            int value;
            switch (CharToInt(Earray[i])) {
            case 1:
                value = op1 + op2;
                stack.push(value);
                break;
            case 2:
                value = op1 - op2;
                stack.push(value);
                break;
            case 3:
                value = op1 * op2;
                stack.push(value);
                break;
            case 4:
                value = op1 / op2;
                stack.push(value);
                break;
            }
            break;
        case 0:
            stack.push(Earray[i]);
            break;
        default:
            break;
        }
        i++;
    }
    return stack.pop();
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
        cout << "Result : ";
        cout << eval(Earray) << endl;
    }

    return 0;
}
