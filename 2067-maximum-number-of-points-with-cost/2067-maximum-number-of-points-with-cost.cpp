class Solution {
public:
    long long maxPoints(vector<vector<int>> &points)
{
    int n=points.size();
    int m=points[0].size();
    vector<vector<long int >> dp(n,vector<long int>(m,0));
    vector<long int> maxLeft(m,0);
    vector<long int> maxRight(m,0);
    maxLeft[0]=points[0][0];
    for(int i=1;i<m;i++)
    {
        maxLeft[i]=max(maxLeft[i-1]-1,(long )points[0][i]);
    }
    maxRight[m-1]=points[0][m-1];
    for(int i=m-2;i>=0;i--)
    {
        maxRight[i]=max(maxRight[i+1]-1,(long )points[0][i]);
    }
    for(int i=0;i<m;i++){
        dp[0][i]=max(maxLeft[i],maxRight[i]);
  //      cout<<dp[0][i]<<" ";
    }
    for(int i=1;i<n;i++)
    {
         for(int j=0;j<m;j++)
        {
            dp[i][j]=max(maxLeft[j]+(long )points[i][j],maxRight[j]+(long )points[i][j]);
      //      cout<<dp[i][j]<<" ";
        }
        maxLeft[0]=dp[i][0];
        for(int j=1;j<m;j++)
        {
            maxLeft[j]=max(maxLeft[j-1]-1,dp[i][j]);
        }
        maxRight[m-1]=dp[i][m-1];
        for(int j=m-2;j>=0;j--)
        {
            maxRight[j]=max(maxRight[j+1]-1,dp[i][j]);
        }
        
    }
    long int  ans=0;
    for(int i=0;i<m;i++)
    {
        ans=max(ans,dp[n-1][i]);
    }
    return ans;
}
};