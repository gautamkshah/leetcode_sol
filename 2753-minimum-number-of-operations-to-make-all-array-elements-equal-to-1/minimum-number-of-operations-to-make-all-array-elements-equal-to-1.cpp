class Solution {
public:
    int minOperations(vector<int>& a) {
        int c = 0;
        int mini = INT_MAX;
        int n=a.size();
        int cc=0;
        for(int i=0;i<n;i++){
            if(a[i]==1) cc++;
        }
        if(cc>0){
            return n-cc;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int gcd = a[j];
                for (int k = i; k <= j; k++) {
                    gcd = __gcd(gcd, a[k]);
                }
                if (gcd == 1) {
                    mini = min(mini, j - i + 1);
                }
            }
        }
        if (mini == INT_MAX) {
            return -1;
        }
        return n-1+mini-1;
    }
};