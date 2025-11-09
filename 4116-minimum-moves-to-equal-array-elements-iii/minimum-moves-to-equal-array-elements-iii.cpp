class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int m=0;
        int sum=0;
        for(int i=0;i<n;i++){
            m=max(nums[i],m);
            sum+=nums[i];
        }        
        return m*n-sum;
    }
};