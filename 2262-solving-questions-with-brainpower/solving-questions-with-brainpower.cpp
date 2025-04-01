class Solution {
public:
    int n;
    long long  dp[1000001];
    long long rec(int i,vector<vector<int>>& q){
        if(dp[i]!=-1) return dp[i];
        if(i>=n) return dp[i]=0;
        return dp[i]=max(q[i][0]+rec(i+q[i][1]+1,q),rec(i+1,q));
    }
    long long mostPoints(vector<vector<int>>& q) {
        n=q.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,q);
    }
};