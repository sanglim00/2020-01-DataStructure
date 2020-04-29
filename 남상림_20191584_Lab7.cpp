#include <iostream>

using namespace std;

class Node {
private:
	char data;
	Node* next;
	Node(char value) { data = value; next = 0; }
	friend class LinkedStack;
	friend class LinkedQueue;
	friend class SortList;
};

class LinkedStack {
private:
	Node* head;
public:
	LinkedStack() { head = 0; }
	void push(char);
	char pop();
	bool isEmpty();
	void display();
};

void LinkedStack::push(char data) {
	Node* temp = new Node(data);
	if (head == NULL) head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}
char LinkedStack::pop() {
	Node* p;
	char input;

	if (isEmpty()) cout << "Stack is Empty.\n";
	else {
		input = head->data;
		p = head;
		head = head->next;
		delete p;
		return input;
	}
}
bool LinkedStack::isEmpty() {
	if (head == NULL) return true;
	else return false;
}
void LinkedStack::display() {
	Node* p;
	if (head != NULL) {
		p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else cout << "Stack is Empty.\n";
}
class LinkedQueue {
private:
	Node* front;
	Node* rear;
public:
	LinkedQueue() { front = 0; rear = 0; }
	void enqueue(char);
	char dequeue();
	bool isEmpty();
	void display();
};
void LinkedQueue::enqueue(char data) {
	Node* temp = new Node(data);
	if (front == NULL) {
		front = temp; rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}
char LinkedQueue::dequeue() {
	Node* p;
	char input;

	input = front->data;
	p = front;

	if (front == rear) { front = 0; rear = 0; }
	else front = front->next;
	delete p;
	return input;
}
bool LinkedQueue::isEmpty() {
	if (front == NULL) return true;
	else return false;
}
void LinkedQueue::display() {
	Node* p;
	if (front != NULL) {
		p = front;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else cout << "Queue is Empty.\n";
}

class SortList {
private:
	Node* head;
public:
	SortList() { head = 0; }
	bool isEmpty();
	void concatenate(LinkedStack, LinkedQueue);
	void insert(char);
	void invert();
	void display();

};
bool SortList::isEmpty() {
	if (head == NULL) return true;
	else return false;
}
void SortList::concatenate(LinkedStack Slist, LinkedQueue Qlist) {
	while (!Slist.isEmpty()) insert(Slist.pop());
	while (!Qlist.isEmpty()) insert(Qlist.dequeue());
}
void SortList::insert(char val) {
	Node* temp = new Node(val);
	Node* p, * q;
	if (head == NULL) head = temp;
	else if(temp->data < head->data){
		temp->next = head;
		head = temp;
	}
	else {
		p = head; q = head;
		while (p != NULL && p->data < temp->data) {
			q = p;
			p = p->next;
		}if (p != NULL) {
			temp->next = p;
			q->next = temp;
		}
		else q->next = temp;
	}
}
void SortList::invert() {
	Node* p, * q, * r;
	p = head; q = NULL;
	while (p) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	 }
	head = q;
}

void SortList::display() {
	Node* p;

	if (head != NULL) {
		p = head;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		 }
		cout << endl;
	}
	else cout << "List is Empty.\n";
}
int main() {
	LinkedStack Slist;
	LinkedQueue Qlist;
	SortList sortlist;

	int choice;
	char input;

	while (true) {
		cout << "1. push 2. pop 3.printStack 4.enqueue 5.dequeue 6. printQueue 7.Merge  8.Invert 9.printList 10.quit  choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter an integer to push : ";
			cin >> input;
			Slist.push(input);
			break;
		case 2:
			cout << Slist.pop();
			cout << " --> is popped.\n";
			break;
		case 3:
			cout << "Stack : ";
			Slist.display();
			break;
		case 4:
			cout << "Enter an integer to enque : ";
			cin >> input;
			Qlist.enqueue(input);
			break;
		case 5:
			cout << Qlist.dequeue();
			cout << " --> is dequed.\n";
			break;
		case 6:
			cout << "Queue : ";
			Qlist.display();
			break;
		case 7:
			sortlist.concatenate(Slist, Qlist);
			cout << "List : ";
			sortlist.display();
			break;
		case 8:
			sortlist.invert();
			cout << "List : ";
			sortlist.display();
			break;
		case 9:
			cout << "List : ";
			sortlist.display();
			break;
		case 10:
			return 0;
			break;
		}
	 }

}
