class Solution {
public:
    int solve(vector<int> &nums,int targ,int ind, int tar){
        if(ind==nums.size()){
            if(tar==targ){
                return 1;
            }else return 0;
        }
        int p1=solve(nums,targ,ind+1,tar+nums[ind]);
        int p2=solve(nums,targ,ind+1,tar-nums[ind]);
        return p1+p2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
        
    }
};