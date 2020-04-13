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
public:
private:
	char *stack;
	int top;
	int StackSize ;
public :
	Stack(int SSize) {
		stack = new char[SSize];
		StackSize = SSize;
		top = -1;
	}
	void push(char buffer);
	char pop();
	bool isEmpty();
	bool isFull();
	int stacktop();
	void displayStack();
};

void Stack::push(char buffer) {
	if (isFull()) 
		cout << "Stack is Full"<<endl;
	else
		stack[++top] = buffer;
}
char Stack::pop() {
	if (isEmpty())
		cout << "Stack is Empty" << endl;
	else
		return stack[--top];
}
bool Stack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}
bool Stack::isFull() {
	if (top == StackSize - 1)
		return true;
	else
		return false;
}
int Stack::stacktop() {
	return stack[top];
}
void Stack::displayStack() {
	int sp = top;
	while (sp != -1) {
		cout << stack[sp--] << endl;
	 }
}

int Priority(char oprt) {
	if (oprt == '(')
		return 1;
	else if (oprt == '*' || oprt == '/')
		return 2;
	else if (oprt == '+' || oprt == '-')
		return 3;
	else if (oprt == ')')
		return 4;
	else
		return 0;
}

void postfix(char* buffer) {
	
	Stack stack(100);
	int i = 0;

	while(buffer[i] !='\0') {
		switch (Priority(buffer[i])) {
		case 0:
			cout << buffer[i];
			break;
		case 1:
			stack.push(buffer[i]);
			break;
		case 2:
		case 3:
			if (Priority(buffer[i]) <= Priority(stack.stacktop()))
				stack.push(buffer[i]);
			else {
				cout << stack.stacktop();
				stack.pop();
				stack.push(buffer[i]);
			}
		case 4:
			while (stack.stacktop() != '(') {
				cout << stack.stacktop();
				stack.pop();
			 }
			stack.pop();
			break;
		}
		i++;
	}while (!stack.isEmpty())
		cout << stack.pop();
}

int eval(char* buffer) {
	
	Stack stack(100);

	int op1, op2;
	int i = 0;
	
	while (buffer[i] != '\0') {
		if (Priority(buffer[i]) == 0) {
			stack.push(buffer[i]-'0');
		}	
		else {
			op2 = stack.pop();
			op1 = stack.pop();

			switch (buffer[i]) {
			case'+':
				stack.push(op1 + op2);
				break;
			case'-':
				stack.push(op1 - op2);
				break;
			case'*':
				stack.push(op1 * op2);
				break;
			case'/':
				stack.push(op1 / op2);
				break;
			}
		}
		i++;
	}
	return stack.pop();
}

int main() {
	Stack stack(100);

	char buffer[80];

	ifstream infile("hw2.txt");
	while (infile.getline(buffer, 80)) {
		cout << "Enter data ( infix form ) : " << buffer << endl;
	 }
	cout << "Conversion ( postfix form ) : ";
	postfix(buffer);
	cout << "Result : " << eval(buffer) << endl;
	
}
