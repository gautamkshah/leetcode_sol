class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int i, int j, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1 && j == m - 1) {
            if (grid[i][j] == 0) return 0;
            else if (k == 0) return -100000;
            else return grid[i][j];
        }
        if (i >= n || j >= m) return -100000;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int ans = -500000;
        if (grid[i][j] == 0)
            ans = max(solve(grid, i + 1, j, k), solve(grid, i, j + 1, k));
        if (grid[i][j] != 0 && k > 0)
            ans = max({grid[i][j] + solve(grid, i + 1, j, k - 1),
                       grid[i][j] + solve(grid, i, j + 1, k - 1)});
        return dp[i][j][k] = ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int ans = solve(grid, 0, 0, k);
        return ans < 0 ? -1 : ans;
    }
};
