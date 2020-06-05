#include <iostream>

using namespace std;

int costArr[6][6] = { 100, 6, 1, 5 ,100, 100,
                                6, 100, 4, 100, 3, 100,
                                1, 4, 100, 5, 6, 5,
                                5, 100, 5, 100, 100, 2,
                                100, 3, 6, 100, 100, 6,
                                100, 100, 5, 2, 6, 100 
};

int visited[6];
int graphT[6];
int cnt = 0, num = 0, index = 0;
int totalCost = 0;
int tmp, check;

void InitArr() {
    for (int i = 0; i < 6; i++) {
        visited[i] = 0;
        graphT[i] = 0;
    }
}

void PrintGraph() {
    visited[0] = 1;

    for(cnt; cnt<5; cnt++) {
        tmp = 100;
        for (int i = 0; i < 6; i++) {
            if (costArr[num][i] != 0 && costArr[num][i] < tmp && visited[i] == 0) {
                tmp = costArr[num][i];
                check = i;
            }
        }
        if (tmp == 100) {
            cout << "No Spanning Tree" << endl;
            break;
        }
        else {
            visited[check] = 1;
            graphT[++index] = check;
            num = check;
            totalCost += tmp;
        }
    }
    cout << "       <<     Weighted Graph     >>\n\n";
    cout << "\t";

    for (int i = 0; i < 6; i++) cout << "V" << i + 1 << "\t";
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << "V" << i + 1 << "\t";
        for (int j = 0; j < 6; j++)  cout << costArr[i][j] << "\t";
        cout << endl;
    }
}
void PrintMST() {
    cout << "\n       <<     Minimal Spanning Tree     >>\n\n" ;
    for (int i = 0; i < 5; i++) {
        if(i < 4)
            cout  << graphT[i] + 1 << ", " << graphT[i + 1] + 1<<"  → " ;

        else        // 마지막은 화살표 출력 안하려고
            cout  << graphT[i] + 1 << ", " << graphT[i + 1] + 1 ;
    }
}

int main() {
    
    InitArr();  //초기화
    PrintGraph();   //1)
    PrintMST();      //2)
    cout << " ( Total Weight  : " << totalCost<<" )"<<endl;

    return 0;
}