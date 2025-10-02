class Solution {
public:
    int maxBottlesDrunk(int num, int ne) {
        int ans=num;
        while(num>=ne){
            num-=ne;
            num++;
            ne++;
            ans++;
        }
        return ans;
        
    }
};