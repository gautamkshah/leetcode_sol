class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> spi;
        int left = 0, top = 0,right = m - 1, bott = n - 1;
        while (left <= right && top <= bott) {
            for (int i = left; i <= right; i++) {
                spi.push_back(mat[top][i]);
            }
            top++;
            for (int i = top; i <= bott; i++) {
                spi.push_back(mat[i][right]);
            }
            right--;
            if (top <= bott) {
                for (int i = right; i >= left; i--) {
                    spi.push_back(mat[bott][i]);
                }
                bott--;
            }
            if (left <= right) {
                for (int i = bott; i >= top; i--) {
                    spi.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return spi;
    }
};