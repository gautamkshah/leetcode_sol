class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int c = 0, i = 0;
        int ones=0;
        while (i < n) {
            if(s[i]=='1'){
                ones++;
                i++;
                continue;
            }
            int x=0;
            while(i<n && s[i]=='0'){
                x++;
                i++;
            }
            c+=ones;
        }
        return c;
    }
};