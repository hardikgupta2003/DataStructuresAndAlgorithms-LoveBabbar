//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <cmath>using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool cycleCheckDirectedDFS(int src, vector<vector<int>> adj,
                               unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsTrack)
    {
        visited[src] = true;
        dfsTrack[src] = true;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool ans = cycleCheckDirectedDFS(nbr, adj, visited, dfsTrack);
                if (ans)
                    return true;
            }
            if (visited[nbr] == 1 && dfsTrack[nbr] == 1)
            {
                // cycle present
                return true;
            }
        }
        // backtrack- imp step
        dfsTrack[src] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTrack;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool isCyclic = cycleCheckDirectedDFS(i, adj, visited, dfsTrack);
                if (isCyclic == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends