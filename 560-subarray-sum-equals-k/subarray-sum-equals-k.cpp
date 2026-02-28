class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        mp[0]=1;
        int curr_sum=0;
        int count=0;
        for(auto i:nums){
            curr_sum+=i;
            count+=mp[curr_sum-k];
            mp[curr_sum]++;
        }
        return count;
        
    }
};