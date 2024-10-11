class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        int n=nums.size();
        vec.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int x=nums[i];
            if(x>vec.back()){
                vec.push_back(x);
            }else{
                int pos=lower_bound(vec.begin(),vec.end(),x)-vec.begin();
                vec[pos]=x;
            }
        }
        return vec.size();
        
    }
};