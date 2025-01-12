#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> adj[(int)1e5];
vector<bool> vis;

void dfs(int node, int m) {
    vis[node] = true;
    for (auto [a, b] : adj[node]) {
        if (!vis[a] && b <= m) {
            dfs(a, m);
        }
    }
}

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        for (int i = 0; i < n; i++) adj[i].clear();
        for (auto& edge : edges) {
            adj[edge[1]].emplace_back(edge[0], edge[2]); // Reverse graph for reachability to node 0
        }

        int l = 1, r = 1e6, m;
        while (l <= r) {
            m = (l + r) >> 1;

            vis = vector<bool>(n, false); // Reset the visited array for each mid value
            dfs(0, m); // Perform DFS starting from node 0

            // Check if all nodes are visited
            bool allVisited = true;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    allVisited = false;
                    break;
                }
            }

            if (allVisited) {
                r = m - 1; // Try to minimize the maximum edge weight
            } else {
                l = m + 1; // Increase the weight limit
            }
        }

        return (l > 1e6 ? -1 : l);
    }
};
