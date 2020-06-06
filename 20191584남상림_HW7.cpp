#include <iostream>

using namespace std;

const int max = 10;
char DataList[10][3] = { 'A', '6', 'B',
			'B', '7', 'C',
			'A', '1', 'C',
			'A', '5', 'D',
			'C', '5', 'D',
			'B', '3', 'E',
			'C', '8', 'E',
			'C', '4', 'F',
			'D', '2', 'F',
			'E', '9', 'F'
};

struct Node {
	char data;
	int cost;
	char data2;
	Node* next;
};

Node graph[max];

class Graph {
private:
	int totalCost = 0;
	int edge;
	Node* head;
	int* visited;
public:
	Graph(int);
	void initvisited();
	void InsertData();
	void SortedData();
	bool CheckCycle();
	void KruskalAlgorithm();
	void PrintTotalCost();
	void PrintData();
};
Graph::Graph(int num) {
	head = NULL;
	edge = num;
	visited = new int[edge];
}

void Graph::initvisited() {
	for (int i = 0; i < edge; i++) visited[i] = i;
}
void Graph::InsertData() {
	for (int i = 0; i < max; i++) {
		graph[i].data = DataList[i][0];
		graph[i].cost = DataList[i][1]-'0';
		graph[i].data2 = DataList[i][2];
	}
}
void Graph::SortedData() {
	for (int i = 0; i < max-1; i++) {
		for (int j = 0; j < max - 1; j++) {
			if (graph[j].cost > graph[j + 1].cost) {
				Node tmp = graph[j];
				graph[j] = graph[j+1];
				graph[j + 1] = tmp;
			}
		}
	}
}
bool Graph::CheckCycle() {
	Node* p = head;
	int count = 0;
	while (p) {
		p = p->next;
		count++;
	}
	if (count == edge - 1) return true;
	else return false;
}

void Graph::KruskalAlgorithm() {
	SortedData();
	initvisited();
	int index = 0;
	Node* temp;

	while (!CheckCycle()) {
		if (visited[graph[index].data - 65] > visited[graph[index].data2 - 65]) {
			int chk = visited[graph[index].data2];
			for (int j = 0; j < max; j++) {
				if (visited[j] == chk) visited[j] = visited[graph[index].data2 - 65];
			}
			totalCost += graph[index].cost;
			temp = new Node();
			temp->data = graph[index].data;
			temp->cost = graph[index].cost;
			temp->data2 = graph[index].data2;
			if (head == NULL) head = temp;
			else {
				Node* p = head;
				while (p->next) p = p->next;
				p->next = temp;
			}
		}
		else if (visited[(graph[index].data) - 65] < visited[(graph[index].data2) - 65]) {
			int chk = visited[graph[index].data2 - 65];
			for (int j = 0; j < max; j++) {
				if (visited[j] == chk) visited[j] = visited[graph[index].data - 65];
			}
			totalCost += graph[index].cost;
			temp = new Node();
			temp->data = graph[index].data;
			temp->cost = graph[index].cost;
			temp->data2 = graph[index].data2;
			if (head == NULL) head = temp;
			else {
				Node* p = head;
				while (p->next) p = p->next;
				p->next = temp;
			}
		}
		index++;
	}

	Node* p = head;
	int i = 1;
	while (p != NULL) {
		cout << "Edge " << i++ << " : " << p->data << " "<< p->cost << " "<< p->data2 << endl;
		p = p->next;
	}
}
void Graph::PrintTotalCost() {
	cout << totalCost << endl;
}

void Graph::PrintData() {
	for (int i = 0; i < 5; i++)
		cout << graph[i].data << " " << graph[i].cost << " " << graph[i].data2 << "\t";
	cout << endl;
	for (int i = 5; i < max; i++)
		cout << graph[i].data << " " << graph[i].cost << " " << graph[i].data2 << "\t";
	cout << endl;
}

int main() {
	Graph myG(6);

	myG.InsertData();
	cout << "1. Input Data : " << endl;
	myG.PrintData();
	cout << endl;

	cout << "2. Sorted Data : " << endl;
	myG.SortedData();
	myG.PrintData();
	cout << endl;

	cout << "3. Kruskal's MST : " << endl;
	myG.KruskalAlgorithm();
	cout << "\n4. Total Cost : ";
	myG.PrintTotalCost();
	return 0;
}
