class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=max(dp[n-1][i+1],grid[n-1][i]);
            cout<<dp[n-1][i]<<" ";
        }
        cout<<endl;
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=max(dp[i+1][m-1],grid[i][m-1]);
            cout<<dp[i][m-1]<<" ";
        }
        cout<<endl;
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=max({dp[i+1][j],dp[i][j+1],grid[i+1][j],grid[i][j+1]});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==dp[i][j] && i<n-1){
                    ans=max(ans,dp[i+1][j]-grid[i][j]);
                }
                if(grid[i][j]==dp[i][j] && j<m-1){
                    ans=max(ans,dp[i][j+1]-grid[i][j]);
                }
                if(grid[i][j]!=dp[i][j]){
                    ans=max(ans,dp[i][j]-grid[i][j]);
                }
            }
           
        }
        return ans;
        
    }
};