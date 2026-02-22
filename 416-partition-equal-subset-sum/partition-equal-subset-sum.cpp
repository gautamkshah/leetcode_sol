class Solution {
public:
    bool solve(vector<int>& nums,int tar,int i,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(tar==0){
                return true;
            }else return false;
        }
        if(tar==0) return true;
        if(dp[i][tar]!=-1) return dp[i][tar];
        bool res=false;
        if(nums[i]<=tar){
            res=res| solve(nums,tar-nums[i],i+1,dp);
        }
        res= res| solve(nums,tar,i+1,dp);
        return dp[i][tar]= res;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        return solve(nums,target,0,dp);
    }
};