class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<int>& stones,int sum,int i,int ts,vector<vector<int>> &dp){
        int n=stones.size();
        if(i==n){
            int val=ts-sum;
            ans=min(ans,abs(val-sum));
            return;
        }
        if(dp[i][sum]!=-1) return;
        solve(stones,sum+stones[i],i+1,ts,dp);
        solve(stones,sum,i+1,ts,dp);
        dp[i][sum]=1;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int ts=0;
        for(auto i:stones) ts+=i;
        vector<vector<int>> dp(stones.size(),vector<int>(ts+1,-1));
        solve(stones,0,0,ts,dp);
        return ans;
    }
};