class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> q;
        int n=nums.size();
        map<int,int> mp;
        int cnt=0;
        for(int i=0;i<k;i++){
            q.push(nums[i]);
            mp[nums[i]]++;
            cnt++;
        }
        vector<int> ans;
        auto en=mp.rbegin();
        ans.push_back(en->first);
        int j=0;
        for(int i=cnt;i<n;i++){
            mp[nums[j]]--;
            if(mp[nums[j]]==0){
                mp.erase(nums[j]);
            }
            q.push(nums[i]);
            mp[nums[i]]++;
            auto en=mp.rbegin();
            ans.push_back(en->first);
            j++;
        }
        return ans;
    }
};