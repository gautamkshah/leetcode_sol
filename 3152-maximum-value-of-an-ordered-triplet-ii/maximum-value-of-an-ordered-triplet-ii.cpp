class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<long long > ma(n), mi(n);
        ma[0]=nums[0];
        mi[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            ma[i]=max(ma[i-1],(long long)nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            mi[i]=max((long long)nums[i+1],mi[i+1]);
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans, (ma[i]-nums[i])*mi[i]);
        }
        return ans;
        
    }
};