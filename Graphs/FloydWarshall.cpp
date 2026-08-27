#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        int INF = 1e8;

        // Convert -1 to INF
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == -1) {
                    dist[i][j] = INF;
                }
            }
        }

        // Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][via] != INF &&
                        dist[via][j] != INF) {

                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][via] + dist[via][j]
                        );
                    }
                }
            }
        }

        // Convert INF back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) {
                    dist[i][j] = -1;
                }
            }
        }
    }
};


int main() {
    Solution obj;

    vector<vector<int>> dist = {
        {0, 2, -1, -1},
        {1, 0, 3, -1},
        {-1, -1, 0, 4},
        {-1, -1, -1, 0}
    };

    obj.floydWarshall(dist);

    cout << "Shortest Distance Matrix:" << endl;

    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist[i].size(); j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}