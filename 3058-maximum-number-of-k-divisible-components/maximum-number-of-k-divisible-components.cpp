class Solution {
public:
    int c = 0;
    long long int solve(vector<vector<long long int>>& adj, vector<int>& values, int k, int root,
              int parent) {
        long long int rest_sum = values[root];

        for (int child : adj[root]) {
            if (child != parent) {
                long long sum = solve(adj, values, k, child,root);
                if (sum % k == 0) {
                    c++;
                } else {
                    rest_sum += sum;
                }
            }
        }
        return rest_sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<long long int>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // if graph is undirected
        }

        solve(adj, values, k, 0, -1);
        return c+1;
    }
};