#include <iostream>
using namespace std;

const int MAXV = 100, MAXE = 1000;

struct Edge {
    int u, v, w;
};

class Graph {
    int V, E;
    Edge edges[MAXE];

    int find(int parent[], int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    // simple insertion sort on edge weights (stable)
    void sortEdges(Edge e[], int m) {
        for (int i = 1; i < m; i++) {
            Edge key = e[i];
            int j = i - 1;
            while (j >= 0 && e[j].w > key.w) {
                e[j + 1] = e[j];
                j--;
            }
            e[j + 1] = key;
        }
    }

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
        cout << "Enter edges (u v w):\n";
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

    void kruskal() {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        Edge sorted[MAXE], mst[MAXV];
        for (int i = 0; i < E; i++) sorted[i] = edges[i];
        sortEdges(sorted, E);
        int parent[MAXV], rnk[MAXV];
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rnk[i] = 0;
        }
        int count = 0, total = 0;
        for (int i = 0; i < E && count < V - 1; i++) {
            int a = find(parent, sorted[i].u), b = find(parent, sorted[i].v);
            if (a != b) {
                if (rnk[a] < rnk[b]) swap(a, b);
                parent[b] = a;
                if (rnk[a] == rnk[b]) rnk[a]++;
                mst[count++] = sorted[i];
                total += sorted[i].w;
            }
        }
        if (count != V - 1) {
            cout << "Graph is disconnected; MST not possible.\n";
            return;
        }
        cout << "Edges in the MST (Kruskal):\n";
        for (int i = 0; i < count; i++)
            cout << mst[i].u << " - " << mst[i].v << " : " << mst[i].w << "\n";
        cout << "Total weight of MST: " << total << "\n";
    }
};

int main() {
    Graph g;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Create graph\n2. Display edges\n";
        cout << "3. Kruskal's MST\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1: g.create(); break;
            case 2: g.display(); break;
            case 3: g.kruskal(); break;
            case 4: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}