class Solution {
public:
    int coinChange(vector<int>&  nums, int am) {
        int n=nums.size();
        int sum=0;
        vector<vector<int>> dp(n,vector<int>(am+1,0));
        for(int i=0;i<am+1;i++){
            if(i%nums[0]==0){
               dp[0][i]=i/nums[0];
            }
            else dp[0][i]=1e8;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=am;j++){
                int nt=dp[i-1][j];
                int t=1e8;
                if(nums[i]<=j){
                    t=1+dp[i][j-nums[i]];
                }
                dp[i][j]=min(t,nt);
            }
        }
        int ans=dp[n-1][am];
        if(ans>=1e8) return-1;
        return ans; 

        
    }
};