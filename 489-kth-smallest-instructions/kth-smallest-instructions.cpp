class Solution {
public:
    int nCr(int n, int r) {
        long ans = 1;
        for (int i = 1, j = n - r + 1; i <= r; ++i, ++j)
            ans = ans * j / i;
        return ans;
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0], h = destination[1];
        int n = v + h;
        string s = "";
        for (int i = 0; i < n; i++) {
            if (h) {
                int c = nCr(h - 1 + v, v);
                if (k <= c) {
                    s += 'H';
                    h--;
                } else {
                    k -= c;
                    s += 'V';
                    v--;
                }
            } else {
                s += 'V';
                v--;
            }
        }
        return s;
    }
    
};

