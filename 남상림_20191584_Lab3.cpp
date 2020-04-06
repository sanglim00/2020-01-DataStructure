//////////////////////////////////////////////////////////////
//Lab 3 : magic square
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : magic square
//Algorithm : 배열
// Variable : square[], square2[] - 숫자 담을 배열 두 개
/////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int num;
int square[99][99]; 
int square2[99][99];
int k, l;

void magic_square_left() {

	int row, col;
	int key = 2;
	int i = 0; 
	int j = num / 2;
	square[i][j] = 1;

	//왼쪽 위로 이동하기
	while (key <= num * num) {
		if (i - 1 < 0)
			row = num - 1;
		else
			row = i - 1;
		if (j - 1 < 0)
			col = num - 1;
		else
			col = j - 1;
		if (square[row][col])
			i = (i + 1) % num;
		else {
			i = row;
			j = col;
		}
		square[i][j] = key++;
	}
}

void magic_square_right() {
	int row, col;
	int key = 2;
	int i = 0;
	int j = num / 2;
	square2[i][j] = 1;

	//오른쪽 위로 이동하기
	while (key <= num * num) {
		if (i - 1 < 0)
			row = num - 1;
		else
			row = i - 1;
		if (j +1 >=num)
			col = 0;
		else
			col = j + 1;
		if (square2[row][col])
			i = (i + 1) % num;
		else {
			i = row;
			j = col;
		}
		square2[i][j] = key++;
	}
}

int main() {

	cout << "Enter number of square : " ;
	cin >> num;

	cout << "Magic square size is : " << num << endl;
	magic_square_left();
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << square[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Magic square size is : " << num << endl;
	magic_square_right();
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << square2[i][j] << " ";
		}
		cout << endl;
	}
}