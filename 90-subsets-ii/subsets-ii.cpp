
class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int>&nums, int i,vector<int> ans){
        int n=nums.size();
        if(i==n){

            st.insert(ans);
            return ;
        }
        ans.push_back(nums[i]);
        solve(nums,i+1,ans);
        ans.pop_back();
        solve(nums,i+1,ans);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        solve(nums,0,ans);
        set<vector<int>> sol;
        for(auto it:st){
            sort(it.begin(),it.end());
            sol.insert(it);
        }
        vector<vector<int>> vecc;
        for(auto it:sol){
            vecc.push_back(it);
        }
        return vecc;
    }
};