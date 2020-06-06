#include <iostream>
#include <vector>

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
	int edge = 0;
	bool visited[max];
public:
	void InitVisited();
	void InsertData();
	void SortedData();
	bool CheckCycle(int);
	void KruskalAlgorithm();
	void PrintData();
};

void Graph::InitVisited() {
	for (int i = 0; i < max; i++) visited[i] = false;
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

vector<char> V;

bool Graph::CheckCycle(int idx) {
	

}

void Graph::KruskalAlgorithm() {
	SortedData();
	InitVisited();

	V.push_back(graph[0].data);
	V.push_back(graph[0].data2);
	totalCost += graph[0].cost;
	cout << "Edge " << 1 << " : " << graph[0].data << " " << graph[0].cost << " " << graph[0].data2 << endl;
	for (int i = 1; i < max; i++) {
		if (!CheckCycle(i)) {
			V.push_back(graph[i].data);
			V.push_back(graph[i].data2);
			totalCost += graph[i].cost;
			cout<<"Edge "<<i+1<<" : "<< graph[i].data << " " << graph[i].cost << " " << graph[i].data2 << endl;
		}
	}

	cout << "\n4. Total Cost : " << totalCost << endl;
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
	Graph myG;

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

	return 0;
}
