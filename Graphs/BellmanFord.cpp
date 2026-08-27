#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(
        int V,
        vector<vector<int>>& edges,
        int src
    ) {
        const int INF = 1e8;

        // result[i] = shortest distance from src to i
        vector<int> result(V, INF);

        result[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= V - 1; i++) {

            for (auto& edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                // u should be reachable
                if (result[u] != INF &&
                    result[u] + weight < result[v]) {

                    result[v] = result[u] + weight;
                }
            }
        }

        // Check for negative cycle
        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (result[u] != INF &&
                result[u] + weight < result[v]) {

                return {-1};
            }
        }

        return result;
    }
};


int main() {
    Solution obj;

    int V = 5;
    int src = 0;

    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    vector<int> answer =
        obj.bellmanFord(V, edges, src);

    if (answer.size() == 1 && answer[0] == -1) {
        cout << "Negative cycle exists" << endl;
    } else {
        cout << "Shortest distances: ";

        for (int distance : answer) {
            cout << distance << " ";
        }

        cout << endl;
    }

    return 0;
}