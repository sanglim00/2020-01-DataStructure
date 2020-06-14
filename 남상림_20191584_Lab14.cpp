#include <iostream>

using namespace std;

const int MaxSize = 7;

class Node{
	int data;
	Node* link;
	friend class Htable;
};
class Htable {
private:
	Node* head;
	Node* hashTable[MaxSize];
public:
	Htable() { for (int i = 0; i < MaxSize; i++) hashTable[i] = NULL; }
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
	if (p->data == key) return true;
	return false;
}
void Htable::InsertKey(int key) {
	int index = hashing(key);
	bool check = FindKey(key);
	if (check == true) return ;
	
	if (hashTable[index] == NULL) 
		hashTable[index]->data = key;
	else {
		Node* p = hashTable[index];
		while (p->link != NULL) p = p->link;
		p->link->data = key;
	}
	
}
void Htable::DeleteKey(int key) {
	int check = FindKey(key);
	if (check == false) cout<<"Key not found\n";
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
		cout <<"Htable["<<i << "] : ";
		if (hashTable[i] != NULL) p = hashTable[i];
		while (p != NULL) {
			cout << p->data << " ";
			p = p->link;
		}
		cout << endl;
	}
}

int main() {
	int choice, num;
	Htable HASH;

	while (true) {
		cout << "1) Find 2) Insert 3) Delete 4) Quit\nChoice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter number to Find : ";
			cin >> num;
			if (HASH.FindKey(num)) cout << "Found\n";
			else cout << "Not Found\n";
			break;
		case 2:
			cout<<"Enter number to Insert : ";
			cin >> num;
			HASH.InsertKey(num);
			break;
		case 3:
			cout<<"Enter number to Delete : "; 
			cin >> num;
			HASH.DeleteKey(num);
			break;
		case 4:
			return 0;
		}
		HASH.PrintTable();
	}
}