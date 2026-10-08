#include <iostream>
using namespace std;
#define INF 9999
void prim(int graph[][10], int vertices) {
    int parent[10];
    int key[10];
    bool selected[10] = {false};
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        parent[i] = -1;
    }
    key[0] = 0;
    for (int count = 0; count < vertices - 1; count++) {
        int minimum = INF;
        int current = -1;
        for (int i = 0; i < vertices; i++) {
            if (!selected[i] && key[i] < minimum) {
                minimum = key[i];
                current = i;
            }
        }
        selected[current] = true;
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] != 0 && !selected[i] && graph[current][i] < key[i]) {
                key[i] = graph[current][i];
                parent[i] = current;
            }
        }
    }
    int totalWeight = 0;
    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total weight: " << totalWeight << endl;
}
int main() {
    int vertices, edges;
    int graph[10][10] = {0};
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges with their weights:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
    prim(graph, vertices);
    return 0;
