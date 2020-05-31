#include <iostream>
#include <fstream>

using namespace std;

const int max = 10;

class Node {
private:
	int data;
	Node* link;
public:
	Node(int num) : data(num), link(NULL) {}
	friend class Graph;
};

class Graph {
private:
	Node* graph[max];
	Node* front;
	Node* rear;
	bool visited[max];
public:
	Graph() :front(NULL), rear(NULL) {}
	void InitGraph();
	void InsertGraph(int, int);
	void DisplayGraph();
	void DFS(int);
};

void Graph::InitGraph() {
	for (int i = 0; i < max; i++) {
		graph[i] = NULL;
		visited[i] = false;
	}
}
void Graph::InsertGraph(int num, int num2) {
	if (graph[num] == NULL) {
		Node* temp = new Node(num);
		graph[num] = temp;
	}
	if (graph[num2] == NULL) {
		Node* temp2 = new Node(num2);
		graph[num2] = temp2;
	}
	Node* p = graph[num];
	Node* q = new Node(num2);
	while (p->link != NULL) p = p->link;
	p->link = q;

	p = graph[num2];
	Node* w = new Node(num);
	while (p->link != NULL) p = p->link;
	p->link = w;

}
void Graph::DisplayGraph() {
	for (int i = 0; i < max; i++) {
		if (graph[i] != NULL) {
			Node* p = graph[i];
			cout << "  graph[" << p->data << "] => ";
			p = p->link;
			for (p; p != NULL; p=p->link) cout << p->data << " ";
			cout << endl;
		}
	}
}
void Graph::DFS(int v) {
	Node* w;
	visited[v] = true;
	cout << "V" << v << " -> ";
	for (w = graph[v]; w != NULL; w = w->link)
		if (!visited[w->data]) DFS(w->data);
}


int main() {
	Graph G;
	G.InitGraph();

	ifstream infile;
	infile.open("HW6_input.txt");

	int num, num2;
	for (int i = 0; i < max; i++) {
		infile >> num >> num2;
		G.InsertGraph(num, num2);
	}
	cout << "<<    Graph Data 1    >>\n" << endl;
	G.DisplayGraph();
	cout << "\nDepth First Search Result : " ;
	G.DFS(0);

	cout <<"\n\n--------------------------\n"<< endl;

	G.InitGraph();
	ifstream infile2;
	infile2.open("HW6_input2.txt");

	int data, data2;
	for (int j = 0; j < max; j++) {
		infile2 >> data >> data2;
		G.InsertGraph(data, data2);
	}
	cout << "<<    Graph Data 2    >>\n" << endl;
	G.DisplayGraph();
	cout << "\nDepth First Search Result : " ;
	G.DFS(0);
	cout << endl;
}
