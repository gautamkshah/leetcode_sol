class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int tot=pref[n-1];
         if(tot-pref[0]==0) return 0;
        for(int i=1;i<n-1;i++){
            int left=tot-pref[i];
            if(left==pref[i-1]) return i;
        }
       
        if(pref[n-2]==0) return n-1;
        return -1;
    }
};