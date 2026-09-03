#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <cmath>

using namespace std;

class Solution {
public:
    // {distance, node}
    typedef pair<int, int> P;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        // Min-heap: smallest distance first
        priority_queue<P, vector<P>, greater<P>> pq;

        // Track nodes already included in MST
        vector<int> inMST(V, false);

        // Start from node 0 with cost 0
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            // Skip if node is already in MST
            if (inMST[node])
                continue;

            // Add node and its edge cost to MST
            sum += dist;
            inMST[node] = true;

            // Check distance from current node to every other node
            for (int i = 0; i < V; i++) {
                if (i == node || inMST[i])
                    continue;

                // Manhattan distance
                int newDist = abs(points[node][0] - points[i][0]) +
                              abs(points[node][1] - points[i][1]);

                // Add edge to min-heap
                pq.push({newDist, i});
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << "Minimum Cost = "
         << sol.minCostConnectPoints(points)
         << endl;

    return 0;
}