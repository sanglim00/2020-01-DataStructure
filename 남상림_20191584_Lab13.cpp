#include <iostream>

using namespace std;
const int numOfVertex = 6;

int Lab13_input[numOfVertex][numOfVertex] = { 100, 20, 15, 100, 100, 100,
                                              100 ,100, 100, 100, 10, 30,
                                              100 ,4 ,100, 100, 100 ,10,
                                              100, 100 ,100 ,100, 100 ,100,
                                              100 ,100, 100 ,15 ,100, 100,
                                              100 ,100, 100 ,4 ,10, 100

};
int Lab13_input2[numOfVertex][numOfVertex] = { 100, 50, 10 ,100, 45 ,100,
                                              100 ,100 ,15 ,100 ,10, 100,
                                              20, 100 ,100 ,15 ,100, 100,
                                              100, 20, 100, 100, 35, 100,
                                              100, 100, 100, 30, 100, 100,
                                              100, 100 ,100, 3, 100 ,100
};

class ShortestPath {
private:
    bool* found;
    int* distance;
    int** cost;
    int Max;
public:
    ShortestPath();
    //첫 번째 데이터 
    void InitCostMatrix();
    void Shortest_Path(int);
    int Choose(int*, int, bool*);
    //두 번째 데이터
    void InitCostMatrix2();
    void Shortest_Path2(int);
    int Choose2(int*, int, bool*);
    void PrintDistance();
    void PrintCostMatrix();
    
};
ShortestPath::ShortestPath() {
    found = new bool[100];
    distance = new int[100];
}
void ShortestPath::InitCostMatrix() {
    Max = 999;

    cost = new int* [numOfVertex];
    for (int i = 0; i < numOfVertex; i++) {
        cost[i] = new int[numOfVertex];
        for (int j = 0; j < numOfVertex; j++) {
            cost[i][j] = Lab13_input[i][j];             //첫 번째 데이터
            if (cost[i][j] == 100) cost[i][j] = Max;
        }
    }
}
void ShortestPath::InitCostMatrix2() {
    Max = 999;
    cost = new int* [numOfVertex];
    for (int i = 0; i < numOfVertex; i++) {
        cost[i] = new int[numOfVertex];
        for (int j = 0; j < numOfVertex; j++) {
            cost[i][j] = Lab13_input2[i][j];           //두 번째 데이터
            if (cost[i][j] == 100) cost[i][j] = Max;
        }
    }
}

void ShortestPath::Shortest_Path(int start) {
    int i, u, w;
    for (i = 0; i < numOfVertex; i++) {
        found[i] = false;
        distance[i] = cost[start][i];
    }

    found[start] = true;
    distance[start] = 0;

    cout << "\t  ***** Shortest Path *****\n\n";
    cout << "Start From Vertex : 0";
    for (i = 0; i < numOfVertex; i++) {
        cout << "\t\tDistance -> ";
        PrintDistance();

        u = Choose(distance, numOfVertex, found);
        found[u] = true;
        if (i != numOfVertex - 1) cout << "\nSelect Node : " << u;

        for (w = 0; w < numOfVertex; w++) {
            if (!found[w]) {
                if (distance[u] + cost[u][w] < distance[w])
                    distance[w] = distance[u] + cost[u][w];
            }
        }
    }
    cout << endl;
}
void ShortestPath::Shortest_Path2(int start) {
    int i, u, w;
    for (i = 0; i < numOfVertex; i++) {
        found[i] = false;
        distance[i] = cost[start][i];
    }

    found[start] = true;
    distance[start] = 0;

    cout << "\t  ***** Shortest Path *****\n\n";
    cout << "Start From Vertex : 0";
    for (i = 0; i < numOfVertex; i++) {
        cout << "\t\tDistance -> ";
        PrintDistance();

        u = Choose2(distance, numOfVertex, found);
        found[u] = true;
        if (i != numOfVertex - 1) cout << "\nSelect Node : " << u;

        for (w = 0; w < numOfVertex; w++) {
            if (!found[w]) {
                if (distance[u] + cost[u][w] < distance[w])
                    distance[w] = distance[u] + cost[u][w];
            }
        }
    }
    cout << endl;
}
void ShortestPath::PrintDistance() {
    for (int i = 0; i < numOfVertex; i++) cout << distance[i] << " ";
}
void ShortestPath::PrintCostMatrix() {
    cout << "\t   ***** Adjacency Matrix *****\n";
    for (int i = 0; i < numOfVertex; i++) {
        cout << endl;
        for (int j = 0; j < numOfVertex; j++)  cout << cost[i][j] << "\t";
    }
    cout << endl << endl;
}
int ShortestPath::Choose(int* distance, int n, bool* found) {
    int min, minNode = 0;
    min = Max;
    for (int i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minNode = i;
        }
    }
    return minNode;
}
int ShortestPath::Choose2(int* distance, int n, bool* found) {
    int min, minNode = 0;
    min = Max;
    for (int i = 0; i < n; i++) {
        if (distance[i] <= min && !found[i]) {
            min = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

int main() {
    ShortestPath SP, SP2;

    SP.InitCostMatrix();
    SP.PrintCostMatrix();
    SP.Shortest_Path(0);   //시작 정점 0

    cout << endl;
    SP2.InitCostMatrix2();
    SP2.PrintCostMatrix();
    SP2.Shortest_Path2(0);   //시작 정점 0

}
