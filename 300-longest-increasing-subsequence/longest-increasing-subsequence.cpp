class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    ans[i]=max(ans[i],ans[j]+1);
                }
            }
        }
        int anss=0;
        for(auto i: ans){
            anss=max(anss,i);
        }
        return anss;
        
    }
};