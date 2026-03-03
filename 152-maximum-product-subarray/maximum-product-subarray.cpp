class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma=1;
        int ans=nums[0];
        for(int i:nums){
            ma*=i;
            ans=max(ans,ma);
            if(ma==0) ma=1;
        }
        ma=1;
        for(int i=nums.size()-1;i>=0;i--){
            ma*=nums[i];
            ans=max(ans,ma);
            if(ma==0) ma=1;
        }
        return ans;
    }
};