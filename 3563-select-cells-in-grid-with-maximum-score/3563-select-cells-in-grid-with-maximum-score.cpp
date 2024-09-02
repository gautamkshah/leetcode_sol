class Solution {
public:
    
int dp[101][(1<<10)];
vector<int> vec[101];

int solve(int i, int mask){
    if(i==101){
        return 0;
    }
    if(dp[i][mask]!=-1){
        return dp[i][mask];
    }
    int ans = solve(i+1,mask);
    for(int j=0;j<vec[i].size();j++){
        if(mask&(1<<vec[i][j])){
            continue;
        }
        ans = max(ans,i+solve(i+1,mask|(1<<vec[i][j])));
    }
    return dp[i][mask] = ans;

}

int maxScore(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vec[grid[i][j]].push_back(i);
        }
    }
    memset(dp,-1,sizeof(dp));
    return solve(1,0);

}
};