class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> nums(26, 0);
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            nums[s[i] - 'a']++;
        }
        
        while(t--) {
            vector<long long> temp(26, 0);
            for(int i = 0; i < 25; i++) {
                temp[i + 1] = nums[i] % MOD;
            }
            temp[0] = nums[25] % MOD;
            temp[1] = (temp[1] + nums[25]) % MOD;
            
            nums = temp;
        }
        
        long long sum = 0;
        for(int i = 0; i < 26; i++) {
            sum = (sum + nums[i]) % MOD;
        }
        
        return (int)sum;
    }
};