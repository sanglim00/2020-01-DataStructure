//////////////////////////////////////////////////////////////
//HomeWork : HW1
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : Hw1- Array Exercise
//Algorithm : 
// Variable : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {

	int num = 0;
	int Narray[6][6];
	ifstream infile;

	infile.open("hw1.txt");

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {

			infile >> num;
			Narray[i][j] = num;
		}
	}

	cout << "1) Original Matrix : A" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << Narray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "2) Transpose of original Matrix A" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << Narray[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "3) Sparse matrix of A -row major" << endl;

	list<int> RClist;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (Narray[i][j] != 0) {
				RClist.push_back(i);
				RClist.push_back(j);
				RClist.push_back(Narray[i][j]);
			}
		}
	}
	int RCarray[8][3];
	int E = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			RCarray[i][j] = RClist.front();
			RClist.pop_front();
			E++;
 		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			cout << RCarray[i][j] << " ";
		}
		cout << endl;
	}
}
