class Solution {
public:
    int longestSquareStreak(vector<int>& num) {
        int n=num.size();
        vector<long long int> nums;
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(num[i]);
        }
        for(auto i:st){
            cout<<i<<" ";
            nums.push_back(i);
        }
        cout<<endl;
        n=nums.size();
        sort(nums.begin(),nums.end());
        map<long long int, int> mp;
        mp[nums[0]*nums[0]]=1;
        for(int i=1;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                int len=mp[nums[i]];
                mp[nums[i]*nums[i]]=len+1;
            }else{
                mp[nums[i]*nums[i]]=1;
            }
        }
        cout<<endl;
        int ans=0;
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
            ans=max(ans,i.second);
        }
        if(ans==1) return -1;
        return ans;
    }
};