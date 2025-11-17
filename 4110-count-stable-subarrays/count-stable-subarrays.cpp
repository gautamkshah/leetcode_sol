#define ll long long
class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
         ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=nums.size();
        vector<ll> prefix(n,0);
        vector<ll> prefix_sum(n,0);
        prefix_sum[0]=1;
        ll c=1;
        prefix[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                c++;
                prefix[i]=c;
            }else{
                prefix[i]=1;
                c=1;
            }
            prefix_sum[i]=prefix_sum[i-1]+c;
        }
        vector<ll> suff(n,0);
        c=1;
        suff[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                c++;
                suff[i]=c;
            }else{
                suff[i]=1;
                c=1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<prefix[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<prefix_sum[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<suff[i]<<" ";
        }
        cout<<endl;
        vector<long long> anss;
        for(int i=0;i<queries.size();i++){
            ll l=queries[i][0];
            ll r=queries[i][1];
            ll last=0;
            if(l!=0){
                last=prefix_sum[l-1];
            }
            ll ans=prefix_sum[r]-last;
            // cout<<ans<<endl;
            ll count=min(r-l+1,suff[l]);
            ll right=0,left=0;
            left=prefix[l]-1;
            right=min(r-l+1,suff[l]);
            count=left*right;
            ans-=count;
            anss.push_back(ans);
            // cout<<l<<" "<<r<<" "<<ans<<" "<<left<<" "<<right<<" "<<count<<" "<<ans<<endl;
        }
        return anss;
    }
};