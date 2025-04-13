class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        
        vector<int> dp(1 << maxChoosableInteger, -1);
        return canWin(maxChoosableInteger, desiredTotal, 0, dp);
    }
    
private:
    bool canWin(int n, int total, int mask, vector<int>& dp) {
        if (dp[mask] != -1) return dp[mask];
        
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                if (total <= i + 1 || !canWin(n, total - (i + 1), mask | (1 << i), dp)) {
                    return dp[mask] = true;
                }
            }
        }
        
        return dp[mask] = false;
    }
};