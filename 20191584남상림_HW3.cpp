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
    int row, col, dir;
};
struct offsets {
    int vert, horiz;
};
int maze[6][6] = { 0,1,1,1,1,1,  
                              1,0,1,1,1,1,  
                              1,0,0,0,0,1, 
                              1,1,0,1,1,1,  
                              1,0,1,0,0,1,  
                              1,1,1,1,1,0 
};
int mark[6][6] = { 0,};

int top = -1;
int maxSize = 10;
element stack[10];

element isEmpty() {
    element position;
    position = { -1, -1, -1 };
    cout << "Stack is Empty" << endl;
}
void isFull() {
    cout << "Stack is Full" << endl;
}
void push(element position) {
    if (top >= maxSize)
        isFull();
    stack[++top] = position;
}
element pop(int *top) {
    if (*top == -1)
        return isEmpty();
    return stack[(*top)--];
}

void miroPath(offsets move[]) {
    bool found = false;
    element position;

    mark[0][0] = 1;
    stack[0] = { 1, 1, 1 };

    int row, col, dir;
    int next_row, next_col;
    int exit_row = 5, exit_col = 5;

    while (!isEmpty && !found) {
        position = pop(&top);
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found) {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if (next_row == exit_row && next_col == exit_col)
                found = true;
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
                mark[next_row][next_col] = 1;
                position = { row, col, ++dir };
                push(position);
                row = next_row; col = next_col; dir = 0;
            }
            else
                ++dir;
         }
     }
    if (found) {
        //miroPath 출력
        cout << "The path is : " << endl;
       
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
        cout << "The maze does not have a path. \n" << endl;
    
}
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
