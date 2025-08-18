class Solution {
public:
        string longestNiceSubstring(string s) {
        if(s.size() < 2) {
            return "";
        }
        vector<int> a(26), A(26);
        for(char c: s) {
            if(isupper(c)) {
                A[c-'A']=1;
            } else {
                a[c-'a']=1;
            }  
        }
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(a[tolower(c)-'a'] && A[toupper(c)-'A']) {
                continue;
            }
            string pre = longestNiceSubstring(s.substr(0, i));
            string suf = longestNiceSubstring(s.substr(i+1));
            if(pre.size() >= suf.size()) {
                return pre;
            } else {
                return suf;
            }
        }
        return s;
    }
};