class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool> (target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]= true;
        }
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                bool nt=dp[i-1][j];
                bool t=false;
                if(nums[i]<=j){
                    t=dp[i-1][j-nums[i]];
                }
                dp[i][j]=t||nt;
            }
        }
        return dp[n-1][target];
        
    }
};