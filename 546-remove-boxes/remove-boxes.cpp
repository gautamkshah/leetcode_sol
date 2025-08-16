class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(boxes, 0, n-1, 0, dp);
    }


    int solve(vector<int>& boxes, int l, int r, int count, vector<vector<vector<int>>>& dp) {
        if (l > r) return 0;
        
        if (dp[l][r][count] != -1) return dp[l][r][count];
        
        int ans = (count + 1) * (count + 1) + solve(boxes, l + 1, r, 0, dp);
        
        for (int i = l + 1; i <= r; i++) {
            if (boxes[i] == boxes[l]) {
                ans = max(ans, solve(boxes, l + 1, i - 1, 0, dp) + solve(boxes, i, r, count + 1, dp));
            }
        }
        
        return dp[l][r][count] = ans;
    }
};