class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a=prices[0];
        int b=0;
        for(int i=1;i<prices.size();i++){
            int cp=prices[i]-a;
            b=max(b,cp);
            a=min(a,prices[i]);
        }
        return b;
        
    }
};