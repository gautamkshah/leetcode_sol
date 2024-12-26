class Solution {
public:
    int n;
    int solve(vector<int> &nums,int i,int sum,int target){
        if(i==n){
            if(sum==target){
                return 1;
            }else return 0;
        }
        int op1=solve(nums,i+1,sum+nums[i],target);
        int op2=solve(nums,i+1,sum-nums[i],target);
        return op1+op2;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        return solve(nums,0,0,target);
        
    }
};