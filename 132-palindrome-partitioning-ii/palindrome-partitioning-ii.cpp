class Solution {
public:
    vector<vector<int>> dp;
    
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j) {
        if (i >= j) return 0;
        if (isPalindrome(s, i, j)) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = s.size();
        for (int k = i; k < j; k++) {
            if (isPalindrome(s, i, k)) {
                ans = min(ans, 1 + solve(s, k + 1, j));
            }
        }
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(s, 0, n - 1);
    }
};
