#include <iostream>

using namespace std;

class Node {
private:
	int data;
	Node* left;
	Node* right;
	friend class Tree;
};

class Tree {
private:
	Node* root;
public:
	Tree() { root = 0; }
	~Tree() {};
	void insertT(int);
	Node* insertBST(Node*, int);
	void deleteT();
	Node* deleteBST(Node*, int);
	void searchT();
	Node* searchBST(Node*, int);
	void levelOrder();
	bool printLevel(Node*, int);
	void NumOfNodes();
	int leaves(Node*, int);
	int NonLeaves(Node*, int);
	Node* findMin(Node*);
	Node* findMax(Node*);
	void drawTree();
	void drawBST(Node*, int);
};

void Tree::insertT(int data) {
	insertBST(root, data);
}
Node* Tree::insertBST(Node* ptr, int data) {
	if (root == NULL) {
		Node* temp = new Node();
		temp->data = data;
		root = temp;
	}
	else if (ptr == NULL) {
		Node* temp = new Node();
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else if (data < ptr->data)
		ptr->left = insertBST(ptr->left, data);
	else if (data > ptr->data) 
		ptr->right = insertBST(ptr->right, data);
	return ptr;
}
void Tree::deleteT() {
	int num;
	Node* temp = root;
	if (temp == NULL) {
		cout << "Tree is Empty" << endl;
	}
	else {
		cout << "Enter number to Delete : ";
		cin >> num;
		deleteBST(temp, num);
	}
}
Node* Tree::deleteBST(Node* ptr, int data) {
	if (ptr != NULL) {
		if (data < ptr->data) ptr->left = deleteBST(ptr->left, data);
		else if (data > ptr->data) ptr->right = deleteBST(ptr->right, data);
		else if (ptr->left == NULL && ptr->right == NULL) ptr = NULL;
		else if (ptr->left == NULL) {
			Node* p = ptr;
			ptr = ptr->right;
			delete(p);
		}
		else if (ptr->right == NULL) {
			Node* p = ptr;
			ptr = ptr->left;
			delete(p);
		}
		else {
			Node* temp = findMax(ptr->left);
			ptr->data = temp->data;
			ptr->left = deleteBST(ptr->left, ptr->data);
		}
	}
	else cout << "Not Found" << endl;
	return ptr;
}
void Tree::searchT() {
	int num;
	Node* temp = root;
	if(temp ==NULL) cout << "Tree is Empty" << endl;
	else {
		cout << "Enter number to Search : ";
		cin >> num;
		searchBST(temp, num);
	}
}

Node* Tree::searchBST(Node* ptr, int data) {
	if (ptr != NULL) {
		if (data == ptr->data) return ptr;
		else if (data < ptr->data) ptr = searchBST(ptr->left, data);
		else if (data > ptr->data) ptr = searchBST(ptr->right, data);
	}
	else return NULL;
	
	cout << data << " is is found in the tree"<<endl;
	return ptr;
}

void Tree::levelOrder() {
	int level = 1;
	Node* temp = root;
	if (temp == NULL) cout << "Tree is Empty" << endl;
	else {
		while (printLevel(temp, level)) level++;
		cout << endl;
	}
}
bool Tree::printLevel(Node* ptr, int level) {
	if (ptr == NULL) return false;
	else if (level == 1) {
		cout << ptr->data << " ";
		return true;
	}
	else {
		bool left = printLevel(ptr->left, level-1);
		bool right = printLevel(ptr->right, level-1);
		return left || right;
	}
}
void Tree::NumOfNodes() {
	int count = 0;
	cout << "Number of Leaves : " << leaves(root, count) << "\t"<<"Number of NonLeaves : " << NonLeaves(root, count) << endl;
}

int Tree::leaves(Node* ptr, int count) {
	if (ptr !=NULL) {
		if (ptr->left == NULL && ptr->right == NULL) count++;
		else {
			count = leaves(ptr->left, count) + leaves(ptr->right, count);
		}
	}
	else count = 0;
	return count;
}
int Tree::NonLeaves(Node* ptr, int count) {
	if (ptr !=NULL) {
		if (ptr->left == NULL && ptr->right == NULL) count = 0;
		else count = NonLeaves(ptr->left, count) + NonLeaves(ptr->right, count) + 1;
	}
	else count = 0;
	return count;
}

Node* Tree::findMin(Node* ptr) {
	if (ptr == NULL)return NULL;
	else if (ptr->left == NULL) return ptr;
	else return findMin(ptr->left);
}
Node* Tree::findMax(Node* ptr) {
	if (ptr == NULL) return NULL;
	else if (ptr->right == NULL) return ptr;
	else return findMax(ptr);
}

void Tree::drawTree() {
	drawBST(root, 1);
}
void Tree::drawBST(Node* ptr, int level) {
	if (ptr != NULL && level <= 7) {
		drawBST(ptr->right, level++);
		for (int i = 1; i <= (level-1); i++) cout << "   ";
		cout << ptr->data;
		if (ptr->left != NULL && ptr->right != NULL) cout << "<" << endl;
		else if (ptr->right != NULL) cout << "¢Ö" << endl;
		else if (ptr->left != NULL) cout << " ¢Ù" << endl;
		else cout << endl;
		drawBST(ptr->left, level++);
	}
}

int main() {
	int choice, num;
	Tree myTree;

	while (true) {
		cout << "MENU 1)Insert 2)Delete 3)Search 4)LevelOrder 5)NumOfNodes 6)Print 7)Quit   choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter number to Insert : ";
			cin >> num;
			myTree.insertT(num);
			break;
		case 2:
			myTree.deleteT();
			break;
		case 3:
			myTree.searchT();
			break;
		case 4:
			myTree.levelOrder();
			break;
		case 5:
			myTree.NumOfNodes();
			break;
		case 6:
			myTree.drawTree();
			break;
		case 7:
			return 0;
		}

	}
}