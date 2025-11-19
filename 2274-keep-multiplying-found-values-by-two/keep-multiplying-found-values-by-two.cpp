class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;
        for(auto i:nums){
            st.insert(i);
        }
        while(true){
            if(st.count(original)){
                original*=2;
            }
            else{
                return original;
            }
        }
        return original;
        
    }
};