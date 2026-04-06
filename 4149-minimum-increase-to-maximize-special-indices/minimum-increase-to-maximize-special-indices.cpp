class Solution {
public:
    // long long solve(vector<int>& nums,int ind){
    //     int n=nums.size();
    //     if(i==n) return 0;

    // }
    long long minIncrease(vector<int>& nums) {
        long long ans1=0;
        int n=nums.size();
        if(n%2){
            for(int i=1;i<n-1;i=i+2){
                ans1+=max({0,max(nums[i-1]+1,nums[i+1]+1)-nums[i]});
            }
            return ans1;
        }
        vector<long long> ans(n,0);
        for(int i=1;i<n-1;i=i+2){
            ans1+=max({0,max(nums[i-1]+1,nums[i+1]+1)-nums[i]});
            ans[i]=ans1;
        }
        ans1=0;
        vector<long long> suff(n,0);
        for(int i=n-2;i>=1;i=i-2){
            ans1+=max({0,max(nums[i-1]+1,nums[i+1]+1)-nums[i]});
            suff[i]=ans1;
        }
        
        long long rs=ans[n-3];
       
        for(int i=1;i<n-1;i=i+2){
            if(i+3<n)
                rs=min(rs,ans[i]+suff[i+3]);
        }
        
        for(int i=n-2;i>2;i=i-2){
            rs=min(rs,suff[i]+ans[i-3]);
        }
       
        rs=min(rs,suff[2]);
        
        return rs;


    }
};