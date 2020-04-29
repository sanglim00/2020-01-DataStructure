#include <iostream>

using namespace std;

class Node {
private:
	int data;
	char name[10];
	Node* next;
	Node* prev;
	Node(int val) {
		data = val;
		next = 0; prev = 0;
	 }
	friend class List;
};

class List {
private:
	Node* head;
	Node* current;
public:
	List() { head = 0; current = 0; }
	int ListLength();
	bool isEmpty();
	void InsertAfter(int);
	void InsertBefore(int);
	void InsertFirst(int);
	void InsertLast(int);
	void DeleteCurrent();
	void LocateCurrent(int);
	void UpdateCurrent(int);
	void DisplayCurrent();
	void Display();
	
};
int List::ListLength() {
	Node* p;
	p = head;
	int count = 0;
	while (p) {
		p = p->next;
		count++;
	}
	return count;
}
bool List::isEmpty() {
	if (head == NULL) return true;
	else return false;
}

void List::InsertAfter(int data) {
	Node* temp = new Node(data);
	Node* p;

	if (head == NULL) head = temp;
	else {
		p = head;
		while (p) {
			p = p->next;
		}p = current;
	}
	current = temp;

 }
void List::InsertBefore(int data) {
	Node* temp = new Node(data);

	if (head == NULL) head = temp;
	else if (temp->data == head->data) {
		head = head->next;
		head->prev = temp;
	}
	else {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	current = temp;
}
void List::InsertFirst(int data) {
	Node* temp = new Node(data);
	if (head == NULL) head = temp;
	else {
		temp->next = head;
		head = temp;
	}
	current = temp;
}
void List::InsertLast(int data) {
	Node* temp = new Node(data);
	Node* p;
	if (head == NULL) head == temp;
	else {
		p = head;
		while (p->next != 0) p = p->next;
		p->next = temp;
	}
	current = temp;
}
void List::DeleteCurrent() {
	Node* p, * q;

	if (head == NULL) cout << "List is Empty.\n";
	else if (head == current) {
		p = head;
		head = head->next;
		head->prev = 0;
		delete p;
		current = head;
	}
	else {
		q = head; p = head;
		while (p != 0 && p->data != current->data) {
			q = p; p = p->next;
		}if (p != 0) {
			q->next = p->next;
			if (p->next != 0) p->next->prev = q;
			delete p;
			current = head;
		}
		else cout << current->data << "is not in the list\n";
	}
}
void List::LocateCurrent(int data) {
	Node* p;
	if (head == NULL) cout << "List is Empty.\n";
	else if (ListLength() >= data) {
		p = head;
		while (p != 0 && p->data != current->data) {
			p = p->next;
		 }
		cout << p->data;
		current = p;
	}
	else {
		cout << "No such a Line.\n";
	}
	
}
void List::UpdateCurrent(int data) {
	current->data = data;
}
void List::DisplayCurrent() {
	cout << current->data << endl;
}
void List::Display() {
	Node* p, *q;
	p = head; q = current;
	char W;
	for (int i = 1; i <= ListLength(); i++) {
		if (p == q) W = '*';
		else W = ':';
		cout << i <<" "<< W <<" "<< p->data << endl;
		p = p->next;
	}
	cout << endl;
}


int main() {
	List lst;
	int choice, num;

	while (true) {
		cout << "1)InsertAfter 2)InsertBefore 3)InsertFirst 4)InsertLast 5)DeleteCurrent 6)LocateCurrent 7)UpdateCurrent 8)Displaycurrent 9)DisplayList 10)Quit\n";
		cout << "Choice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter a data to insert => ";
			cin >> num;
			lst.InsertAfter(num);
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 2:
			cout << "Enter a data to insert => ";
			cin >> num;
			lst.InsertBefore(num);
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 3:
			cout << "Enter a data to insert => ";
			cin >> num;
			lst.InsertFirst(num);
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 4:
			cout << "Enter a data to insert => ";
			cin >> num;
			lst.InsertLast(num);
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 5:
			lst.DeleteCurrent();
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 6:
			cout << "Enter a position to locate => ";
			cin >> num;
			lst.LocateCurrent(num);
			break;
		case 7:
			cout << "Enter a data to update => ";
			cin >> num;
			lst.UpdateCurrent(num);
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 8:
			lst.DeleteCurrent();
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 9:
			cout << "---------List---------\n";
			lst.Display();
			break;
		case 10:
			return 0;
		}
	 }
	
}
