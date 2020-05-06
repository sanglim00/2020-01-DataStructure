#include <iostream>
#include <string>

using namespace std;

char prec[4][2] = { '*', 2, '/', 2, '+', 1 , '-', 1 };

class Node {
private:
    char data;
    int prio;
    Node* left;
    Node* right;
    Node(char value) :data(value), prio(100), left(NULL), right(NULL) {}
    Node(char value, int prio) : data(value), prio(prio), left(NULL), right(NULL) {}
    friend class Tree;
};

class Tree {
private:
    Node* root;
public:
    Tree() { root = 0; }
    ~Tree() {}
    void buildTree(char data);
    void operatorT(char data, int prio);
    void operandT(char data);
    void inorder(Node* p);
    void postorder(Node* p);
    void preorder(Node* p);
    bool isNUM(char data);
    int evalTree(Node* p);
    bool NotP(char data);
    void printEval();
    void display(int num);
};
void Tree::buildTree(char data) {
    for (int i = 0; i < 4; i++) {
        if (prec[i][0] == data) {
            operatorT(data, prec[i][1]);
            return;
        }
    }
    operandT(data);
}


void Tree::operatorT(char data, int prio) {
    Node* temp = new Node(data, prio);
    Node* p = root;
    if (root->prio >= temp->prio) {
        temp->left = root;
        root = temp;
    }
    else {
        temp->left = root->right;
        root->right = temp;
    }
}
void Tree::operandT(char data) {
    Node* temp = new Node(data);
    Node* p;
    if (root == NULL) root = temp;
    else {
        p = root;
        while (p->right != NULL) p = p->right;
        p->right = temp;
    }
}

void Tree::inorder(Node* p) {
    if (p) {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}
void Tree::postorder(Node* p) {
    if (p) {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}
void Tree::preorder(Node* p) {
    if (p) {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

bool Tree::isNUM(char data) {
    switch (data) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 1;
    }
    return 0;
}
int Tree::evalTree(Node* p) {
    int value = 0;
    int left = 0;
    int right = 0;
    if (p != NULL) {
        if (isNUM(p->data))
            value = p->data - '0';
        else {
            left = evalTree(p->left);
            right = evalTree(p->right);
            switch (p->data) {
            case '+':
                value = left + right;
                break;
            case '-':
                value = left - right;
                break;
            case '*':
                value = left * right;
                break;
            case '/':
                value = left / right;
                break;
            }
        }
    }
    else cout << "Empty tree" << endl;
    return value;
}
void Tree::printEval() {
    cout << "EvalTree :";
    cout << evalTree(root) << endl;
}

bool Tree::NotP(char data) {
    if (data == '(') return false;
    else if (data == ')') return false;
    else return true;
}

void Tree::display(int num) {
    Node* p = root;
    switch (num) {
    case 1:
        cout << "Inorder :";
        inorder(p);
        break;
    case 2:
        cout << "Postorder :";
        postorder(p);
        break;
    case 3:
        cout << "Preorder :";
        preorder(p);
        break;
    }
    cout << endl;
}

int main() {
    Tree myTree;
    string str;
    int choice;

    cout << "Enter Expression : ";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        if (myTree.NotP(str[i]))
            myTree.buildTree(str[i]);

    myTree.display(1);
    myTree.display(2);
    myTree.display(3);
    myTree.printEval();

    Tree myTree2;
    cout << "Enter Expression 2: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        if (myTree2.NotP(str[i]))
            myTree2.buildTree(str[i]);

    myTree2.display(1);
    myTree2.display(2);
    myTree2.display(3);


}
