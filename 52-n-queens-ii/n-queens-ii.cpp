class Solution {
public:
    vector<vector<string>> ans;
    bool safe(vector<string>& res, int ii, int jj) {
        int n = res.size();
        for (int i = 0; i < ii; i++) {
            if (res[i][jj] == 'Q')
                return false;
        }
        for (int j = 0; j < jj; j++) {
            if (res[ii][j] == 'Q')
                return false;
        }
        for (int i = ii - 1, j = jj - 1; i >= 0 && j >= 0; i--, j--) {
            if (res[i][j] == 'Q')
                return false;
        }
        for (int i = ii - 1, j = jj + 1; i >= 0 && j < n; i--, j++) {
            if (res[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void solve(vector<string>& res, int ind, int n) {
        if (ind == n) {
            ans.push_back(res);
        }
        for (int i = 0; i < n; i++) {
            if (safe(res, ind, i)) {
                res[ind][i] = 'Q';
                solve(res, ind + 1, n);
                res[ind][i] = '.';
            }
        }
    }
  
    int totalNQueens(int n) {
vector<string> res;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                s.push_back('.');
            }
            res.push_back(s);
        }
        solve(res, 0, n);
        return ans.size();
    }
};