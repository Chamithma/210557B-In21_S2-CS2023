#include <iostream>
#include <vector>

using namespace std;

int findMinKey(vector<int>& key, vector<bool>& mstSet) {
    int minKey = INT_MAX, minIndex;

    for (size_t v = 0; v < key.size(); ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (size_t i = 1; i < parent.size(); ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(const vector<vector<int>>& graph) {
    size_t V = graph.size();
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;         // Start with the first vertex as the root
    parent[0] = -1;     // First node is always the root of MST

    for (size_t count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (size_t v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    size_t V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix:\n";
    for (size_t i = 0; i < V; ++i) {
        for (size_t j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    primMST(graph);

    return 0;
}
