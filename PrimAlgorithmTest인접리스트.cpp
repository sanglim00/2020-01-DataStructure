#include <iostream>
#include <fstream>

using namespace std;

const int max = 6;

class PrimMST {
private:
	int total = 0 , total2 = 0, edge = 0 , edge2 = 0;
	int costArr[max][max];
	int LowCost[max];
	bool visited[max];
public:
	PrimMST();
	void InitArr();
	int FindMin(int*);
	void InsertData(char, int, char);
	void printMST(char, char);
	void printMST();
	void Method1(int);
	void Method2(int);

};
PrimMST::PrimMST() {
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			costArr[i][j] = 100;
		}
	}
}
void PrimMST::InitArr() {
	for (int i = 0; i < max; i++) {
		LowCost[i] = 100;
		visited[i] = false;
	}
}
int PrimMST::FindMin(int* arr) {
	int min = 999;
	int index = 0;

	for (int i = 0; i < max; i++) {
		if (min > arr[i] && visited == 0) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}
void PrimMST::InsertData(char V, int num, char U) {
	costArr[(int)(V - 'A')][(int)(U - 'A')] = num;
	costArr[(int)(U - 'A')][(int)(V - 'A')] = num;
}
void PrimMST::printMST(char V, char U) {
	char printV = V + 'A';
	char printU = U + 'A';
	cout << "( " << printV<< "," << printU<< " )";
	visited[V] = true;
}
void PrimMST::printMST() {
	for (int i = 0; i < max; i++)  costArr[i][i] = 0;
	
	cout << "\t";
	for (int i = 0; i < max; i++) cout << (char)(i + 'A') << "\t";
	cout << endl;
	for (int i = 0; i < max; i++) {
		cout << (char)(i + 'A') << "\t";
		for (int j = 0; j < max; j++) {
			cout << costArr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < max; i++)  costArr[i][i] = 100;
}

void PrimMST::Method1 (int start) {
	int min = 100;
	int num ;

	for (int i = 0; i < max; i++) {
		if (costArr[start][i] && visited[i] != true) {
			min = costArr[start][i];
			num = i;
		}
	}
	total += min;
	printMST(start, num);

	if (edge < 4) cout << "-> ";
	else cout << "\n Weight : " << total << endl;

	edge++;
	if (edge < 5) Method1(num);
}
void PrimMST::Method2 (int start) {

	for (int i = 0; i < max; i++) {
		if (LowCost[i] > costArr[start][i] && visited == 0) 
			LowCost[i] = costArr[start][i];
	}
	for(edge2; edge2<5; edge2++) {
		int temp = FindMin(LowCost);
		int index;
		for (int j = 0; j < max; j++) {
			if (costArr[j][temp] == LowCost[temp]) index = j;
		}
		LowCost[temp] = 100;
		total2 += costArr[index][temp];
		printMST(index, temp);
		if (edge2 !=4) cout << "-> ";
		else cout << "\n Weight : " << total2 << endl;

		visited[temp] = true;
		Method2(temp);
	}
}

int main() {
	PrimMST prim;
	char data, data2;
	int num;

	ifstream infile;
	infile.open("Lab12_input.txt");

	prim.InitArr();

	for (int i = 0; i < max; i++) {
		infile >> data >> num >> data2;
		prim.InsertData(data, num, data2);
	}

	prim.printMST();

	cout << "\nMST : ";
	prim.Method1(0);
	prim.InitArr();
	cout << endl << "(Revised Prim's Algorithm)" << endl << "MST: ";
	prim.Method2(0);

	return 0;
}