class Solution {
public:
    int n;
    unordered_map<int, int> stonePos;  // map stone value to index
    map<pair<int, int>, bool> dp;

    bool solve(vector<int>& stones, int i, int k) {
        if (i == n - 1) return true;

        if (dp.count({i, k})) return dp[{i, k}];

        for (int jump = k - 1; jump <= k + 1; ++jump) {
            if (jump > 0) {
                int nextStone = stones[i] + jump;
                if (stonePos.count(nextStone)) {
                    int nextIndex = stonePos[nextStone];
                    if (solve(stones, nextIndex, jump)) {
                        return dp[{i, k}] = true;
                    }
                }
            }
        }

        return dp[{i, k}] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] - stones[0] != 1) return false;

        // Build position map
        for (int i = 0; i < n; ++i) {
            stonePos[stones[i]] = i;
        }

        return solve(stones, 1, 1);
    }
};
