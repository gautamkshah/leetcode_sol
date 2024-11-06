class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> a(n);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            a[i]=nums[i];
            int c=0;
            while(nums[i]!=0){
                if(nums[i]%2==1) c++;
                nums[i]/=2;
            }
            ans[i]=c;
        }
      //  cout<<"he\n;";
        int i=0;
        int prev=-1;
        bool res=true;
        while(i<n){
            int s=ans[i];
            int maxi=a[i];
           // cout<<s<<" "<<maxi<<endl;
            while(i<n && ans[i]==s ){
                if(a[i]<prev){
                    res=false;
                    break;
                }
                maxi=max(maxi,a[i]);
                i++;
            }
            prev=maxi;
        }
        return res;
        
    }
};