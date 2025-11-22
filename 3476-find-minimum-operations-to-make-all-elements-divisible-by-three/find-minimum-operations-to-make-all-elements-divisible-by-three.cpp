class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(auto i:nums){
            mp[i%3]++;
        }
        return mp[1]+mp[2];
        
    }
};