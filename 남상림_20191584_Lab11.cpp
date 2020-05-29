#include <iostream>

using namespace std;

const int max = 6;
const int row = 6;
const int col = 6;


int GRAPH[row][col] = {
    //        0, 1, 1, 0, 0, 0, 0, 0, 
    //        1, 0, 0, 1, 1, 0, 0, 0, 
    //        1, 0, 0, 0, 0, 1, 1, 0, 
    //        0, 1, 0, 0, 0, 0, 0, 1, 
    //        0, 1, 0, 0, 0, 0, 0, 1, 
    //        0, 0, 1, 0, 0, 0, 0, 1, 
    //        0, 0, 0, 1, 1, 1, 1, 1, 
    //        0, 0, 0, 1, 1, 1, 1, 0

            0, 1, 1, 0, 0, 0,
            1, 0, 1, 1, 0, 0,
            1, 1, 0, 0, 0, 1,
            0, 1, 0, 0, 1, 1,
            0, 0, 0, 1, 0, 1,
            0, 0, 1, 1, 1, 0
};


class Node {
private:
    int data;
    Node *link;
public:
    Node(int num) : data(num), link(NULL){}
    friend class Graph;
};

class Graph {
private:
    Node *graph[max];
    Node *front;
    Node *rear;
    char visited[max];
public:
    Graph() : front(NULL), rear(NULL) {}
    void init_Graph();
    void insertGraph();
    void PrintGraph();
    void Enque(int v);
    int Deque();
    void bfs(int v);
};

void Graph::init_Graph() {
    for (int i = 0; i < max; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }
}

void Graph::Enque(int v) {
    Node *tmp = new Node(v);
    if (front != NULL) {
        rear->link = tmp;
        rear = tmp;
    } else {
        front = tmp;
        rear = tmp;
    }
}

int Graph::Deque() {
    Node *w;
    int v;
    w = front;
    front = w->link;
    v = w->data;
    delete (w);
    return v;
}

void Graph::insertGraph() {
    int R, C;
    for (int i = 0; i < row; i++) {
        for (int j = i; j < col; j++) {
            if (GRAPH[i][j] == 1) {
                R = i;
                C = j;
                if (graph[R] == NULL) {
                    Node *Rtemp = new Node(R);
                    graph[R] = Rtemp;
                }
                if (graph[C] == NULL) {
                    Node *Ctemp = new Node(C);
                    graph[C] = Ctemp;
                }

                Node *p = graph[R];
                Node *tmp1 = new Node(C);

                while (p->link != NULL) p = p->link;
                p->link = tmp1;

                GRAPH[graph[R]->data][tmp1->data] = 1;

                p = graph[C];
                Node *tmp2 = new Node(R);

                while (p->link != NULL) p = p->link;
                p->link = tmp2;

                GRAPH[graph[C]->data][tmp2->data] = 1;
            }
        }
    }
}

void Graph::PrintGraph() {
    cout << "    ";
    for (int i = 0; i < max; i++)
        cout << "v" << i << " ";
    cout << endl;
    for (int i = 0; i < row; ++i) {
        cout << "v" << i << "  ";
        for (int j = 0; j < col; ++j)
            cout << GRAPH[i][j] << "  ";
        cout << endl;;
    }
}

void Graph::bfs(int v) {
    Enque(v);
    visited[v] = 1;

    while (front) {
        int v = Deque();
        cout << v << " ";
        for (int w = GRAPH[v][v]; w < max; w++) {
            if ((GRAPH[v][w] != 0) && visited[w] != 1) {
                Enque(w);
                visited[w] = 1;
            }
        }
    }
}

int main() {
    Graph graph;
    graph.init_Graph(); 
    graph.insertGraph();
    cout << "--------------ADJACENCY GRAPH--------------" << endl;
    cout << endl;
    graph.PrintGraph();
    cout << endl;
    cout << "BFS  : ";
    graph.bfs(0);
    cout << endl;
    return 0;
}