#include <iostream>

using namespace std;

char arr[100] = {};

class Stack {
private:
	int top;
	char *stack;
	const int Size ;
public:
	Stack (int Size);
	void push(char val);
	void pop();
	bool StackFull();
	bool StackEmpty();
	void displayStack();
};
Stack::Stack(int Size) : Size(Size) {
	stack = new char[Size];
	top = -1;
}
void Stack::push(char val) {
	if (StackFull())
		cout << "Stack Full" ;
	else
		stack[++top] = val;
}
void Stack::pop() {
	if (!StackEmpty())
		cout << stack[top--];
	else
		cout << "Stack Empty";
}
bool Stack::StackFull() {
	if (top == Size - 1)
		return true;
	else
		return false;
}
bool Stack::StackEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}
void Stack::displayStack() {
	if (StackEmpty()) {
		cout << "StackEmpty : ";
	}
	else {
		for (int i = top; i > -1; i--) {
			cout << stack[i] << " ";
		}
		cout << "\t";
	}
}

class Queue {
private:
	int rear;
	int front;
	char *queue;
	const int Size;
public :
	Queue(int Size);
	void enQueue(char val);
	void deQueue();
	bool QueueFull();
	bool QueueEmpty();
	void displayQueue();
};

Queue::Queue(int Size) :Size(Size){
	queue = new char[Size];
	rear = -1;
	front = -1;
}
void Queue::enQueue(char val) {
	if (QueueFull())
		cout << "Queue Full";
	else
		queue[++rear] = val;
}
void Queue::deQueue() {
	if (!QueueEmpty())
		cout << queue[++front];
	else
		cout << "Queue Empty";
}
bool Queue::QueueFull() {
	if (rear == Size -1)
		return true;
	else
		return false;
}
bool Queue::QueueEmpty() {
	if (rear == front)
		return true;
	else
		return false;
}
void Queue::displayQueue() {
	if(QueueEmpty())
		cout << "Queue Empty";
	else {
		for (int i = front+1; i <= rear; i++)
			cout << queue[i] << " ";
	}
}
class CQueue {
private:
	int rear;
	int front;
	int flag;
	char* Cqueue;
	const int Size ;
public :
	CQueue(int Size);
	void CEnque(char val);
	void Cdeque();
	bool CQEmpty();
	bool CQFull();
	void displayCQ();
};
CQueue::CQueue(int Size) :Size(Size) {
	Cqueue = new char[Size + 1];
	rear = 1;
	front = 1;
}
void CQueue::CEnque(char val) {
	if (front == rear && flag == 1)
		cout << "CQueue Full";
	else {
		Cqueue[rear] = val;
		rear = (rear + 1) % Size;
		flag = 1;
	}
}
void CQueue::Cdeque() {
	int item;
	if (front == rear && flag == 0) {
		cout << "CQueue Empty";
		exit(-1);
	}
	else {
		item = Cqueue[front];
		front = (front + 1) % Size;
		flag = 0;
	}
}
bool CQueue::CQEmpty() {
	if (rear == front)
		return true;
	else
		return false;
}
bool CQueue::CQFull() {
	if ((rear + 1) % Size == front)
		return true;
	else
		return false;
}

void CQueue::displayCQ() {
	int a = 0;
	for (int i = front; a < Size; i = (i + 1) % Size) {
		cout << Cqueue[i] << " ";
		a++;
	}
}

int main() {
	Stack stack(2);
	Queue queue(3);
	CQueue Cqueue(3);

	// 1)
	stack.push('a');
	queue.enQueue('b');
	queue.enQueue('c');
	queue.enQueue('d');
	stack.push('e');
	// 2)
	stack.push('F');
	cout <<'\t';
	queue.enQueue('G');
	cout << endl;
	// 3)
	cout << "Stack : ";
	stack.displayStack();
	cout << '\t';
	// 4)
	cout << "Queue : ";
	queue.displayQueue();
	cout << endl;
	// 5)
	cout << "Output : ";
	stack.pop();
	queue.deQueue();
	queue.deQueue();
	queue.deQueue();
	stack.pop();
	cout << endl;

	// 6)
	stack.pop();
	cout << '\t';
	queue.deQueue();

	// 7) 
	Cqueue.CEnque('A');
	Cqueue.CEnque('B');
	Cqueue.CEnque('C');
	Cqueue.Cdeque();
	Cqueue.CEnque('D');
	cout << endl;
	// 8)
	Cqueue.displayCQ();
	// 9)
	cout << endl;
	Cqueue.Cdeque();
	Cqueue.Cdeque();
	Cqueue.Cdeque();
	Cqueue.Cdeque();


	return 0;
}