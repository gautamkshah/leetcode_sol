class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        vector<int> suff(n,0);
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i+1];
        }
        for(int i=0;i<n-1;i++){
            double top=suff[i];
            double down=n-i-1;
            double val=top/down;
            if(nums[i]>val) c++;
        }
        return c;
        
    }
};