class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++){
            if(nums[i-1]==target){
                pre[i]=1+pre[i-1];
            }
            else{
                pre[i]=pre[i-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int c=pre[j]-pre[i-1];
                if(c>(j-i+1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};