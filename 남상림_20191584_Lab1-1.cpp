//////////////////////////////////////////////////////////////
//Lab 1 : File IO Exercise
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : basic Exercise1-1
//Algorithm : 파일 내용읽고 줄마다의 단어 수 세기, 총 단어수로 출력하기
// Variable : buffur[] , line 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int WordCount(string buffer) {
    int i = 0, IN = 1, OUT = 0;
    int state = OUT;
    int wc = 0;

    while (buffer[i] != '\0') { //다음 읽을 줄이 없을때까지 반복하기
        if (isalpha(buffer[i])) { //만난 단어가 영문인지 확인하고
            if (state == OUT) {   
                ++wc; 
                //단어를 만나면 갯수 +1 하기
                 state = IN; 
            }
        }
        else if (buffer[i] == ' ')
            state = OUT;
        i++;
    }return wc; // 센 단어의 개수 리턴
}

int main() {

    ifstream infile;

    char buffer[999];
    int wc = 0;
    int total = 0;
    infile.open("lab1-1.dat"); 

    while (infile.getline(buffer, 999)) {
        cout << buffer << endl;
        total = WordCount(buffer);
        cout << "The number of words : " << total << endl;
        wc = wc + total;
    }
    cout << "Total Number of Words : " << wc << endl;

    infile.close(); //한 번 연 파일은 다시 닫아 주어야한다
    return 0;
}

