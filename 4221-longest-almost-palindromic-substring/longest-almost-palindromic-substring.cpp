class Solution {
public:
    int solve(string& s, int i) {
        int c = 1;
        int n = s.size();
        int j = i - 1, k = i + 1;
         if(j==-1 || k==n){
                    c++;
                }
        bool res = true;
        while (j >= 0 && k < n) {
            if (s[j] == s[k]) {
                c += 2;
                j--;
                k++;
                if(j==-1 && k==n){
                    break;
                }else if(j==-1 || k==n){
                    c++;
                }
                
            } else {
                int op1 = 0;
                int q = j - 1, w = k;
                while (q >= 0 && w < n) {
                    if (s[q] == s[w]) {
                        op1 += 2;
                        q--;
                        w++;
                    } else
                        break;
                }
                q = j, w = k + 1;
                int op2 = 0;
                while (q >= 0 && w < n) {
                    if (s[q] == s[w]) {
                        op2 += 2;
                        q--;
                        w++;
                    } else
                        break;
                }
                return c + max(op1, op2) + 1;
            }
        }
        return c;
    }
    int solve1(string &s, int i){
        int c = 0;
        int n = s.size();
        int j = i - 1, k = i + 2;
        if(i==0 && n!=2){
            c++;
        }else if(i==n-2 && n!=2){
            c++;
        }
        bool res = true;
        while (j >= 0 && k < n) {
            if (s[j] == s[k]) {
                c += 2;
                j--;
                k++;
                if(j==-1 && k==n){
                    break;
                }else if(j==-1 || k==n){
                    c++;
                }
            } else {
                int op1 = 0;
                int q = j - 1, w = k;
                while (q >= 0 && w < n) {
                    if (s[q] == s[w]) {
                        op1 += 2;
                        q--;
                        w++;
                    } else
                        break;
                }
                q = j, w = k + 1;
                int op2 = 0;
                while (q >= 0 && w < n) {
                    if (s[q] == s[w]) {
                        op2 += 2;
                        q--;
                        w++;
                    } else
                        break;
                }
                return c + max(op1, op2) + 1;
            }
        }
        return c;
    }
    int almostPalindromic(string s) {
        int n = s.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            c = max(solve(s, i), c);
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                c=max(solve1(s,i)+2,c);
            }
        }
        return c;
    }
};