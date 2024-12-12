#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

// Disjoint-Set (Union-Find) class
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) 
    {
        for (int i = 0; i < n; ++i) 
        parent[i] = i;
    }

    // Find the root of the set containing x
    int Amol(int x) 
    {
        if (parent[x] != x) parent[x] = Amol(parent[x]);
        return parent[x];
    }

    // Union of two sets
    void unite(int x, int y) 
    {
        int rootX = Amol(x);
        int rootY = Amol(y);
        if (rootX != rootY) 
        {
            if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else 
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Function to apply Kruskal’s Algorithm and find the MST
vector<Edge> kruskal(int n, vector<Edge>& edges) {
    DisjointSet ds(n);
    vector<Edge> mst;

    // Sort edges based on weight
    sort(edges.begin(), edges.end());

    for (const auto& edge : edges) 
    {
        if (ds.Amol(edge.u) != ds.Amol(edge.v)) 
        {
            mst.push_back(edge);
            ds.unite(edge.u, edge.v);
        }
    }
    return mst;
}

int main() {
    // Graph representation as edges list
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 15}, {0, 3, 20}, {1, 2, 35},
        {1, 4, 25}, {2, 3, 30}, {2, 4, 5}, {3, 4, 10}
    };

    int n = 5;  // Number of departments (nodes)

    // Get MST using Kruskal's algorithm
    vector<Edge> mst = kruskal(n, edges);

    // Output the MST edges and total weight
    int totalWeight = 0;
    cout << "Edges in MST:" << endl;
    for (const auto& edge : mst) {
        cout << "D" << edge.u + 1 << " - D" << edge.v + 1 << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}