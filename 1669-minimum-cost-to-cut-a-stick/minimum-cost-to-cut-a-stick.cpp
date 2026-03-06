class Solution {
public:
    
    int dp[101][101];
    int solve(int i,int j,vector<int>&cuts){
       if (i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] +
                  solve(i, ind - 1, cuts) +
                  solve(ind + 1, j, cuts);

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
       sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts);
        
    }
};