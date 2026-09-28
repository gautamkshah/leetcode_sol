class Solution {
public:
    int minDays(vector<int>& bl, int m, int k) {
        int l=1;
        int h=0;
        int n=bl.size();
        for(int i=0;i<n;i++){
            h=max(h,bl[i]);
        }
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int count_bou=0;
            int i=0;
            while(i<n){
                if(bl[i]>mid){
                    i++;
                    continue;
                }
                int count=0;
                while(i<n and bl[i]<=mid){
                    count++;
                    i++;
                }
                count_bou+=count/k;
            }
            if (count_bou>=m){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;

        
    }
};