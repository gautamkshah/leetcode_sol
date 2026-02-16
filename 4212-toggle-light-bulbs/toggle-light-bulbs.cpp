class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        int n=bulbs.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[bulbs[i]]++;
        }
        for(auto i:mp){
            if(i.second%2==1){
                ans.push_back(i.first);
            }

        }
        return ans;
    }
};