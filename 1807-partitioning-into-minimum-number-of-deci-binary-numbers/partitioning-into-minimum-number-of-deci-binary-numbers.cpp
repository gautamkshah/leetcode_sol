class Solution {
public:
    int minPartitions(string n) {
        int s=n.size();
        int ma=0;
        for(auto i:n){
            ma=max(ma,i-48);
        }   
        return ma;
    }
};