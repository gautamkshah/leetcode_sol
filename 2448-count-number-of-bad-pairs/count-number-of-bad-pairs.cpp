class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        map<long long ,long long > mp;
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
        long long ans=0;
        for(auto i:mp){
            
            ans+=(i.second*(i.second-1))/2;
        }
        long long res=n;
        res=res*(res-1)/2;
        return res-ans;
        
    }
};