#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    // {weight, node}
    typedef pair<int, int> P;

    int spanningTree(int V, vector<vector<int>>& edges) {

        // Step 1: Create adjacency list
        // adj[u] = {v, weight}
        vector<vector<P>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Undirected graph
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min Heap: stores {weight, node}
        // Always gives the minimum weight edge first
        priority_queue<P, vector<P>, greater<P>> pq;

        // Marks nodes already included in MST
        vector<bool> inMST(V, false);

        int sum = 0;

        // Start from node 0 with weight 0
        pq.push({0, 0});

        while (!pq.empty()) {

            // Get minimum weight edge
            auto [wt, node] = pq.top();
            pq.pop();

            // Ignore if node is already in MST
            if (inMST[node])
                continue;

            // Add node to MST
            inMST[node] = true;

            // Add the edge weight to MST cost
            sum += wt;

            // Add all possible edges to neighbouring nodes
            for (auto [v, newWt] : adj[node]) {

                // Only consider nodes not yet in MST
                if (!inMST[v]) {
                    pq.push({newWt, v});
                }
            }
        }

        return sum;
    }
};


// Driver Code
int main() {

    Solution obj;

    int V = 5;

    // {source, destination, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int answer = obj.spanningTree(V, edges);

    cout << "Minimum Spanning Tree Weight = "
         << answer << endl;

    return 0;
} 