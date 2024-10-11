class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int c_pr1=1,c_pr2=1;
        int m1=INT_MIN,m2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                m1=max(m1,0);
                c_pr1=1;
            }else {
                c_pr1*=nums[i];
                m1=max(c_pr1,m1);
            }
            if(nums[n-i-1]==0){
                m2=max(m2,0);
                c_pr2=1;
            }else{
                c_pr2*=nums[n-i-1];
                m2=max(c_pr2,m2);
            }
        }
        return max(m1,m2);


        
    }
};