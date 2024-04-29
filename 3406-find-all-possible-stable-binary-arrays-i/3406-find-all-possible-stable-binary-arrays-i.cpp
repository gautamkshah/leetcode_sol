const long long mod = 1e9 + 7;

class Solution {
public:
    long  z, o, l;
    int dp[201][201][201][2];

int solve(int zero, int one, int limit, int last)
{
    if (zero == z && one == o)
    {
        return 1;
    }

    int ans = 0;
    if (last == -1)
    {
        if (zero < z)
        {
            ans = (ans + solve(zero + 1, one,1, 0)) % mod;
        }
        if (one < o)
        {
            ans = (ans + solve(zero, one + 1,1, 1)) % mod;
        }
    }
    if(last!=-1){
        if(dp[zero][one][limit][last]!=-1) return dp[zero][one][limit][last];
    }
    if (last == 0)
    {
        if (limit < l)
        {
            if (zero < z)
            {
                ans = (ans + solve(zero + 1, one, limit + 1, 0)) % mod;
            }
        }
        if (one < o)
        {
            ans = (ans + solve(zero, one + 1, 1, 1)) % mod;
        }
    }
    else if(last==1){
        if(limit<l){
            if(one<o){
                ans = (ans + solve(zero, one + 1, limit + 1, 1)) % mod;
            }
        }
        if(zero<z){
            ans = (ans + solve(zero + 1, one, 1, 0)) % mod;
        }
    }
    if(last==-1) return ans%mod;
    return dp[zero][one][limit][last]=ans % mod;
}

int numberOfStableArrays(int zero, int one, int limit)
{
    z = zero;
    o = one;
    l = limit;
    memset(dp,-1,sizeof(dp));
    int ans = solve(0, 0, 0, -1)%mod;
    return (ans)%mod;
}

};