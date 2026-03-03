class Solution {
public:
    bool solve(vector<int>& piles,int h,int mid){
        long long int c=0;
        for(auto i:piles){
            c+=i/mid;
            if(i%mid!=0) c++;
        }
        if(c<=h){
            return true;
        }else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=0;
        for(auto i: piles) r=max(r,i);
        while(l<=r){
            int mid=(l+r)/2;
            bool res=solve(piles,h,mid);
            if(res){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};