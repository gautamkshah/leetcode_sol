class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> rev=nums;
        reverse(rev.begin(),rev.end());
        for(int i:rev){
            nums.push_back(i);
        }
        return nums;
        
    }
};