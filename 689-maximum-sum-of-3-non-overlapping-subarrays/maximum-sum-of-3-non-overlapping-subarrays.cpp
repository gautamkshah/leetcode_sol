class Solution {
public:
    int dp[20005][5];
    int solve(vector<int>& nums, int k, int i, int count) {
        int n = nums.size();
        if (i == n) {
            if (count == 3) {
                return 0;
            } else {
                return -1e5;
            }
        }
        if (dp[i][count] != -1) return dp[i][count];
        int pick = 0;
        if (i + k <= n && count < 3) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
            }
            pick = sum + solve(nums, k, i + k, count + 1);
        }
        int notpick = solve(nums, k, i + 1, count);
        return dp[i][count] = max(pick, notpick);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        solve(nums, k, 0, 0);

        vector<int> res;
        int i = 0, count = 0, n = nums.size();
        while (count < 3) {
            int maxSum = -1e5, bestIndex = -1;
            for (int j = i; j + k <= n; j++) {
                int sum = 0;
                for (int x = j; x < j + k; x++) {
                    sum += nums[x];
                }
                if (sum + solve(nums, k, j + k, count + 1) > maxSum) {
                    maxSum = sum + solve(nums, k, j + k, count + 1);
                    bestIndex = j;
                }
            }
            res.push_back(bestIndex);
            i = bestIndex + k;
            count++;
        }
        return res;
    }
};
