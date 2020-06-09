#include <iostream>
#include <fstream>

using namespace std;

const int numOfVertex = 7;

class ShortestPath {
private:
	bool* found;
	int *distance;
	int** cost;
	int Max;
public:
	ShortestPath();
	void InitCostMatrix();
	void Shortest_Path(int);
	void PrintDistance();
	void PrintCostMatrix();
	int Choose(int*, int, bool*);
};
ShortestPath::ShortestPath() {
	found = new bool[100];
	distance = new int[100];
}
void ShortestPath::InitCostMatrix() {
	ifstream infile;
	infile.open("Lab13_input.txt");
	Max = 100;

	cost = new int* [numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		cost[i] = new int[numOfVertex];
		for (int j = 0; j < numOfVertex; j++) 
			infile >> cost[i][j];
	}
}

void ShortestPath::Shortest_Path(int start) {
	int i, u, w;
	for (i = 0; i < numOfVertex; i++) {
		found[i] = false;
		distance[i] = cost[start][i];
	}

	found[start] = true;
	distance[start] = 0;

	cout << "\t\tShortest Path Distance\n\n";

	for (i = 0; i < numOfVertex - 1; i++) {
		cout << "Distance : ";
		PrintDistance();

		u = Choose(distance, numOfVertex, found);
		found[u] = true;
		cout << "\t( Selected Node : " << u << " )" << endl;
		for (w = 0; w < numOfVertex; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) 
					distance[w] = distance[u] + cost[u][w];
			}
		}
	}
}
void ShortestPath::PrintDistance() {
	for (int i = 0; i < numOfVertex; i++) cout << distance[i] << " ";
}
void ShortestPath::PrintCostMatrix() {
	cout << "\t\t\tCost Matrix\n\n\t";
	for (int i = 0; i < numOfVertex; i++) cout << "V" << i << "\t";
	cout << endl;
	for (int i = 0; i < numOfVertex; i++) {
		cout << "V" << i << "\t";
		for (int j = 0; j < numOfVertex; j++)  cout << cost[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}
int ShortestPath::Choose(int* distance, int n, bool* found) {
	int min, minNode;
	min = Max;
	for (int i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minNode = i;
		}
	}
	return minNode;
}

int main() {
	ShortestPath SP;

	SP.InitCostMatrix();
	SP.PrintCostMatrix();
	SP.Shortest_Path(0);
	
}