class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>> vec(n+1, vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]){
                    vec[i][j]=1+max(vec[i-1][j-1],vec[i][j]);
                }else{
                    vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
                }
            }
        }

        return vec[n][m];

    }
};