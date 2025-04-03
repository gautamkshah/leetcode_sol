class Solution {
public:
    vector<vector<int>> dp;
    int solve(int f, int l){
        if(f>=l) return 0;
        if(l-f==1) return f;
        if(l-f==2) return f+1;
        if(dp[f][l]!=-1) return dp[f][l];
        
        int cost=INT_MAX;
        for(int i=f+1;i<l;i++){
            cost = min(cost,i+ max(solve(f,i-1), solve(i+1,l)));
        }
        return dp[f][l]= cost;
    }
    int getMoneyAmount(int n) {
        dp.assign(n+2, vector<int>(n+2, -1));
        return solve(1,n);
        
    }
};