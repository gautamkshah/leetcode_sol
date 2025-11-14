class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& quereis) {
        vector<vector<int>> vec(n+1,vector<int> (n+1,0));
        for(int i=0;i<quereis.size();i++){
            int row1=quereis[i][0];
            int col1=quereis[i][1];
            int row2=quereis[i][2];
            int col2=quereis[i][3];
            for(int j=row1;j<=row2;j++){
                vec[j][col1]++;
                vec[j][col2+1]--;
            }
        }
        vector<vector<int>> grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int pre=0;
            for(int j=0;j<n;j++){
                pre+=vec[i][j];
                grid[i][j]=pre;
            }
        }
        return grid;
    }
};