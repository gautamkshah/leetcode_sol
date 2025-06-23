class Solution {
public:
    vector<int> findCoins(const vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        vector<int> coin;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==1) {
        //         coin.push_back(i+1);
        //         break;
        //     }
        // }
        for(int i=1;i<=n;i++){
            int tar=dp[i];
            if(tar==nums[i-1]) continue;
            if(tar!=nums[i-1]-1) return {};
            // cout<<tar<<" "<<nums[i-1]<<endl;
            coin.push_back(i);
            for(int j=i;j<=n;j++){
                dp[j]+=dp[j-i];
            }
        }
        return coin;
    }
};