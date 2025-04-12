class Solution {
public:
    bool solve(vector<int>& nums,int k ,int mid){
        int sum=0;
        int csum=0;
        int n=nums.size();
        int c=1;
        for(int i=0;i<n;i++){
            if(nums[i]>mid) return false;
            sum+=nums[i];
            if(sum>mid){
                sum=nums[i];
                c++;
                if(c>k) return false;
            }
        }
        return true;
    }


    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int mi=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            mi=min(mi,nums[i]);
            sum+=nums[i];
        }
        int l=mi,h=sum;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(solve(nums,k,mid)){
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};