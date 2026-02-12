class Solution {
public:
    int n, m;
    vector<vector<vector<long long>>> dp;

    long long solve(vector<int>& a, vector<int>& b, int i, int j, int t, int k) {
        if (t == k) return 0;                
        if (i == n || j == m) return LLONG_MIN / 4; 

        long long &res = dp[i][j][t];
        if (res != LLONG_MIN) return res;

        // Option 1: skip a[i]
        long long op1 = solve(a, b, i + 1, j, t, k);

        // Option 2: skip b[j]
        long long op2 = solve(a, b, i, j + 1, t, k);

        // Option 3: take both
        long long take = solve(a, b, i + 1, j + 1, t + 1, k);
        if (take != LLONG_MIN / 4)
            take += 1LL * a[i] * b[j];

        res = max({op1, op2, take});
        return res;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size();
        m = nums2.size();
        dp.assign(n, vector<vector<long long>>(m, vector<long long>(k, LLONG_MIN)));
        return solve(nums1, nums2, 0, 0, 0, k);
    }
};
