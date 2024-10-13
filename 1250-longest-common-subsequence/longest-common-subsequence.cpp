class Solution {
public:
    int n,m;
    int solve(string & t1,string &t2,int i,int j){
        if(i==n || j==m) return 0;
        if(t1[i]==t2[j]){
            return 1+solve(t1,t2,i+1,j+1);
        }
        return max(solve(t1,t2,i+1,j),solve(t1,t2,i,j+1));
    }
    int longestCommonSubsequence(string t1, string t2) {
        n=t1.size();
        m=t2.size();
       
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
};