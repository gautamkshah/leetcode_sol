class Solution {
public:
    int numWaterBottles(int nb, int ne) {
       int t=nb;
       int ans=nb;
       while(t>=ne){
        ans+=t/ne;
        t=t/ne+t%ne;
       }
       return ans;
    }
};