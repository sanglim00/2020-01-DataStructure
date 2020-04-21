//Main Heading
/*********************************************
 HomeWork : HW3
 Name : Nam Sang Lim
 ID : 20191584
 Program Description : Homework 3  Maze Problem 
Algorithm : 주어진 2차원 배열 maze의 0,0에서 시작하여 마지막 점 5, 5까지 0인 부분을 찾아 미로를 나가는 알고리즘
                    8개의 방향을 돌면서 갈 수 있는 방향을 가보면서 길을 찾는다. 통과한 길의 row,col,dir을 stack에 쌓고 마지막에 출력한다.
                    mark에는 지나간 길을 표시하고 나중에 출력한다.
                    exit_row와 exit_col에 도착하면 스택 내용물을 출력하고 아니면 길이 없다는 메세지를 출력한다.
 Variable : maze - 나가야 하는 미로가 담긴 배열
                 mark - 미로를 나가는 길을 표시한 배열
                 move - 중심을 기준으로 8개의 방위를 담고있는 배열
                 stack - 지나간 길들의 row, col, dir을 담는 스택
                 element - row,col,dir을 가지고 있는 구조체
                 offsets - vert, horiz를 가지고 있는 구조체
**********************************************/

#include <iostream>

using namespace std;

struct element {        //element 구조체 선언
    int row, col, dir;
};
struct offsets {            //offsets 구조체 선언
    int vert, horiz;
};
int maze[6][6] = { 0,1,1,1,1,1,             //미로를 담고 있는 배열
                              1,0,1,1,1,1,  
                              1,0,0,0,0,1, 
                              1,1,0,1,1,1,  
                              1,0,1,0,0,1,  
                              1,1,1,1,1,0 
};
int mark[6][6] = { 0,};                         //미로를 나가는 길을 기록할 배열

int maxSize = 100;
element stack[100];                         //element 타입의 stack 선언

element isEmpty();
void isFull();
void push(int *top, element position);
element pop(int* top);
void miroPath(offsets move[]);

int main() {
    offsets move[8];

    move[0].vert = -1; move[0].horiz = 0;   // N    
    move[1].vert = -1; move[1].horiz = 1;   // NE 
    move[2].vert = 0; move[2].horiz = 1;    // E     
    move[3].vert = 1; move[3].horiz = 1;    // SE   
    move[4].vert = 1; move[4].horiz = 0;    // S     
    move[5].vert = 1; move[5].horiz = -1;   // SW 
    move[6].vert = 0; move[6].horiz = -1;   // W     
    move[7].vert = -1; move[7].horiz = -1;  // NW 

    miroPath(move);
}
//Sub Heading
/****************************************************
function : isEmpty
description : 이 함수는 스택이 비었음을 알려주는 함수이다
variables : position은 element 타입이고 {-1,-1,-1}의 값을 가진다.
****************************************************/
element isEmpty() {
    element position;
    position = { -1, -1, -1 };
    cout << "Stack is Empty" << endl;
    return position;
}
//Sub Heading
/****************************************************
function : isFull
description : 이 함수는 스택이 가득 찼음을 알려주는 함수이다.
****************************************************/
void isFull() {
    cout << "Stack is Full" << endl;
}
//Sub Heading
/****************************************************
function : push
description : 이 함수는 스택에 값을 넣어주는 함수이다.
variables : top - 스택의 인덱스를 가리키는 값
                 position - stack에 넣어줄 값을 가지는 매개변수
****************************************************/
void push(int* top, element position) {
    if (*top >= maxSize)
        isFull();
    stack[++(*top)] = position;
}
//Sub Heading
/****************************************************
function : pop
description : 이 함수는 스택의 젤 위의 값을 리턴해주는 함수이다.
variables : top - stack의 인덱스를 가리킨다.
****************************************************/
element pop(int* top) {
    if (*top == -1)
        return isEmpty();
    return stack[(*top)--];
}
//Sub Heading
/****************************************************
function : miroPath
description : 이 함수는 미로의 경로를 탐색하는 함수이다.
variables : move[] - 8개의 방향을 가지고 있는 배열이다 (메인에 정의되어 있다.)
                found - exit_row,와 exit_col과 만났는지의 여부를 저장하는 bool형 변수
                top - stack의 인덱스를 가리킨다.
                row, col, dir - 현재위치를 담고 있다.
                next_row,next_col, next_dir = 다음 위치를 담는 변수
                 exit_col, exit_row - 최종 목적지를 담고 있는 변수
****************************************************/
void miroPath(offsets move[]) {
    bool found = false;         //길을 찾았는지 여부를 저장하는 변수 false로 시작한다.
    element position;

    int top = 0;
    mark[0][0] = 1;                 //0,0에서 시작한다 - 1로 표시
    stack[0] = { 0, 0, 0 };      

    int row, col, dir;
    int next_row, next_col;
    int exit_row = 5, exit_col = 5;         //최종 도달해야할 행과 열

    while (top >-1 && !found) {
        position = pop(&top);               
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found) {         //8방향 다 돌기 전까지 반복
            //다음 이동 좌표를 계산한다.
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if (next_row == exit_row && next_col == exit_col) {         //만약 최종 행렬과 다음 행렬이 일치하면
                mark[next_row][next_col] = 1;                                       //표시하고
                position = { row, col, ++dir };                                         //지금 위치를 저장해서
                push(&top, position);                                                      //stack에 push한다
                row = next_row;
                col = next_col;
                found = true;                                           //길을 찾았다고 저장한다.
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
                mark[next_row][next_col] = 1;
                position = { row, col, ++dir };
                push(&top, position);           //현재위치를 저장한다.
                row = next_row; 
                col = next_col;
                dir = 0;
            }
            else
                ++dir;          
         }
     }
    if (found) {        //길을 찾았다면
        //miroPath 출력
        cout << "The path is : " << endl;
        cout << "row\tcol" << endl;
        for (int i = 0; i <= top; i++)
            cout << stack[i].row << "\t" << stack[i].col << endl;
        cout << exit_row << "\t" << exit_col << endl;

        //marked matrix 출력
        cout << "Marked Matrix : " << endl;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cout << mark[i][j];
            }
            cout << endl;
        }
    }
    else
        // 미로의 경로가 없을 경우(탈출 못하면) 출력하는 문장
        cout << "The maze does not have a path. \n" << endl;

}
