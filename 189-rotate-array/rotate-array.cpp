class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n; // the value is k ..0..n-1
        vector<int>ans;
        for(int i=n-k;i<n;++i)ans.push_back(nums[i]);
        //we are getting the last k elements
        //(n-k)(k)
        //(k)(n-k)
        for(int i=0;i<(n-k);++i)ans.push_back(nums[i]);
        nums = ans;

    }
};