class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int mid=(l+h)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    l=mid+1;
                }else{
                    h=mid;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }else{
                    h=mid;
                }
            }
        }
        return nums[l];
        
    }
};