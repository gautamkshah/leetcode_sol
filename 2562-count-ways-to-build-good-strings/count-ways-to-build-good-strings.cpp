class Solution {
public:
    int n;
    int e=1000000007;
    int  dp[1000001];
    int rec(int i,int l, int h, int z, int o){
        if(dp[i]!=-1) return dp[i];
        if(i>h) return dp[i]=0;
        if(i>=l && i<=h){
            return dp[i]=(1+rec(i+z,l,h,z,o)+rec(i+o,l,h,z,o))%e;
        }
        else{
            return dp[i]=(rec(i+z,l,h,z,o)+rec(i+o,l,h,z,o))%e;
        }
    }
    int countGoodStrings(int l, int h, int z, int o) {
        memset(dp,-1,sizeof(dp));
        return rec(0,l,h,z,o);
        
    }
};