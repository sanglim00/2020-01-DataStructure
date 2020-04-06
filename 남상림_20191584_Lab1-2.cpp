//////////////////////////////////////////////////////////////
//Lab 1 : File IO Exercise
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : basic Exercise1-2
//Algorithm : 파일을 읽고 최대값과 최소값 그리고 그 위치를 찾기
// Variable : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

// 배열에서 가장 작은 값을 찾아 반환하여 주는 함수
int findMin(int data[], int n) {
    int min = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min) {
            min = i;
        }
    }return min;
}

// 배열에서 가장 큰 값을 찾아 반환하여 주는 함수
int findMax(int data[], int n) {
    int max = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            max = i;
        }
    }
    return max;
}
int main() {
    int number, count = 0,  data[10];

    ifstream inFile("numberFile.txt");

    // 파일을 읽고 그 값들을 배열에 저장하는 반복문
    while (inFile >> number) {
        data[count++] = number;
    }

    int minnum = findMin(data, count); // 가장 작은 값을 찾는 함수에서 반환된 값을 minnum에 저장
    int maxnum = findMax(data, count); //가장 큰 값을 찾는 함수에서 반환된 값을 maxnum에 저장

    // 위 두 문장은 출력을 하는 문장이다. 수와 그 수의 위치를 출력한다.
    // 참고로 인덱스는 0부터 시작하기 때문에 위치를 잘 확인하여야 한다.
    cout << "Minimun number is " << data[minnum] << "at position " << minnum << endl;
    cout << "Maximum number is " << data[maxnum] << "at position " << maxnum << endl;
}