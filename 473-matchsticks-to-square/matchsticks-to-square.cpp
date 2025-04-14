class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        
        // Sort in descending order to trigger failures early
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        // Check if any matchstick is longer than target
        if (matchsticks[0] > target) return false;
        
        // DP memoization: dp[mask] represents sides filled for this mask
        // We'll use a map from mask to possible side lengths
        unordered_map<int, bool> dp;
        
        // The mask represents which matchsticks have been used (bitmask)
        function<bool(int, int)> dfs = [&](int mask, int sides_done) {
            int total = 0;
            // Calculate how many matchsticks have been used
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    total += matchsticks[i];
                }
            }
            
            // If we've formed 3 sides, the 4th must be correct
            if (sides_done == 3) {
                return true;
            }
            
            // If we've seen this mask before, return cached result
            if (dp.count(mask)) return dp[mask];
            
            int remaining = (total / target) * target;
            int next_target = remaining + target;
            
            bool res = false;
            // Try adding unused matchsticks
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    int new_sum = total + matchsticks[i];
                    if (new_sum <= next_target) {
                        if (dfs(mask | (1 << i), sides_done + (new_sum == next_target))) {
                            res = true;
                            break;
                        }
                    }
                }
            }
            
            return dp[mask] = res;
        };
        
        return dfs(0, 0);
    }
};