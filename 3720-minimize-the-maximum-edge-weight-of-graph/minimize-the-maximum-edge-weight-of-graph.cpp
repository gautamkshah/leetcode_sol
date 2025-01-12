vector<pair<int,int>>adj[(int) 1e5];
vector<bool>vis;
int dfs(int node, int m){
     vis[node] = 1;
     int ret = 1;
     for(auto [a,b] : adj[node])
          if(!vis[a] && b <= m)ret += dfs(a, m);

     return ret;
}
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        for(int i = 0; i < n; i++)adj[i].clear();
        for(auto i : edges)
            adj[i[1]].push_back({i[0], i[2]});
        
        int l = 1 ,r = 1e6, m;
        while(l <= r){
            m = (l + r) >> 1;
            vis = vector<bool>(n);
            (dfs(0, m) != n ? l = m + 1 : r = m - 1);
        }
        return (l == 1e6 + 1 ? -1 : l);
    }
};
