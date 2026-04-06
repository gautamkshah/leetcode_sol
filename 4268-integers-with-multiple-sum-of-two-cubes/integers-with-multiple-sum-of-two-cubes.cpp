class Solution {
public:
    bool is(long long n) {
        long long root = round(cbrt(n));
        return root * root * root == n;
    }
    vector<int> findGoodIntegers(int n) {
        vector<int> ans;
        map<long long , long long> mp;
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=i;j++){
                long long val=i*i*i+j*j*j;
                if(val<=n)
                   mp[val]++;
            }
        }
        for(auto i:mp){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;

        
    }
};