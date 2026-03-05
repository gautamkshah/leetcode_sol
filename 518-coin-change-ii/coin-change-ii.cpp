class Solution {
public:
    int solve(int am, vector<int>& coins,int i, vector<vector<int>>& dp){
        int n=coins.size();
        if(i==n){
            if(am==0) return 1;
            else return 0;
        }
        if(dp[am][i]!=-1) return dp[am][i];
        int ways=0;

        if(coins[i]<=am)
            ways+=solve(am-coins[i],coins,i,dp);
        ways+=solve(am,coins,i+1,dp);
        return dp[am][i]=ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(),-1));
        sort(coins.begin(),coins.end());
        return solve(amount,coins,0,dp);
        
    }
};