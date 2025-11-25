class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int n=s.size();
        map<char,int> mp;
        int i=0,j=0;
        while(j<n){
            if(mp[s[i]]==0){
                mp[s[i]]++;
                len=max(len,j-i+1);
            }else{
                mp[s[j]]++;
                while(mp[s[j]]!=1){
                    mp[s[i]]--;
                    i++;
                }
                len=max(len,j-i+1);
            }
            j++;
        }
        return len;
        
    }
};