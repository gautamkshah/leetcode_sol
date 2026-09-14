class Solution {
public:
    int solve(vector<int> &nums,int k){
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int atmostk=solve(nums,k);
        int atmostk1=solve(nums,k-1);
        return atmostk-atmostk1;
    }
};