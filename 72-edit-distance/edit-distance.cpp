class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        
        // dp[i][j] represents the minimum edit distance between w1[0..i-1] and w2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the first row (edit distance between empty w1 and w2[0..j])
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;  // Requires j insertions to match
        }

        // Fill the first column (edit distance between empty w2 and w1[0..i])
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;  // Requires i deletions to match
        }

        // Fill the rest of the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (w1[i - 1] == w2[j - 1]) {
                    // If characters match, no additional operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // If characters don't match, consider insert, delete, and replace
                    int insertOp = dp[i][j - 1] + 1;
                    int deleteOp = dp[i - 1][j] + 1;
                    int replaceOp = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        // The result is stored in dp[n][m]
        return dp[n][m];
    }
};
