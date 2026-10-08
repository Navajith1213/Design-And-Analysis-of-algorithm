#include <iostream>
using namespace std;

const int MAXV = 100, MAXE = 1000;
const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

class Graph {
    int V, E;
    Edge edges[MAXE];

public:
    Graph() { V = 0; E = 0; }

    void create() {
        int e;
        cout << "Enter number of vertices: ";
        cin >> V;
        if (V <= 0 || V > MAXV) {
            V = 0;
            cout << "Invalid number of vertices.\n";
            return;
        }
        cout << "Enter number of edges: ";
        cin >> e;
        E = 0;
        cout << "Enter directed edges (u v w):\n";
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (u < 0 || v < 0 || u >= V || v >= V) {
                cout << "Invalid edge ignored.\n";
                continue;
            }
            if (E == MAXE) {
                cout << "Edge limit reached; edge ignored.\n";
                continue;
            }
            edges[E].u = u;
            edges[E].v = v;
            edges[E].w = w;
            E++;
        }
        cout << "Graph created.\n";
    }

    void display() {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        cout << "Edges (u v w):\n";
        for (int i = 0; i < E; i++)
            cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << "\n";
    }

    void bellmanFord(int src) {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        if (src < 0 || src >= V) {
            cout << "Invalid source vertex.\n";
            return;
        }
        int dist[MAXV];
        for (int i = 0; i < V; i++) dist[i] = INF;
        dist[src] = 0;
        for (int i = 1; i < V; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].u, v = edges[j].v, w = edges[j].w;
                if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            }
        }
        for (int j = 0; j < E; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                cout << "Negative weight cycle detected.\n";
                return;
            }
        }
        cout << "Shortest distances from vertex " << src << ":\n";
        for (int v = 0; v < V; v++) {
            cout << v << " : ";
            if (dist[v] == INF) cout << "INF (unreachable)\n";
            else cout << dist[v] << "\n";
        }
    }
};

int main() {
    Graph g;
    int choice, src;
    while (true) {
        cout << "\nMenu:\n1. Create graph\n2. Display edges\n";
        cout << "3. Bellman-Ford shortest path\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1: g.create(); break;
            case 2: g.display(); break;
            case 3:
                cout << "Enter source vertex: ";
                cin >> src;
                g.bellmanFord(src);
                break;
            case 4: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}