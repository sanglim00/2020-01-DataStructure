#include <iostream>
using namespace std;

struct Node {
    int data; // 노드에 저장되는 정수 데이터 
    struct Node* left; // 왼쪽 서브트리
    struct Node* right; // 오른쪽 서브트리
};

void insert(struct Node** root, int data) {
    Node* p;

    if(root == NULL) {
        p->data = data;
        root = &p;
    }
    else {
        if(p->data < data) p->right->data = data;
        else p->left->data = data;
        root = &p;
       
    }
};

void preOrder(struct Node* root) {
    if(root == NULL) return;
    cout<< root->data <<' ';
    preOrder(root->left);
    preOrder(root->right);
};

void inOrder(struct Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout<< root->data <<' ';
    inOrder(root->right);
};

void postOrder(struct Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<' ';
};

int size(struct Node* root) {
    return 1;
};

int height(struct Node* root) {
    return 1;
};

int sumOfWeight(struct Node* root) {
    return 1;
};

int maxPathWeight(struct Node* root) {
    return 1;
};

void mirror(struct Node** root) {

};

void destruct(struct Node** root) {

};

int main() {

    int times, num, data;
    struct Node* root = NULL;
    
    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> num;
        for(int j = 0; j < num; j++) {
            cin >> data;
            insert(&root, data);
        }
        cout << size(root) << endl;
        cout << height(root) << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;
        mirror(&root);
        preOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;
        destruct(&root);

        (root == NULL) ? cout<< 0 <<endl : cout << 1 <<endl;
    }

    return 0;
}