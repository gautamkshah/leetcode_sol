class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int mi=prices[0];
        for(int i=1;i<n;i++){
            
            mi=min(mi,prices[i]);
            int sol=prices[i]-mi;
            ans=max(ans,sol);
        }
        return ans;
    }
};