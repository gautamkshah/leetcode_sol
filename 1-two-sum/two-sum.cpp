class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int ,int > mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int fi=target-nums[i];
            if(mp.find(fi)!=mp.end()){
                res={mp[fi],i};
                return res;
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};