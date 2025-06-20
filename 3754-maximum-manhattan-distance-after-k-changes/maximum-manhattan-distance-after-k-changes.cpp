class Solution {
public:
    int maxDistance(string ss, int k) {
        int n = 0, s = 0, e = 0, w = 0;
        int l = ss.size();
        int ans = 0;
        for (int i = 0; i < l; i++) {
            if (ss[i] == 'N')
                n++;
            if (ss[i] == 'E')
                e++;
            if (ss[i] == 'W')
                w++;
            if (ss[i] == 'S')
                s++;
            if (n >= s && e >= w) {
                int v = n - s + e - w + min(k, s + w)*2;
                ans = max(ans, v);
            }
            if (s >= n && e >= w) {
                int v = s - n + e - w + min(k, n + w)*2;
                ans = max(ans, v);
            }
            if (n >= s && w >= e) {
                int v = n - s - e + w + min(k, s + e)*2;
                ans = max(ans, v);
            }
            if (s >= n && w >= e) {
                int v = s - n + w - e + min(k, n + e)*2;
                ans = max(ans, v);
            }
        }
        return ans;
    }
};