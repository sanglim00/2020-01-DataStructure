/*********************************************
 HomeWork : HW3
 Name : Nam Sang Lim
 ID : 20191584
 Program Description : 
Algorithm :
 Variable :
**********************************************/

#include <iostream>

using namespace std;

struct element {
    int row;
    int col;
    int dir;
};
struct offsets {
    int vert;
    int horiz;
};
int top = -1;
int size = 10;

element stack[36];
offsets move[8];
int exit_row = 5, exit_col = 5;

void Move(offsets move[]) {
    move[0].vert = -1; move[0].horiz = 0;   // N     
    move[1].vert=-1; move[1].horiz=1;   // NE 
    move[2].vert=0; move[2].horiz=1;    // E     
    move[3].vert=1; move[3].horiz=1;    // SE   
    move[4].vert=1; move[4].horiz=0;    // S     
    move[5].vert=1; move[5].horiz=-1;   // SW 
    move[6].vert=0; move[6].horiz=-1;   // W     
    move[7].vert=-1; move[7].horiz=-1;  // NW 
}

void push(int val) {
    if (!isFull())
        stack[++top] = val;
    else
        cout << "Stack is Full" << endl;
}
int pop() {
    if (!isEmpty())
        return stack[top--];
    else
        cout << "Stack is Empty" << endl;
}
bool isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}
bool isFull() {
    if (top == size - 1)
        return true;
    else
        return false;
}

int maze[6][6] = { 0,1,1,1,1,1, 
                              1,0,1,1,1,1,  
                              1,0,0,0,0,1,  
                              1,1,0,1,1,1,  
                              1,0,1,0,0,1,  
                              1,1,1,1,1,0 
};
int mark[6][6] = {0,};

void miroPath() {
    int i, j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (maze[i][j] == 0)
                mark[i][j] = 1;
        }
    }

    bool found = false;
    element position;
    mark[0][0] = 1;
    int top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 1;
    int next_row, next_col;
    int row, col, dir;
  
    while (!isEmpty() && !found) {
        position = delete(&top);
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found) {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if (next_row = exit_row && next_col == exit_col)
                found = true;
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;

                push(position.dir);
                row = next_row;
                col = next_col;
                dir = 0;
            }
            else
                ++dir;
         }
     }
    if (found) {
        //미로 경로 출력
        //방문된 matrix 출력
    }
    else
        cout << "The maze does not have a path" << endl;
}


int main() {
    miroPath();
}