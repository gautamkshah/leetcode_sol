class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> diff(n);
        pre[0]=nums[0];
        int o=0,e=0;
        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]^nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                e++;
            }else{
                o++;
            }
            diff[i]=e-o;
        }
        // for(int i=0;i<n;i++){
        //     cout<<pre[i]<<" "<<diff[i]<<endl;
        // }
        map<pair<int,int>,int> mp;
        mp[{0,0}]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find({pre[i],diff[i]})!=mp.end()){
                ans=max(ans,i-mp[{pre[i],diff[i]}]);
                cout<<i<<endl;
            }
            else mp[{pre[i],diff[i]}]=i;
        }
        // for(auto i:mp){
        //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
        // }
        return ans;
    }
};