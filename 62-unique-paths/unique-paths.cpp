class Solution {
public:
int dp[101][101];
int solve(int i,int j,int m,int n){
    if(i==m || j==n){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int c=0;
    c+=solve(i,j+1,m,n);
    c+=solve(i+1,j,m,n);
    return dp[i][j]=c;

}
    int uniquePaths(int m, int n) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        int res= solve(0,0,m,n);
        return res;
        
    }
};