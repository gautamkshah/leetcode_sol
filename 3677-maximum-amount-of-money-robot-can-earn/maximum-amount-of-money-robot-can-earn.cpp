class Solution {
public:
    int dp[501][501][3];
    int solve(vector<vector<int>>& coins, int i, int j, int k = 0) {
        int n = coins.size();
        int m = coins[0].size();
       
        if (i == n - 1 && j == m-1) {
            if (coins[i][j] < 0 && k <= 1) {
                return 0;
            } else {
                return coins[i][j];
            }
        }
        

        if (dp[i][j][k] != -100000000) {
            return dp[i][j][k];
        }
        // cout << i << " " << j << endl;
        int right = -1e8;
        if (j < m - 1) {
            int take = coins[i][j] + solve(coins, i, j + 1, k);
            int nt = -1e8;
            if (k < 2)
                nt = solve(coins, i, j + 1, k + 1);
            right = max(take, nt);
        }
        int down = -1e8;
        if (i < n - 1) {
            int take = coins[i][j] + solve(coins, i + 1, j, k);
            int nt = -1e8;
            if (k < 2)
                nt = solve(coins, i + 1, j, k + 1);
            down = max(take, nt);
        }
        // cout << i << " " << j << " " << k << " " << max(right, down) << endl;
        return dp[i][j][k] = max(right, down);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        for (int i = 0; i < 501; ++i) {
            for (int j = 0; j < 501; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = -100000000;
                }
            }
        }

        int n = coins.size();
        int m = coins[0].size();
        int x = solve(coins, 0, 0, 0);
        return x;
    }
};