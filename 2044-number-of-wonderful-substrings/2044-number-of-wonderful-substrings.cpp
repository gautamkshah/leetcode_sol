class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        map<long long,long long> mp;
        long long ans=0;
        long cum_xor=0;
        mp[0]=1;
        for(char ch:word){
            long shift=ch-'a';
            cum_xor^=(1<<shift);
            ans+=mp[cum_xor];
            for(char ch1='a'; ch1<='j';ch1++){
                shift=ch1-'a';
                long val=(cum_xor)^(1<<shift);
                ans+=mp[val];
            }
            mp[cum_xor]++;
        }
        return ans;
         
    }
};