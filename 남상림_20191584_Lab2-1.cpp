//////////////////////////////////////////////////////////////
//Lab 2 : Recursion 연습
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : Recurision 연습 lab 2-1
//Algorithm : 반복알고리즘과 순환알고리즘 이 2가지 방법으로 이진탐색하기
// Variable : 
/////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int COMPARE(int left, int right) {
    if (left > right)
        return 1;
    else if (left == right)
        return 0;
    else
        return -1;
}

int binary_search(int list[], int searchnum, int left, int right) {

    while (left <= right) {
        int middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum)) {
        case -1:
            left = middle + 1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle - 1;
            break;
        }

    }return -1;
}

int RecursiveSearch(int list[], int searchnum, int left, int right) {

    if (left <= right) {
        int middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum)) {
        case -1:
            return RecursiveSearch(list, searchnum, middle + 1, right);
        case 0:
            return middle;
        case 1:
            return RecursiveSearch(list, searchnum, left, middle - 1);
        }
    }
    return -1;
}


int main() {

    int choice = 0;
    int searchnum;
    int list[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int left, right;
    cout << "Numbers in the List : 10, 20, 30, 40, 50, 60, 70, 80, 90, 100\n";
    while (choice != 3) {
        cout << "Enter methods of search : 1. Bin-search  2.Recursive search  3.Exit    :  ";
        cin >> choice;
        if (choice == 3) break;

        cout << "Enter an integer to search  : ";
        cin >> searchnum;

        if (choice == 1) {
            int ret = binary_search(list, searchnum, 0, 9);
            if (ret == -1) {
                cout << searchnum << " is not in the list" << endl;
            }
            else {
                cout << searchnum << " is at position " << ret + 1 << endl;
            }
        }
        else if (choice == 2) {
            int ret = RecursiveSearch(list, searchnum, 0, 9);
            if (ret == -1) {
                cout << searchnum << " is not in the list" << endl;
            }
            else {
                cout << searchnum << " is at position " << ret + 1 << endl;
            }
        }
    }
}