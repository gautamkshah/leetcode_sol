class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // Create a DP table with (n+1) x (m+1) size
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, take diagonal value and add 1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If they don't match, take the max of top or left cell
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The bottom-right corner contains the length of the longest common subsequence
        return dp[n][m];
    }
};
