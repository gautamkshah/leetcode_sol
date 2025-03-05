class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        for(long long i=1;i<=n;i++){
            if(i!=n){
                ans+=i*2-1;
            }
            ans+=i*2-1;
        }
        return ans;
    }
};